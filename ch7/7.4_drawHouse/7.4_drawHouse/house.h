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

#define HouseHeight         2.0
#define HouseWidth          3.0
#define AtticHeight         0.7
#define DoorWidth           0.4
#define DoorHeight          0.7
#define DoorKnobRadius      0.03
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


void drawWindows(GLdouble x, GLdouble y);
void drawDoor(GLdouble x, GLdouble y);
#endif /* defined(____4_drawHouse__house__) */
