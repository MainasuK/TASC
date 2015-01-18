//
//  drawPumpkin.c
//  ex07_pumpkin
//
//  Created by Cirno MainasuK on 2015-1-18.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawPumpkin.h"

void drawPumpkin(GLdouble x, GLdouble y) {
    drawOutline(x, y);
    drawStem(x, y);
    drawNose(x, y);
    drawEyes(x, y);
    drawTooth(x, y);
}

void drawOutline(GLdouble x, GLdouble y) {
    drawCenteredCircle(x, y, HeadRadius);
}

void drawStem(GLdouble x, GLdouble y) {
    drawBox(x-StemWidth/2.0, y+HeadRadius, StemWidth, StemHeight);
    
}

void drawNose(GLdouble x, GLdouble y) {
    drawTriangle(x-NoseWidth*0.5, y-NoseHeight*0.5, NoseWidth, NoseHeight);
}

void drawEyes(GLdouble x, GLdouble y) {
    drawTriangle(x-HeadRadius*0.3-EyeWidth, y+HeadRadius*0.3, EyeWidth, -EyeHeight);
    drawTriangle(x+HeadRadius*0.3, y+HeadRadius*0.3, EyeWidth, -EyeHeight);
}

void drawTooth(GLdouble x, GLdouble y) {
    GLdouble toothX, toothY;
    toothX = x - 0.5*(ToothWidth * NTeethPerRow);
    toothY = y - 0.5 * HeadRadius;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < NTeethPerRow; j++) {
            drawBox(toothX+j*ToothWidth, toothY-i*ToothHeight, ToothWidth, ToothHeight);
        }
    }
    
}