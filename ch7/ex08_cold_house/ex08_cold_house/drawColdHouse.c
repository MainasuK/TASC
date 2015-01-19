//
//  drawColdHouse.c
//  ex08_cold_house
//
//  Created by Cirno MainasuK on 2015-1-18.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawColdHouse.h"

void drawColdHouse(GLdouble x, GLdouble y) {
    drawOutline(x, y);
    drawTower(x, y);
    drawDoor(x, y);
    drawWindow(x, y);
}

void drawOutline(GLdouble x, GLdouble y) {
    drawBox(x, y, HouseWidth, HouseHeight);
    drawTriangle(x, y+HouseHeight, HouseWidth, HouseArch);
}

void drawTower(GLdouble x, GLdouble y) {
    drawBox(x-TowerWidth, y, TowerWidth, TowerHeight);
    drawBox(x+HouseWidth, y, TowerWidth, TowerHeight);
    drawTriangle(x-TowerWidth, y+TowerHeight, TowerWidth, TowerArch);
    drawTriangle(x+HouseWidth, y+TowerHeight, TowerWidth, TowerArch);
}

void drawDoor(GLdouble x, GLdouble y) {
    drawBox(x+(HouseWidth-DoorWidth)/2.0, y, DoorWidth, DoorHeight);
    drawTriangle(x+(HouseWidth-DoorWidth)/2.0, y+DoorHeight, DoorWidth, DoorArch);
}

void drawWindow(GLdouble x, GLdouble y) {
    drawBox(x+HouseWidth/5.0, y+WindowLevel, WindowSize, WindowSize);
    drawBox(x+HouseWidth/5.0*3, y+WindowLevel, WindowSize, WindowSize);
}