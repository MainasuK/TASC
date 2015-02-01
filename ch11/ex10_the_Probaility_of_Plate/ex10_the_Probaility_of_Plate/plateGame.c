//
//  plateGame.c
//  ex10_the_Probaility_of_Plate
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "plateGame.h"

static void initPlate(void);
static int getLane(void);
static void drawBall(int *k);

void plateGame(int n) {
    int lane[10] = {0};
    initPlate();
    randomize();
    
    for (int i = 0; i < n; i++) {
        lane[getLane()] += 1;
    }
    drawBall(lane);
}


void initPlate(void) {
    GLdouble leftMost;
    leftMost = 0-0.5*10*(radius+interval);
    for (int i = 0; i < 11; i++) {
        drawLine(leftMost, -1, leftMost, 0.5);
        leftMost += (interval+radius);
    }
}

int getLane(void) {
    double start = 5.5;
    for (int i = 0; i < 9; i++) {
        start = (randomChance(0.5) ? start-0.5 : start+0.5);
    }
    printf("%lf\n", start);
    return (int)(--start);
}

void drawBall(int *k) {
    GLdouble leftMost, downMost;
    leftMost = 0-0.5*10*(radius+interval)+(radius+interval)*0.5;
    downMost = -1 + radius;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < k[i]; j++) {
            drawCenteredCircle(leftMost+i*(interval+radius), downMost+j*radius*1.35, radius*0.7);
        }
    }
}