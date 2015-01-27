/*
 * File: graphics.c
 * Version: 3.1
 * Last modified on Fri Feb 24 19:42:15 1995 by eroberts
 * -----------------------------------------------------
 * This file implements the graphics.h and extgraph.h interfaces
 * for the Macintosh using THINK's Lightspeed C.
 */

/*
 * General implementation notes
 * ----------------------------
 * This implementation is relatively complex for two reasons.
 * The first source of complexity is that windows on the
 * Macintosh are dynamically repositioned, obscured, and
 * reexposed.  When these events occur, the drawing in the
 * window needs to be repainted.  Thus, it is not sufficient
 * to have the drawing package simply issue the appropriate
 * QuickDraw procedures directly to the screen.  This
 * implementation solves the problem by rendering the image
 * to an offscreen bitmap and then repainting the image from
 * that copy whenever update events occur.
 *
 * The second problem, which is indeed more severe, is that
 * that is much more easily understood by experts than by
 * novices.  In a traditional Macintosh application, the
 * main program is coded as an "event loop," which
 * continually polls the event manager to see if any activity
 * is necessary.  This strategy runs counter to the more
 * conventional view of a main program as the highest level
 * in the problem decomposition.  In the context of teaching
 * programming, we want the main program and its subprograms
 * to draw the figures -- a strategy which is not easy to
 * reconcile with the standard Macintosh approach.  This
 * implementation solves this problem by patching in a call
 * to an update procedure as part of the event loop embedded
 * in the console input mechanism.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <console.h>
#include <math.h>
#include <time.h>
#include <Traps.h>

#include "genlib.h"
#include "gcalloc.h"
#include "strlib.h"
#include "extgraph.h"

/*
 * Parameters
 * ----------
 * DesiredWidth     -- Desired width of the graphics window
 * DesiredHeight    -- Desired height of the graphics window
 * ConsoleLines     -- Console lines
 * ConsoleHeight    -- Estimate of console height (inches)
 * BottomMargin     -- Minimum bottom margin (inches)
 * RightMargin      -- Minimum right margin (inches)
 * WindowSeparation -- Minimum window separation (inches)
 * TitleBarPixels   -- Pixel height of title bar
 * DefaultFont      -- Font used to implement "Default" font
 * DefaultSize      -- Initial point size for text
 * MaxColors        -- Maximum number of color names allowed
 * MinColors        -- Minimum number of colors the device must support
 * CheckForColor    -- TRUE if abstraction should check for color memory
 */

#define DesiredWidth       7.0
#define DesiredHeight      4.0
#define ConsoleLines       8
#define ConsoleHeight      1.1
#define BottomMargin       0.05
#define RightMargin        0.05
#define WindowSeparation   0.10
#define TitleBarPixels    20

#define DefaultFont "Geneva"
#define DefaultSize 10

#define MaxColors       256
#define MinColors        16
#define CheckForColor FALSE

/*
 * Other constants
 * ---------------
 * LargeInt -- Used to signify out of range values
 * Epsilon  -- Small arithmetic offset to reduce aliasing/banding
 * Pi       -- Mathematical constant pi
 */

#define LargeInt 16000
#define Epsilon  0.00000000001
#define Pi       3.1415926535

/*
 * Type: graphicsStateT
 * --------------------
 * This structure holds the variables that make up the graphics state.
 */

typedef struct graphicsStateT {
    double cx, cy;
    string font;
    int size;
    int style;
    bool erase;
    int color;
    struct graphicsStateT *link;
} *graphicsStateT;

/*
 * Type: regionStateT
 * ------------------
 * The region assembly process has the character of a finite state
 * machine with the following four states:
 *
 *   NoRegion       Region has not yet been started
 *   RegionStarting Region is started but no line segments yet
 *   RegionActive   First line segment appears
 *   PenHasMoved    Pen has moved during definition
 *
 * The current state determines whether other operations are legal
 * at that point.
 */

typedef enum {
    NoRegion, RegionStarting, RegionActive, PenHasMoved
} regionStateT;

/*
 * Type: colorEntryT
 * -----------------
 * This type is used for the entries in the color table.
 */

typedef struct {
    string name;
    double red, green, blue;
} colorEntryT;

/*
 * Global variables
 * ----------------
 * initialized   -- TRUE if initialization has been done
 * windowTitle   -- Current window title (initialized statically)
 * consoleFile   -- FILE * for console (saved to allow redirection)
 * gWindow       -- Window pointer for graphics window
 * osWindow      -- Offscreen window pointer for rendering
 * xResolution   -- Horizontal resolution of screen (dots per inch)
 * yResolution   -- Vertical resolution of screen (dots per inch)
 * windowWidth   -- Width of graphics window
 * windowHeight  -- Height of graphics window
 * regionState   -- Current state of the region
 * regionDensity -- Fill density to apply to region
 * mouseState    -- State of mouse as tracked by event handler
 * colorTable    -- Table of defined colors
 * nColors       -- Number of defined colors
 * colorOK       -- TRUE if color port successfully initialized
 * checkMemory   -- TRUE if application should check color memory
 * stateStack    -- Stack of graphicStateT blocks
 * cx, cy        -- Current coordinates     | These
 * eraseMode     -- Setting of erase flag   | variables
 * textFont      -- Current font            | consititute
 * textStyle     -- Current style           | the current
 * pointSize     -- Current point size      | graphics
 * penColor      -- Color of pen            | state
 */

static bool initialized = FALSE;
static string windowTitle = "Graphics Window";
static FILE consoleFile;

static WindowPeek gWindow, osWindow;
static short xResolution, yResolution;
static double windowWidth = DesiredWidth;
static double windowHeight = DesiredHeight;

static regionStateT regionState;
static double regionDensity;

static bool mouseState;

static colorEntryT colorTable[MaxColors];
static int nColors;
static bool colorOK;
static bool checkMemory = CheckForColor;

static graphicsStateT stateStack;

static double cx, cy;
static bool eraseMode;
static string textFont;
static int textStyle;
static int pointSize;
static int penColor;

/*
 * Static table: fillList
 * ----------------------
 * This table contains the bitmap patterns for the various density
 * values.  Adding more patterns to this list increases the
 * precision with which the client can control fill patterns.
 */

static Pattern fillList[] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x88, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88, 0x22 },
    { 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA },
    { 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
};

#define NFills (sizeof fillList / sizeof fillList[0])

/* Private function prototypes */

static void InitCheck(void);
static void InitGraphicsState(void);
static void EraseWindow(void);
static void CreateGraphicsWindow(void);
static bool CreateColorWindow(Rect *bounds);
static bool CreateBWWindow(Rect *bounds);
static void PrepareToDraw(void);
static void PrepareToDrawText(void);
static void DisplayLine(double x, double y, double dx, double dy);
static void DisplayArc(double x, double y, double rx, double ry,
                       double start, double sweep);
static void RenderArc(double x, double y, double rx, double ry,
                      double start, double sweep);
static void DisplayText(double x, double y, string text);
static void SetArcBB(Rect *rp, double xc, double yc,
                      double rx, double ry, double start, double sweep);
static void SetTextBB(Rect *rp, double x, double y, string text);
static void UpdateRect(Rect *rp);
static StringPtr PascalString(string cstr);
static int GetFontNumber(string fontName);
static void InitColors(void);
static bool ShouldBeWhite(void);
static void CheckColorMemory(void);
static int FindColorName(string name);
static void PatchEventHandler(void);
static long FindSystemTrap(short trap);
static void MyEventHandler(EventRecord *ep);
static void DoUpdateDisplay(void);
static bool StringMatch(string s1, string s2);
static int RectWidth(Rect *rp);
static int RectHeight(Rect *rp);
static void SetRectFromSize(Rect *rp, int x, int y, int width, int height);
static double Radians(double degrees);
static double Degrees(double radians);
static double InchesX(int x);
static double InchesY(int y);
static int PixelsX(double x);
static int PixelsY(double y);
static int ScaleX(double x);
static int ScaleY(double y);
static int Round(double x);
static int Min(int x, int y);
static int Max(int x, int y);
static double MinF(double x, double y);
static double MaxF(double x, double y);

/* Exported entries */

/* Section 1 -- Basic functions from graphics.h */

void InitGraphics(void)
{
    if (initialized) {
        EraseWindow();
    } else {
        initialized = TRUE;
        ProtectVariable(stateStack);
        ProtectVariable(windowTitle);
        ProtectVariable(textFont);
        InitColors();
        CreateGraphicsWindow();
        PatchEventHandler();
    }
    InitGraphicsState();
}

void MovePen(double x, double y)
{
    InitCheck();
    if (regionState == RegionActive) regionState = PenHasMoved;
    cx = x;
    cy = y;
}

void DrawLine(double dx, double dy)
{
    InitCheck();
    switch (regionState) {
      case NoRegion:
        DisplayLine(cx, cy, dx, dy);
        break;
      case RegionStarting: case RegionActive:
        DisplayLine(cx, cy, dx, dy);
        regionState = RegionActive;
        break;
      case PenHasMoved:
        Error("Region segments must be contiguous");
    }
    cx += dx;
    cy += dy;
}

void DrawArc(double r, double start, double sweep)
{
    DrawEllipticalArc(r, r, start, sweep);
}

double GetWindowWidth(void)
{
    InitCheck();
    return (windowWidth);
}

double GetWindowHeight(void)
{
    InitCheck();
    return (windowHeight);
}

double GetCurrentX(void)
{
    InitCheck();
    return (cx);
}

double GetCurrentY(void)
{
    InitCheck();
    return (cy);
}

/* Section 2 -- Elliptical arcs */

void DrawEllipticalArc(double rx, double ry,
                       double start, double sweep)
{
    double x, y;

    InitCheck();
    x = cx + rx * cos(Radians(start + 180));
    y = cy + ry * sin(Radians(start + 180));
    switch (regionState) {
      case NoRegion:
        DisplayArc(x, y, rx, ry, start, sweep);
        break;
      case RegionStarting: case RegionActive:
        RenderArc(x, y, rx, ry, start, sweep);
        regionState = RegionActive;
        break;
      case PenHasMoved:
        Error("Region segments must be contiguous");
    }
    cx = x + rx * cos(Radians(start + sweep));
    cy = y + ry * sin(Radians(start + sweep));
}

/* Section 3 -- Graphical structures */

void StartFilledRegion(double density)
{
    GrafPtr saveWindow;

    InitCheck();
    if (regionState != NoRegion) {
        Error("Region is already in progress");
    }
    if (density < 0 || density > 1) {
        Error("Density for regions must be between 0 and 1");
    }
    regionState = RegionStarting;
    regionDensity = density;
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    OpenRgn();
    SetPort(saveWindow);
}

void EndFilledRegion(void)
{
    RgnHandle region;
    GrafPtr saveWindow;
    int px;

    InitCheck();
    switch (regionState) {
      case NoRegion:
        Error("EndFilledRegion without StartFilledRegion");
      case RegionStarting:
        regionState = NoRegion;
        return;
      case RegionActive: case PenHasMoved:
        regionState = NoRegion;
        break;
    }
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDraw();
    region = NewRgn();
    if (region == NULL) Error("EndFilledRegion: Can't create region");
    CloseRgn(region);
    UpdateRect(&(*region)->rgnBBox);
    px = regionDensity * (NFills - 1) + 0.5 - Epsilon;
    if (eraseMode || ShouldBeWhite()) px = 0;
    FillRgn(region, ((Pattern *) fillList) + px);
    SetPort(saveWindow);
    DisposeRgn(region);
}

/* Section 4 -- String functions */

void DrawTextString(string text)
{
    InitCheck();
    if (regionState != NoRegion) {
        Error("Text strings are illegal inside a region");
    }
    DisplayText(cx, cy, text);
    cx += TextStringWidth(text);
}

double TextStringWidth(string text)
{
    Rect rect;
    GrafPtr saveWindow;

    InitCheck();
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDrawText();
    SetTextBB(&rect, cx, cy, text);
    SetPort(saveWindow);
    return (InchesX(RectWidth(&rect)));
}

void SetFont(string font)
{
    InitCheck();
    if (GetFontNumber(font) != 0) {
        textFont = CopyString(font);
    }
}

string GetFont(void)
{
    InitCheck();
    return (CopyString(textFont));
}

void SetPointSize(int size)
{
    InitCheck();
    pointSize = size;
}

int GetPointSize(void)
{
    InitCheck();
    return (pointSize);
}

void SetStyle(int style)
{
    InitCheck();
    textStyle = style;
}

int GetStyle(void)
{
    InitCheck();
    return (textStyle);
}

double GetFontAscent(void)
{
    FontInfo fInfo;
    GrafPtr saveWindow;

    InitCheck();
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDrawText();
    GetFontInfo(&fInfo);
    SetPort(saveWindow);
    return (InchesY(fInfo.ascent));
}

double GetFontDescent(void)
{
    FontInfo fInfo;
    GrafPtr saveWindow;

    InitCheck();
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDrawText();
    GetFontInfo(&fInfo);
    SetPort(saveWindow);
    return (InchesY(fInfo.descent));
}

double GetFontHeight(void)
{
    FontInfo fInfo;
    GrafPtr saveWindow;

    InitCheck();
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDrawText();
    GetFontInfo(&fInfo);
    SetPort(saveWindow);
    return (InchesY(fInfo.ascent + fInfo.descent + fInfo.leading));
}

/* Section 5 -- Mouse support */

double GetMouseX(void)
{
    GrafPtr saveWindow;
    Point pt;

    InitCheck();
    GetPort(&saveWindow);
    SetPort((WindowPtr) gWindow);
    GetMouse(&pt);
    SetPort(saveWindow);
    return (InchesX(pt.h));
}

double GetMouseY(void)
{
    GrafPtr saveWindow;
    Point pt;

    InitCheck();
    GetPort(&saveWindow);
    SetPort((WindowPtr) gWindow);
    GetMouse(&pt);
    SetPort(saveWindow);
    return (windowHeight - InchesY(pt.v));
}

bool MouseButtonIsDown(void)
{
    InitCheck();
    return (Button());
}

void WaitForMouseDown(void)
{
    InitCheck();
    mouseState = Button();
    while (!mouseState) {
        UpdateDisplay();
    }
}

void WaitForMouseUp(void)
{
    InitCheck();
    mouseState = Button();
    while (mouseState) {
        UpdateDisplay();
    }
}

/* Section 6 -- Color support */

bool HasColor(void)
{
    InitCheck();
    return (colorOK);
}

void SetPenColor(string color)
{
    int cindex;

    InitCheck();
    if (checkMemory && !StringMatch(color, "Black")
                    && !StringMatch(color, "White")) {
        CheckColorMemory();
        checkMemory = FALSE;
    }
    cindex = FindColorName(color);
    if (cindex == -1) Error("Undefined color: %s", color);
    penColor = cindex;
}

string GetPenColor(void)
{
    InitCheck();
    return (colorTable[penColor].name);
}

void DefineColor(string name,
                 double red, double green, double blue)
{
    int cindex;

    InitCheck();
    if (red < 0 || red > 1 || green < 0 || green > 1 || blue < 0 || blue > 1) {
        Error("DefineColor: All color intensities must be between 0 and 1");
    }
    cindex = FindColorName(name);
    if (cindex == -1) {
        if (nColors == MaxColors) Error("DefineColor: Too many colors");
        cindex = nColors++;
    }
    colorTable[cindex].name = CopyString(name);
    colorTable[cindex].red = red;
    colorTable[cindex].green = green;
    colorTable[cindex].blue = blue;
}

/* Section 7 -- Miscellaneous functions */

void SetEraseMode(bool mode)
{
    InitCheck();
    eraseMode = mode;
}

bool GetEraseMode(void)
{
    InitCheck();
    return (eraseMode);
}

void SetWindowTitle(string title)
{
    windowTitle = CopyString(title);
    if (initialized) {
        SetWTitle((WindowPtr) gWindow, PascalString(title));
    }
}

string GetWindowTitle(void)
{
    return (CopyString(windowTitle));
}

/*
 * Implementation notes: UpdateDisplay
 * -----------------------------------
 * This implementation of this function is entirely dependent
 * on the implementation of the console.h interface.  Calling
 * the I/O event procedure for the console when cnt is 0 and raw
 * mode is on has the effect of responding to one pending event
 * without performing any I/O operations.  Repeating this call
 * as long as there are events therefore clears the event queue,
 * which will end up responding to any pending update events.
 */

void UpdateDisplay(void)
{
    EventRecord event;
    int cnt;

    InitCheck();
    cnt = consoleFile.cnt;
    consoleFile.cnt = 0;
    csetmode(C_RAW, &consoleFile);
    while (EventAvail(everyEvent, &event) || event.what != nullEvent) {
        (void) consoleFile.proc(stdin, 0);
    }
    consoleFile.cnt = cnt;
    csetmode(C_ECHO, &consoleFile);
}

void Pause(double seconds)
{
    long dummy;

    UpdateDisplay();
    Delay(seconds * CLOCKS_PER_SEC, &dummy);
}

void ExitGraphics(void)
{
    console_options.pause_atexit = FALSE;
    exit(0);
}

void SaveGraphicsState(void)
{
    graphicsStateT sb;

    InitCheck();
    sb = New(graphicsStateT);
    sb->cx = cx;
    sb->cy = cy;
    sb->font = textFont;
    sb->size = pointSize;
    sb->style = textStyle;
    sb->erase = eraseMode;
    sb->color = penColor;
    sb->link = stateStack;
    stateStack = sb;
}

void RestoreGraphicsState(void)
{
    graphicsStateT sb;

    InitCheck();
    if (stateStack == NULL) {
        Error("RestoreGraphicsState called before SaveGraphicsState");
    }
    sb = stateStack;
    cx = sb->cx;
    cy = sb->cy;
    textFont = sb->font;
    pointSize = sb->size;
    textStyle = sb->style;
    eraseMode = sb->erase;
    penColor = sb->color;
    stateStack = sb->link;
    FreeBlock(sb);
}

double GetFullScreenWidth(void)
{
    GrafPtr wPort;
    short xRes, yRes;

    GetWMgrPort(&wPort);
    ScreenRes(&xRes, &yRes);
    return ((double) RectWidth(&wPort->portRect) / xRes);
}

double GetFullScreenHeight(void)
{
    GrafPtr wPort;
    short xRes, yRes;

    GetWMgrPort(&wPort);
    ScreenRes(&xRes, &yRes);
    return ((double) RectHeight(&wPort->portRect) / yRes);
}

void SetWindowSize(double width, double height)
{
    if (initialized) return;
    windowWidth = width;
    windowHeight = height;
}

double GetXResolution(void)
{
    short xRes, yRes;

    if (initialized) {
        return (xResolution);
    } else {
        ScreenRes(&xRes, &yRes);
        return (xRes);
    }
}

double GetYResolution(void)
{
    short xRes, yRes;

    if (initialized) {
        return (yResolution);
    } else {
        ScreenRes(&xRes, &yRes);
        return (yRes);
    }
}

/* Private functions */

/*
 * Function: InitCheck
 * Usage: InitCheck();
 * -------------------
 * This function merely ensures that the package has been
 * initialized before the client functions are called.
 */

static void InitCheck(void)
{
    if (!initialized) Error("InitGraphics has not been called");
}

/*
 * Function: InitGraphicsState
 * Usage: InitGraphicsState();
 * ---------------------------
 * This function initializes the graphics state elements to
 * their default values.
 */

static void InitGraphicsState(void)
{
    cx = cy = 0;
    eraseMode = FALSE;
    textFont = "Default";
    pointSize = DefaultSize;
    textStyle = Normal;
    stateStack = NULL;
    regionState = NoRegion;
    SetPenColor("Black");
}

/*
 * Function: EraseWindow
 * Usage: EraseWindow();
 * ---------------------
 * This function erases all of the offscreen memory bits,
 * thereby clearing the screen image.  Note that the portBits
 * array is typically larger than a Macintosh segment and
 * therefore cannot be cleared with array operations or memset.
 */

static void EraseWindow(void)
{
    GrafPtr saveWindow;
    Rect rect;
    int width, height;

    GetPort(&saveWindow);
    SetPort((WindowPtr) gWindow);
    width = RectWidth(&gWindow->port.portRect);
    height = RectHeight(&gWindow->port.portRect);
    SetRect(&rect, 0, 0, width, height);
    InvalRect(&rect);
    SetPort(saveWindow);
    CopyBits(&((GrafPtr) osWindow)->portBits,
             &((GrafPtr) osWindow)->portBits,
             &((GrafPtr) osWindow)->portRect,
             &((GrafPtr) osWindow)->portRect,
             srcBic, NULL);
}

/*
 * Function: CreateGraphicsWindow
 * Usage: CreateGraphicsWindow();
 * ------------------------------
 * This function creates the graphics window on the screen and
 * the offscreen memory to back it up.
 */

static void CreateGraphicsWindow(void)
{
    GrafPtr wPort;
    WindowPtr cWindow;
    double xScale, yScale, scaleFactor;
    double xSpace, ySpace;
    int gHeight, cHeight;
    int left, top;
    Rect bounds;
    long nBytes;
    void *base;

    GetWMgrPort(&wPort);
    ScreenRes(&xResolution, &yResolution);
    left = console_options.left;
    top = console_options.top;
    xSpace = InchesX(RectWidth(&wPort->portRect) - left) - RightMargin;
    ySpace = InchesY(RectHeight(&wPort->portRect) - top) - BottomMargin
             - ConsoleHeight - 2 * InchesY(TitleBarPixels);
    xScale = yScale = 1.0;
    if (windowWidth > xSpace) {
        xScale = xSpace / windowWidth;
    }
    if (windowHeight > ySpace) {
        yScale = ySpace / windowHeight;
    }
    scaleFactor = MinF(xScale, yScale);
    gHeight = PixelsY(windowHeight * scaleFactor) + TitleBarPixels;
    console_options.top += gHeight + PixelsY(WindowSeparation);
    console_options.nrows = ConsoleLines;
    console_options.title = "\pConsole Window";
    printf("\n");
    fflush(stdout);
    consoleFile = *stdout;
    cHeight = RectHeight(&((GrafPtr) stdout->window)->portRect);
    cWindow = (WindowPtr) stdout->window;
    SizeWindow(cWindow, PixelsX(DesiredWidth), cHeight, 0);
    MoveWindow(cWindow, left, console_options.top, TRUE);
    xResolution *= scaleFactor;
    yResolution *= scaleFactor;
    SetRectFromSize(&bounds, left, top,
                    PixelsX(windowWidth), PixelsY(windowHeight));
    colorOK = (TestDeviceAttribute(GetMainDevice(), gdDevType) != 0);
    if (colorOK) colorOK = CreateColorWindow(&bounds);
    if (!colorOK) {
        if (!CreateBWWindow(&bounds)) {
            Error("InitGraphics: Can't create window");
        }
    }
    EraseWindow();
    ShowWindow((WindowPtr) gWindow);
}

/*
 * Function: CreateColorWindow
 * Usage: success = CreateColorWindow(&bounds);
 * --------------------------------------------
 * This function tries to create a color graphics window with
 * the specified bounds.  If it succeeds, the resulting window
 * is stored in the global variable gWindow and the corresponding
 * offscreen bitmap is stored in the pseudowindow osWindow.  The
 * function returns TRUE on success and FALSE on failure.
 */

static bool CreateColorWindow(Rect *bounds)
{
    CGrafPtr gPort, osPort;
    Rect visRect;
    int nColors;
    long nBytes;
    void *base;

    gWindow = (WindowPeek) NewCWindow(NULL, bounds,
                                      PascalString(windowTitle),
                                      FALSE, 0, (WindowPtr) -1, FALSE, 0);
    if (gWindow == NULL) return (FALSE);
    gPort = (CGrafPtr) gWindow;
    nColors = (*(*gPort->portPixMap)->pmTable)->ctSize + 1;
    if (nColors < MinColors) {
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    osWindow = (WindowPeek) malloc(sizeof(CGrafPort));
    if (osWindow == NULL) {
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    osPort = (CGrafPtr) osWindow;
    *osPort = *gPort;
    if ((osPort->visRgn = NewRgn()) == NULL) {
        free(osWindow);
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    visRect = *bounds;
    OffsetRect(&visRect, -bounds->left, -bounds->top);
    RectRgn(osPort->visRgn, &visRect);
    if ((osPort->portPixMap = NewPixMap()) == NULL) {
        free(osWindow);
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    CopyPixMap(gPort->portPixMap, osPort->portPixMap);
    nBytes = (long) RectHeight(bounds)
               * ((*osPort->portPixMap)->rowBytes & 0x3FFF);
    base = calloc(nBytes, 1);
    if (base == NULL) {
        DisposePixMap(osPort->portPixMap);
        free(osWindow);
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    (*osPort->portPixMap)->baseAddr = base;
    return (TRUE);
}

/*
 * Function: CreateBWWindow
 * Usage: success = CreateBWWindow(&bounds);
 * -----------------------------------------
 * This function is identical to CreateColorWindow except that
 * it creates a black-and-white window.  This function is used
 * if the device does not support color or if there is not
 * enough memory to create a color bitmap.
 */

static bool CreateBWWindow(Rect *bounds)
{
    GrafPtr gPort, osPort;
    Rect visRect;
    void *base;

    gWindow = (WindowPeek) NewWindow(NULL, bounds,
                                     PascalString(windowTitle),
                                     FALSE, 0, (WindowPtr) -1, FALSE, 0);
    if (gWindow == NULL) return (FALSE);
    gPort = (GrafPtr) gWindow;
    osWindow = (WindowPeek) malloc(sizeof(GrafPort));
    if (osWindow == NULL) {
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    osPort = (GrafPtr) osWindow;
    *osPort = *gPort;
    if ((osPort->visRgn = NewRgn()) == NULL) {
        free(osWindow);
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    visRect = *bounds;
    OffsetRect(&visRect, -bounds->left, -bounds->top);
    RectRgn(osPort->visRgn, &visRect);
    base = calloc((long) RectHeight(bounds) * osPort->portBits.rowBytes, 1);
    if (base == NULL) {
        free(osWindow);
        DisposeWindow((WindowPtr) gWindow);
        return (FALSE);
    }
    osPort->portBits.baseAddr = base;
    return (TRUE);
}

/*
 * Function: PrepareToDraw
 * Usage: PrepareToDraw();
 * -----------------------
 * This function must be called before any rendering operation
 * to ensure the pen modes and colors are correctly set.  The
 * port must already be selected when this function is called.
 */

static void PrepareToDraw(void)
{
    bool erase;
    RGBColor color;

    erase = eraseMode;
    if (colorOK) {
        color.red = colorTable[penColor].red * 0xFFFFL;
        color.green = colorTable[penColor].green * 0xFFFFL;
        color.blue = colorTable[penColor].blue * 0xFFFFL;
        RGBForeColor(&color);
    } else {
        if (ShouldBeWhite()) erase = TRUE;
    }
    PenMode((erase) ? patBic : patCopy);
    TextMode((erase) ? srcBic : srcOr);
}

/*
 * Function: PrepareToDrawText
 * Usage: PrepareToDrawText();
 * ---------------------------
 * This function must be called before any text rendering operation.
 * The port must already be selected when this function is called.
 */

static void PrepareToDrawText(void)
{
    int fnum;

    PrepareToDraw();
    fnum = GetFontNumber(textFont);
    if (fnum == 0) Error("Internal error: illegal font");
    TextFont(fnum);
    TextSize(pointSize);
    TextFace(((textStyle & Bold) ? bold : 0)
             | ((textStyle & Italic) ? italic : 0));
}

/*
 * Function: DisplayLine
 * Usage: DisplayLine(x, y, dx, dy);
 * ---------------------------------
 * This function displays a line segment from the point (x, y)
 * to the point (x + dx, y + dy).  Like all of the other graphical
 * operations, the line is rendered into offscreen memory.  The
 * actual screen is updated only in response to the update event.
 */

static void DisplayLine(double x, double y, double dx, double dy)
{
    GrafPtr saveWindow;
    Rect rect;
    int ix0, iy0, ix1, iy1;

    ix0 = ScaleX(x);
    iy0 = ScaleY(y);
    ix1 = ScaleX(x + dx);
    iy1 = ScaleY(y + dy);
    SetRect(&rect, Min(ix0,ix1), Min(iy0,iy1), Max(ix0,ix1), Max(iy0,iy1));
    UpdateRect(&rect);
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDraw();
    MoveTo(ix0, iy0);
    LineTo(ix1, iy1);
    SetPort(saveWindow);
}

/*
 * Function: DisplayArc
 * Usage: DisplayArc(x, y, rx, ry, start, sweep);
 * ---------------------------------------------
 * This function displays an elliptical arc segment centered at
 * the point (x, y).  (Note that the argument signature is different
 * from that of the client function DrawEllipticalArc.)
 */

static void DisplayArc(double x, double y, double rx, double ry,
                       double start, double sweep)
{
    GrafPtr saveWindow;
    Rect rect;
    int ix0, iy0, ix1, iy1, istart, isweep;

    istart = Round(start);
    isweep = Round(sweep);
    ix0 = ScaleX(x - rx);
    iy0 = ScaleY(y + ry);
    ix1 = ix0 + PixelsX(2 * rx);
    iy1 = iy0 + PixelsY(2 * ry);
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDraw();
    SetArcBB(&rect, x, y, rx, ry, start, sweep);
    UpdateRect(&rect);
    SetRect(&rect, ix0, iy0, ix1+1, iy1+1);
    FrameArc(&rect, 90 - istart, -isweep);
    SetPort(saveWindow);
}

/*
 * Function: RenderArc
 * Usage: RenderArc(x, y, rx, ry, start, sweep);
 * ---------------------------------------------
 * This function is identical to the DisplayArc function except
 * that the arc is rendered using line segments.  This complication
 * is necessary on the Macintosh for filled shapes because arcs are
 * not counted as region boundaries.  As an optimization, a
 * complete circle or oval is drawn using the DrawOval tool, which
 * does add a region boundary.  The arc unit is chosen to represent
 * a pixel width at the specified arc radius.
 */

static void RenderArc(double x, double y, double rx, double ry,
                      double start, double sweep)
{
    GrafPtr saveWindow;
    double t, mint, maxt, dt;
    int ix0, iy0, ix1, iy1;
    Rect rect;

    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDraw();
    if (sweep < 0) {
        start += sweep;
        sweep = -sweep;
    }
    if (sweep > 360 - Epsilon) {
        ix0 = ScaleX(x - rx);
        iy0 = ScaleY(y + ry);
        ix1 = ix0 + PixelsX(2 * rx);
        iy1 = iy0 + PixelsY(2 * ry);
        SetRect(&rect, ix0, iy0, ix1+1, iy1+1);
        FrameOval(&rect);
    } else {
        dt = atan2(InchesY(1), MaxF(fabs(rx), fabs(ry)));
        mint = Radians(start);
        maxt = Radians(start + sweep);
        for (t = mint; t < maxt; t += dt) {
            if (t > maxt - dt / 2) t = maxt;
            ix0 = ScaleX(x + rx * cos(t));
            iy0 = ScaleY(y + ry * sin(t));
            if (t == mint) {
                MoveTo(ix0, iy0);
            } else {
                LineTo(ix0, iy0);
            }
        }
    }
    SetArcBB(&rect, x, y, rx, ry, start, sweep);
    UpdateRect(&rect);
    SetPort(saveWindow);
}

/*
 * Function: DisplayText
 * Usage: DisplayText(x, y, text);
 * -------------------------------
 * Displays the specified text starting at the point (x, y)
 * using the current font, size, and style parameters.
 */

static void DisplayText(double x, double y, string text)
{
    GrafPtr saveWindow;
    Rect rect;
    int ix, iy;

    ix = ScaleX(x);
    iy = ScaleY(y);
    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    PrepareToDrawText();
    SetTextBB(&rect, x, y, text);
    UpdateRect(&rect);
    MoveTo(ix, iy);
    DrawText(text, 0, strlen(text));
    SetPort(saveWindow);
}

/*
 * Function: SetArcBB
 * Usage: SetArcBB(&rect, xc, yc, rx, ry, start, sweep);
 * -----------------------------------------------------
 * This function sets the rectangle dimensions to the bounding
 * box of the arc segment specified by the remaining arguments.
 */

static void SetArcBB(Rect *rp, double xc, double yc,
                      double rx, double ry, double start, double sweep)
{
    int xmax, xmin, ymax, ymin;
    int xl, xr, yt, yb;
    int ix0, iy0, ix1, iy1;

    xmin = ScaleX(xc - rx);
    ymin = ScaleY(yc + ry);
    xmax = xmin + PixelsX(2 * rx);
    ymax = ymin + PixelsX(2 * ry);
    if (sweep < 0) {
        start += sweep;
        sweep = -sweep;
    }
    if (sweep >= 360) {
        SetRect(rp, xmin, ymin, xmax, ymax);
        return;
    }
    if (start < 0) {
        start = 360 - fmod(-start, 360);
    } else {
        start = fmod(start, 360);
    }
    ix0 = ScaleX(xc + rx * cos(Radians(start)));
    iy0 = ScaleY(yc + ry * sin(Radians(start)));
    ix1 = ScaleX(xc + rx * cos(Radians(start + sweep)));
    iy1 = ScaleY(yc + ry * sin(Radians(start + sweep)));
    if (start + sweep > 360) {
        xr = xmax;
    } else {
        xr = Max(ix0, ix1);
    }
    start = fmod(start + 270, 360);
    if (start + sweep > 360) {
        yt = ymin;
    } else {
        yt = Min(iy0, iy1);
    }
    start = fmod(start + 270, 360);
    if (start + sweep > 360) {
        xl = xmin;
    } else {
        xl = Min(ix0, ix1);
    }
    start = fmod(start + 270, 360);
    if (start + sweep > 360) {
        yb = ymax;
    } else {
        yb = Max(iy0, iy1);
    }
    SetRect(rp, xl, yt, xr + 1, yb + 1);
}

/*
 * Function: SetTextBB
 * Usage: SetTextBB(&rect, x, y, text);
 * ------------------------------------
 * This function sets the rectangle dimensions to the bounding
 * box of the text string.
 */

static void SetTextBB(Rect *rp, double x, double y, string text)
{
    GrafPtr saveWindow;
    FontInfo fInfo;
    int ix, iy, width;

    GetPort(&saveWindow);
    SetPort((WindowPtr) osWindow);
    ix = ScaleX(x);
    iy = ScaleY(y);
    GetFontInfo(&fInfo);
    width = TextWidth(text, 0, strlen(text));
    SetRect(rp, ix, iy - fInfo.ascent, ix + width, iy + fInfo.descent);
    SetPort(saveWindow);
}

/*
 * Function: UpdateRect
 * Usage: UpdateRect(&rect);
 * -------------------------
 * This function sets the invalid area of the screen to include
 * the update rectangle.
 */

static void UpdateRect(Rect *rp)
{
    GrafPtr saveWindow;
    Rect rect;

    GetPort(&saveWindow);
    SetPort((WindowPtr) gWindow);
    rect = *rp;
    InsetRect(&rect, -1, -1);
    InvalRect(&rect);
    SetPort(saveWindow);
}

/*
 * Function: PascalString
 * Usage: pstr = PascalString(cstr);
 * --------------------------------
 * This function generates a dynamically allocated Pascal string
 * from the corresponding C string.
 */

static StringPtr PascalString(string cstr)
{
    int len;
    StringPtr pstr;

    len = strlen(cstr);
    pstr = GetBlock(len + 2);
    strcpy((char *) &pstr[1], cstr);
    pstr[0] = len;
    return (pstr);
}

/*
 * Function: GetFontNumber
 * Usage: fontNumber = GetFontNumber(fontName);
 * --------------------------------------------
 * This function returns the font number corresponding to a
 * Macintosh font name.
 */

static int GetFontNumber(string fontName)
{
    StringPtr pstr;
    short fnum;

    if (StringEqual(fontName, "Default")) fontName = DefaultFont;
    GetFNum(pstr = PascalString(fontName), &fnum);
    FreeBlock(pstr);
    return (fnum);
}

/*
 * Function: InitColors
 * Usage: InitColors();
 * --------------------
 * This function defines the built-in colors.
 */

static void InitColors(void)
{
    nColors = 0;
    DefineColor("Black", 0, 0, 0);
    DefineColor("Dark Gray", .35, .35, .35);
    DefineColor("Gray", .6, .6, .6);
    DefineColor("Light Gray", .75, .75, .75);
    DefineColor("White", 1, 1, 1);
    DefineColor("Red", 1, 0, 0);
    DefineColor("Yellow", 1, 1, 0);
    DefineColor("Green", 0, 1, 0);
    DefineColor("Cyan", 0, 1, 1);
    DefineColor("Blue", 0, 0, 1);
    DefineColor("Magenta", 1, 0, 1);
}

/*
 * Function: ShouldBeWhite
 * Usage: if (ShouldBeWhite()) . . .
 * ---------------------------------
 * This function returns TRUE if the current color is so
 * close to white that it should be represented as such
 * in a black-and-white world.  Note that the function
 * is always FALSE in the color domain.
 */

static bool ShouldBeWhite(void)
{
    if (colorOK) return (FALSE);
    if (colorTable[penColor].red < .9) return (FALSE);
    if (colorTable[penColor].blue < .9) return (FALSE);
    if (colorTable[penColor].green < .9) return (FALSE);
    return (TRUE);
}

/*
 * Function: CheckColorMemory
 * Usage: CheckColorMemory();
 * --------------------------
 * By default, the THINK C project is too small to support color.
 * This function checks to see if the problem is the memory size
 * and gives a message to that effect.
 */

static void CheckColorMemory(void)
{
    if (colorOK) return;
    printf("There is not enough memory in this project to create\n");
    printf("a color window.  Try increasing the partition size to\n");
    printf("1000K by changing the setting in the Set Project Type\n");
    printf("dialog of the Project menu.  Also make sure that the\n");
    printf("Monitors control panel is set to at least 16 but no more\n");
    printf("than 256 colors.\n");
}

/*
 * Function: FindColorName
 * Usage: index = FindColorName(name);
 * -----------------------------------
 * This function returns the index of the named color in the
 * color table, or -1 if the color does not exist.
 */

static int FindColorName(string name)
{
    int i;

    for (i = 0; i < nColors; i++) {
        if (StringMatch(name, colorTable[i].name)) return (i);
    }
    return (-1);
}

/*
 * Event handler
 * -------------
 * The trickiest part of the graphics library code is the
 * following patch system, which adds a call to MyEventHandler
 * prior to the SystemEvent trap.  This makes it possible for
 * the same event loop that handles console events to update
 * the graphics window instead.
 */

static char patchArea[0x20];

/*
 *  00  PEA    $FFF0(A6)
 *  04  JSR    xxxx.L
 *  0A  CLR.L  -(A7)
 *  0C  PEA    $FFF0(A6)
 *  10  $A9B2
 *  12  JMP    yyyy.L
 */

/*
 * Function: PatchEventHandler
 * Usage: PatchEventHandler();
 * ---------------------------
 * This call inserts the patch into the event handling code to
 * call MyEventHandler.  The function first finds the address
 * of the SystemEvent trap and then replaces it with a jump
 * to the code fragment shown above, after xxxx is replaced
 * by the address of MyEventHandler and yyyy by the address
 * after the SystemEvent trap in the existing code.
 */

static void PatchEventHandler(void)
{
    long trapAddress;
    char *patch;

    trapAddress = FindSystemTrap(_SystemEvent);
    patch = patchArea;
    if ((int) patch & 1) patch++;
    memcpy(&patch[0x00], (void *) (trapAddress - 4), 4);
    *((short *) (&patch[0x04])) = 0x4EB9;
    *((long *) (&patch[0x06])) = (long) MyEventHandler;
    *((short *) (&patch[0x0A])) = 0x42A7;
    memcpy(&patch[0x0C], (void *) (trapAddress - 4), 6);
    *((short *) (&patch[0x12])) = 0x4EF9;
    *((long *) (&patch[0x14])) = trapAddress + 2;
    *((short *) (trapAddress - 4)) = 0x4EF9;
    *((long *) (trapAddress - 2)) = (long) patch;
}

/*
 * Function: FindSystemTrap
 * Usage: addr = FindSystemTrap(trap);
 * ----------------------------------
 * This function finds the first occurrence of the specified trap
 * in the code stream beginning at the input function.
 */

static long FindSystemTrap(short trap)
{
    long ptr, base;
    int i;

    base = (long) stdin->proc;
    if (*((short *) base) == 0x4EF9) {
        base = *((long *) (base + 2));
    }
    for (ptr = base; *((short *) ptr) != trap; ptr -= 2);
    return (ptr);
}

/*
 * Function: MyEventHandler
 * Usage: MyEventHandler();
 * ------------------------
 * This function catches update events for the console window.
 */

static void MyEventHandler(EventRecord *ep)
{
    int clickType;
    WindowPeek window;

    switch (ep->what) {
      case updateEvt:
        if ((WindowPeek) ep->message == gWindow) DoUpdateDisplay();
        break;
      case mouseDown:
          mouseState = TRUE;
        clickType = FindWindow(ep->where, (WindowPtr *) &window);
        if (window != gWindow) return;
        if (clickType == inDrag) {
            DragWindow((WindowPtr) window, ep->where,
                       &(*GetGrayRgn())->rgnBBox);
        }
        break;
      case mouseUp:
          mouseState = FALSE;
    }
}

/*
 * Function: DoUpdateDisplay
 * Usage: DoUpdateDisplay();
 * -------------------------
 * This function copies the bits from the offscreen memory to
 * the invalid area of the display.
 */

static void DoUpdateDisplay(void)
{
    GrafPtr saveWindow;
    Rect rect;
    int width, height;

    BeginUpdate((WindowPtr) gWindow);
    GetPort(&saveWindow);
    SetPort((WindowPtr) gWindow);
    CopyBits(&((GrafPtr) osWindow)->portBits,
             &((GrafPtr) gWindow)->portBits,
             &((GrafPtr) osWindow)->portRect,
             &((GrafPtr) gWindow)->portRect,
             srcCopy, NULL);
    SetPort(saveWindow);
    EndUpdate((WindowPtr) gWindow);
}

/*
 * Utility functions
 * -----------------
 * This section contains several extremely short utility functions
 * that improve the readability of the code.
 */

/*
 * Function: StringMatch
 * Usage: if (StringMatch(s1, s2)) . . .
 * -------------------------------------
 * This function returns TRUE if two strings are equal, ignoring
 * case distinctions.
 */

static bool StringMatch(string s1, string s2)
{
    register char *cp1, *cp2;

    cp1 = s1;
    cp2 = s2;
    while (tolower(*cp1) == tolower(*cp2)) {
        if (*cp1 == '\0') return (TRUE);
        cp1++;
        cp2++;
    }
    return (FALSE);
}

/*
 * Functions: RectWidth, RectHeight
 * Usage: w = RectWidth(&r);
 *        h = RectHeight(&r);
 * --------------------------------
 * These functions return the width and height of a rectangle.
 */

static int RectWidth(Rect *rp)
{
    return (rp->right - rp->left);
}

static int RectHeight(Rect *rp)
{
    return (rp->bottom - rp->top);
}

/*
 * Functions: SetRectFromSize
 * Usage: SetRectFromSize(&r, x, y, width, height);
 * ------------------------------------------------
 * This function is similar to SetRect except that it takes width
 * and height parameters rather than right and bottom.
 */

static void SetRectFromSize(Rect *rp, int x, int y, int width, int height)
{
    SetRect(rp, x, y, x + width, y + height);
}

/*
 * Functions: Radians, Degrees
 * Usage: radians = Radians(degrees);
 *        degrees = Degrees(radians);
 * ----------------------------------
 * These functions convert back and forth between degrees and radians.
 */

static double Radians(double degrees)
{
    return (degrees * Pi / 180);
}

static double Degrees(double radians)
{
    return (radians * 180 / Pi);
}

/*
 * Functions: InchesX, InchesY
 * Usage: inches = InchesX(pixels);
 *        inches = InchesY(pixels);
 * --------------------------------
 * These functions convert distances measured in pixels to inches.
 * Because the resolution may not be uniform in the horizontal and
 * vertical directions, the coordinates are treated separately.
 */

static double InchesX(int x)
{
    return ((double) x / xResolution);
}

static double InchesY(int y)
{
    return ((double) y / yResolution);
}

/*
 * Functions: PixelsX, PixelsY
 * Usage: pixels = PixelsX(inches);
 *        pixels = PixelsY(inches);
 * --------------------------------
 * These functions convert distances measured in inches to pixels.
 */

static int PixelsX(double x)
{
    return (Round(x * xResolution + Epsilon));
}

static int PixelsY(double y)
{
    return (Round(y * yResolution + Epsilon));
}

/*
 * Functions: ScaleX, ScaleY
 * Usage: pixels = ScaleX(inches);
 *        pixels = ScaleY(inches);
 * --------------------------------
 * These functions are like PixelsX and PixelsY but convert coordinates
 * rather than lengths.  The difference is that y-coordinate values must
 * be inverted top to bottom to support the cartesian coordinates of
 * the graphics.h model.
 */

static int ScaleX(double x)
{
    return (PixelsX(x));
}

static int ScaleY(double y)
{
    return (Round(PixelsY(windowHeight - y)));
}

static int Round(double x)
{
    return ((int) floor(x + 0.5));
}

/*
 * Functions: Min, Max
 * Usage: min = Min(x, y);
 *        max = Max(x, y);
 * -----------------------
 * These functions find the minimum and maximum of two integers.
 */

static int Min(int x, int y)
{
    return ((x < y) ? x : y);
}

static int Max(int x, int y)
{
    return ((x > y) ? x : y);
}

/*
 * Functions: MinF, MaxF
 * Usage: min = MinF(x, y);
 *        max = MaxF(x, y);
 * ------------------------
 * These functions find the minimum and maximum of two doubles.
 */

static double MinF(double x, double y)
{
    return ((x < y) ? x : y);
}

static double MaxF(double x, double y)
{
    return ((x > y) ? x : y);
}
