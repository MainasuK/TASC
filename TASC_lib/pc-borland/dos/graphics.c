/*
 * File: graphics.c
 * Version: 2.0
 * Last modified on Tue Sep 20 09:35:42 1994 by eroberts
 * -----------------------------------------------------
 * This file implements the graphics.h interface for the
 * DOS/Borland C platform.  This version implements only the
 * standard graphics library; the extensions in extgraph.c are
 * implemented only for the Windows version.
 *
 * The DOS graphics library needs to know where the device
 * driver files are located.  In the standard install script,
 * that information is inserted in the Makefile so that no
 * additional installer interaction is required.
 */

#include <stdio.h>
#include <graphics.h>
#include <math.h>

#include "genlib.h"
#include "graphics.h"

#ifndef BCPATH
#error graphics.c requires that the Makefile define BCPATH
#endif

/*
 * Other constants
 * ---------------
 * PixelsPerInch -- Device resolution (not obtainable directly)
 * Epsilon       -- Small arithmetic offset to reduce aliasing/banding
 * Pi            -- Mathematical constant pi
 */

#define PixelsPerInch 72
#define Epsilon       0.00000000001
#define Pi            3.1415926535

/*
 * Global variables
 * ----------------
 * initialized  -- TRUE if initialization has been done
 * pixelWidth   -- Width of screen in pixels
 * pixelHeight  -- Height of screen in pixels
 */

static bool initialized = FALSE;
static int pixelWidth, pixelHeight;

/* Private function prototypes */

static double Radians(double degrees);
static int Round(double x);
static double InchesX(int x);
static double InchesY(int y);
static int PixelsX(double x);
static int PixelsY(double y);
static int ScaleX(double x);
static int ScaleY(double y);

/* Exported entries */

void InitGraphics(void)
{
    int gdriver, gmode, ec;

    if (!initialized) {
        gdriver = DETECT;
        initgraph(&gdriver, &gmode, BCPATH "\\BGI");
        ec = graphresult();
        if (ec != grOk) {
            printf("Error: %s\n", grapherrormsg(ec));
            (void) getchar();
            exit(1);
        }
        pixelWidth = getmaxx();
        pixelHeight = getmaxy();
        initialized = TRUE;
    }
    cleardevice();
}

void MovePen(double x, double y)
{
    moveto(ScaleX(x), ScaleY(y));
}

void DrawLine(double dx, double dy)
{
    linerel(PixelsX(dx), -PixelsY(dy));
}

void DrawArc(double r, double start, double sweep)
{
    int kstart, ksweep, kend;
    double cx, cy;

    kstart = Round(start);
    ksweep = Round(sweep);
    if (ksweep < 0) {
        kstart += ksweep;
        ksweep = -ksweep;
    }
    if (kstart < 0) {
        kstart = 360 - (-kstart % 360);
    } else {
        kstart %= 360;
    }
    if (ksweep >= 360) {
        kstart = 0;
        kend = 360;
    } else {
        kend = (kstart + ksweep) % 360;
    }
    cx = GetCurrentX() + r * cos(Radians(start + 180));
    cy = GetCurrentY() + r * sin(Radians(start + 180));
    arc(ScaleX(cx), ScaleY(cy), kstart, kend, PixelsX(r));
    MovePen(cx + r * cos(Radians(start + sweep)),
            cy + r * sin(Radians(start + sweep)));
}

double GetWindowWidth(void)
{
    return (InchesX(pixelWidth));
}

double GetWindowHeight(void)
{
    return (InchesY(pixelHeight));
}

double GetCurrentX(void)
{
    return (InchesX(getx()));
}

double GetCurrentY(void)
{
    return (InchesY(pixelHeight - gety()));
}

/*
 * Utility functions
 * -----------------
 * This section contains several extremely short utility functions
 * that improve the readability of the code.
 */

/*
 * Function: Radians
 * Usage: radians = Radians(degrees);
 * ----------------------------------
 * This functions convert an angle in degrees to radians.
 */

static double Radians(double degrees)
{
    return (degrees * Pi / 180);
}

/*
 * Function: Round
 * Usage: n = Round(x);
 * --------------------
 * This function rounds a double to the nearest integer.
 */

static int Round(double x)
{
    return ((int) floor(x + 0.5));
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
    return ((double) x / PixelsPerInch);
}

static double InchesY(int y)
{
    return ((double) y / PixelsPerInch);
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
    return (Round(x * PixelsPerInch + Epsilon));
}

static int PixelsY(double y)
{
    return (Round(y * PixelsPerInch + Epsilon));
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
    return (pixelHeight - PixelsY(y));
}
