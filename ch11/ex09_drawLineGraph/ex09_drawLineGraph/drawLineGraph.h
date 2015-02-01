//
//  drawLineGraph.h
//  ex09_drawLineGraph
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex09_drawLineGraph__drawLineGraph__
#define __ex09_drawLineGraph__drawLineGraph__

#include "DrawTools.h"

typedef enum {
    FALSE, TRUE,
} bool;

typedef struct point {
    GLdouble x;
    GLdouble y;
} Point;


void drawLineGraph(int n);
Point getNextPoint(void);

#endif /* defined(__ex09_drawLineGraph__drawLineGraph__) */
