//
//  house.c
//  7.4_drawHouse
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This is a library to build a house with OpenGL
//  The comments get from The Art and Science of C

#include "house.h"



void drawHouse(GLdouble x, GLdouble y) {
    drawOutline(x, y);
    drawDoor(x + (HouseWidth - DoorWidth) / 2, y);
    drawWindows(x, y);
    
}


void drawOutline(GLdouble x, GLdouble y) {
    drawBox(x, y, HouseWidth, HouseHeight);
    drawTriangle(x, y + HouseHeight, HouseWidth, AtticHeight);
}


void drawWindows(GLdouble x, GLdouble y) {
    double xleft, xright;
    
    xleft = x + HouseWidth * 0.25;
    xright = x + HouseWidth * 0.75;
    drawGrid(xleft - PaneWidth * 1.5, y + FirstFloorWindows,
             PaneWidth, PaneHeight, 3, 2);
    drawGrid(xright - PaneWidth * 1.5, y + FirstFloorWindows,
             PaneWidth, PaneHeight, 3, 2);
    drawGrid(xleft - PaneWidth, y + SecondFloorWindows,
             PaneWidth, PaneHeight, 2, 2);
    drawGrid(xright - PaneWidth, y + SecondFloorWindows,
             PaneWidth, PaneHeight, 2, 2);
}


/*
 * Function: DrawDoor
 * Usage: DrawDoor(x, y);
 * ----------------------
 * This function draws a door, with its doorknob.  As usual,
 * (x, y) specifies the lower left corner of the door.
 */

void drawDoor(double x, double y)
{
    drawBox(x, y, DoorWidth, DoorHeight);
    drawCenteredCircle(x + DoorWidth - DoorKnobInset,
                       y + DoorHeight / 2, DoorKnobRadius);
}


