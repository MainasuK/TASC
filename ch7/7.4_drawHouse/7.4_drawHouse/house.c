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
    DrawTriangle(x, y + HouseHeight, HouseWidth, AtticHeight);
}






