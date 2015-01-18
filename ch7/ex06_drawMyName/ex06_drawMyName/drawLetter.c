//
//  drawLetter.c
//  ex06_drawMyName
//
//  Created by Cirno MainasuK on 2015-1-18.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawLetter.h"
#include <math.h>
#define root2 pow(2,0.5)
void drawWord(char *p, int n) {

}

void drawC(GLdouble x, GLdouble y, GLdouble scale) {
    drawArc(x+scale*0.5, y+scale*0.5, scale*0.4, 45, 315);
}

void drawK(GLdouble x, GLdouble y, GLdouble scale) {
    GLdouble baseline = 0.1*scale;
    GLdouble width = 0.45*scale;
    GLdouble height = 0.9*scale;
    GLdouble foot = 0.1*scale;
    drawLine(x, y+baseline, x, y+height);
    drawLine(x, y+(height+baseline)/2, x+width, y+height);
    drawLine(x+foot, foot+y+(height+baseline)/2, x+width+foot, y+baseline);
    
}

void drawM(GLdouble x, GLdouble y, GLdouble scale) {
    GLdouble baseline = 0.1*scale;
    GLdouble width = 0.25*scale;
    GLdouble height = 0.9*scale;
    drawLine(x, y+baseline, x+width, y+height);
    drawLine(x+width, y+height, x+width*2, y+baseline);
    drawLine(x+width*2, y+baseline, x+width*3, y+height);
    drawLine(x+width*3, y+height, x+width*4, y+baseline);
    
}