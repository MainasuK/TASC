//
//  drawColdHouse.h
//  ex08_cold_house
//
//  Created by Cirno MainasuK on 2015-1-18.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex08_cold_house__drawColdHouse__
#define __ex08_cold_house__drawColdHouse__

#include <stdio.h>
#include "DrawTools.h"

#define HouseWidth          1.5
#define HouseHeight         2.0
#define HouseArch           1.0

#define TowerWidth          0.4
#define TowerHeight         2.3
#define TowerArch           0.6

#define DoorWidth           0.3
#define DoorHeight          0.5
#define DoorArch            0.25

#define WindowLevel         1.4
#define WindowSize          0.3

void drawColdHouse(GLdouble x, GLdouble y);
void drawOutline(GLdouble x, GLdouble y);
void drawTower(GLdouble x, GLdouble y);
void drawDoor(GLdouble x, GLdouble y);
void drawWindow(GLdouble x, GLdouble y);

#endif /* defined(__ex08_cold_house__drawColdHouse__) */
