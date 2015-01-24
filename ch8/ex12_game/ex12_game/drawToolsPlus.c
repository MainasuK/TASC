//
//  drawToolsPlus.c
//  ex12_game
//
//  Created by Cirno MainasuK on 2015-1-24.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawToolsPlus.h"

void drawCenteredTriangle(GLdouble x, GLdouble y, GLdouble base, GLdouble height) {
    drawTriangle(x-base/2, y-height/2, base, height);
}

void drawCenteredBox(GLdouble x, GLdouble y, GLdouble width) {
    drawBox(x-width/2, y-width/2, width, width);
}