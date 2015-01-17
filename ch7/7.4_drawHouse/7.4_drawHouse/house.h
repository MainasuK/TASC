//
//  house.h
//  7.4_drawHouse
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef ____4_drawHouse__house__
#define ____4_drawHouse__house__

#include <stdio.h>
#include "DrawTools.h"

#define HouseHeight         2.0
#define HouseWidth          3.0
#define AtticHeight         0.7

#define DoorWidth           0.4
#define DoorHeight          0.7
#define DoorKnobRadius      0.03
#define DoorKnobInset       0.07

#define PaneHeight          0.25
#define PaneWidth           0.2

#define FirstFloorWindows   0.3
#define SecondFloorWindows  1.25

/*
 * Function: drawHouse
 * Usage: drawHouse(x, y);
 * ------------------------------
 * This function draws a house with the lower left corner
 * at (x, y).  This level of the function merely divides up
 * the work.
 */

void drawHouse(GLdouble x, GLdouble y);


/* Function: drawOutline
 * Usage: drawOutline(x, y)
 * ------------------------------
 * This funciton draws the outline for the house, using (x, y)
 * as the origin.  The outline consists of a box with a
 * triangle on top.
 */


void drawOutline(GLdouble x, GLdouble y);


/*
 * Function: DrawWindows
 * Usage: DrawWindows(x, y);
 * -------------------------
 * This function draws all the windows for the house,
 * taking advantage of the fact that the windows are all
 * arranged in two-dimensional grids of equal-sized panes.
 * By calling the function DrawGrid, this implementation
 * can create all of the window structures using a single
 * tool.
 */

void drawWindows(GLdouble x, GLdouble y);


/*
 * Function: DrawDoor
 * Usage: DrawDoor(x, y);
 * ----------------------
 * This function draws a door, with its doorknob.  As usual,
 * (x, y) specifies the lower left corner of the door.
 */

void drawDoor(GLdouble x, GLdouble y);
#endif /* defined(____4_drawHouse__house__) */
