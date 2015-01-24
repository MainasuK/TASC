//
//  city.c
//  ex11_city
//
//  Created by Cirno MainasuK on 2015-1-24.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "city.h"

#define THICKNESS 0.004

void drawCity(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid) {
    drawGrid(x, y, width/grid, height/grid, grid, grid);
    drawPath(x, y, width, height, grid);
}

void drawPath(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid) {
    int up, right, draw;
    up = 0;
    right = 0;
    randomize();
    do {
        draw = randomChance(0.5);
        if (draw) {
            if (up < 10) {
                (draw) ? drawPathUp(x, y, width, height, grid, up, right) : drawPathRight(x, y, width, height, grid, up, right);
                (draw) ? up++ : right++;
            }
        } else {
            if (right < 10) {
                (draw) ? drawPathUp(x, y, width, height, grid, up, right) : drawPathRight(x, y, width, height, grid, up, right);
                (draw) ? up++ : right++;
            }
        }
        printf("up:%d right:%d\n", up, right);
    } while (up + right < grid*2);
    
}

void drawPathUp(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid, int up, int right) {
    drawLine(x+right*(width/grid)-THICKNESS, y+up*(height/grid), x+right*(width/grid)-THICKNESS, y+(up+1)*(height/grid));
    drawLine(x+right*(width/grid)+THICKNESS, y+up*(height/grid), x+right*(width/grid)+THICKNESS, y+(up+1)*(height/grid));

    
    
}

void drawPathRight(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid, int up, int right) {
    drawLine(x+right*(width/grid), y+up*(height/grid)-THICKNESS, x+(right+1)*(width/grid), y+up*(height/grid)-THICKNESS);
    drawLine(x+right*(width/grid), y+up*(height/grid)+THICKNESS, x+(right+1)*(width/grid), y+up*(height/grid)+THICKNESS);
}
