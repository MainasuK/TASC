//
//  game.c
//  ex12_game
//
//  Created by Cirno MainasuK on 2015-1-24.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "game.h"
#include "random.h"
#include <math.h>

void game(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int initScore) {
    drawBox(x, y, width, height);
    drawWindows(x, y, width, height);
    drawPatter(x, y, width, height);
}

void drawWindows(GLdouble x, GLdouble y, GLdouble width, GLdouble height) {
    drawBox(x+width/13, y+height/4, width/13*3, height/2);
    drawBox(x+width/13*5, y+height/4, width/13*3, height/2);
    drawBox(x+width/13*9, y+height/4, width/13*3, height/2);
}

void drawPatter(GLdouble x, GLdouble y, GLdouble width, GLdouble height) {
    randomize();
    int def;
    GLdouble x1, y1, x2, y2, x3, y3;
    x1 = x + width  / 13 * 2.5;
    y1 = y + height / 4  * 2;
    x3 = x2 = x1;
    y3 = y2 = y1;
    def = randomInteger(1, 3);
    
    def = randomInteger(1, 3);
    printf("%d\n", def);
    switch (def) {
        case 1:
            drawCenteredCircle(x1, y1, width/4*0.3);
            break;
        case 2:
            drawCenteredTriangle(x1, y1, width/4*0.7, width/4*0.7*pow(3.0/4.0, 1.0/2.0));
            break;
        case 3:
            drawCenteredBox(x1, y1, width/4*0.4);
            
        default:
            break;
    }
    
    
    def = randomInteger(1, 3);
    printf("%d\n", def);
    switch (def) {
        case 1:
            drawCenteredCircle(x2, y2, width/4*0.3);
            break;
        case 2:
            drawCenteredTriangle(x2, y2, width/4*0.7, width/4*0.7*pow(3.0/4.0, 1.0/2.0));
            break;
        case 3:
            drawCenteredBox(x2, y2, width/4*0.4);
            
        default:
            break;
    }
    
    def = randomInteger(1, 3);
    printf("%d\n", def);
    switch (def) {
        case 1:
            drawCenteredCircle(x3, y3, width/4*0.3);
            break;
        case 2:
            drawCenteredTriangle(x3, y3, width/4*0.7, width/4*0.7*pow(3.0/4.0, 1.0/2.0));
            break;
        case 3:
            drawCenteredBox(x3, y3, width/4*0.4);
            
        default:
            break;
    }


}