//
//  drawPumpkin.h
//  ex07_pumpkin
//
//  Created by Cirno MainasuK on 2015-1-18.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex07_pumpkin__drawPumpkin__
#define __ex07_pumpkin__drawPumpkin__

#include <stdio.h>
#include "DrawTools.h"

#define HeadRadius      1.0
#define StemWidth       0.1
#define StemHeight      0.15
#define EyeWidth        0.3
#define EyeHeight       0.2
#define NoseWidth       0.2
#define NoseHeight      0.2
#define NTeethPerRow    7
#define ToothWidth      0.083333
#define ToothHeight 0.15

void drawPumpkin(GLdouble x, GLdouble y);

void drawOutline(GLdouble x, GLdouble y);
void drawStem(GLdouble x, GLdouble y);
void drawNose(GLdouble x, GLdouble y);
void drawEyes(GLdouble x, GLdouble y);
void drawTooth(GLdouble x, GLdouble y);
#endif /* defined(__ex07_pumpkin__drawPumpkin__) */
