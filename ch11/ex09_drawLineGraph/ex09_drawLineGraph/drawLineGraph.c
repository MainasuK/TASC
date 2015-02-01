//
//  drawLineGraph.c
//  ex09_drawLineGraph
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawLineGraph.h"

#define originX -1
#define originY -1

void drawLineGraph(int n) {
    printf("Point No.1: \n");
    Point A = getNextPoint();
    for (int i = 1; i < n; i++) {
        printf("Point No. %d: \n", i);
        Point temp = getNextPoint();
        drawLine(originX+A.x, originY+A.y, originX+temp.x, originY+temp.y);
        A.x = temp.x;
        A.y = temp.y;
    }
}

Point getNextPoint(void) {
    Point i;
    scanf("%lf%lf", &i.x, &i.y);
    return i;
}