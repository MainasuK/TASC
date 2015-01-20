//
//  drawMemoria.h
//  ex09_Lincoln_Memoria
//
//  Created by Cirno MainasuK on 2015-1-20.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex09_Lincoln_Memoria__drawMemoria__
#define __ex09_Lincoln_Memoria__drawMemoria__

#include <stdio.h>
#include "DrawTools.h"

#define MemorialWidth       4.0
#define PedestalHeight      0.3

#define NumberOfColumns     12
#define ColumnWidth         0.15
#define ColumnHeight        1.0
#define ColumnCircleRadius  0.05

#define LowerRoofHeight     0.5
#define UpperRoofWidth      3.5
#define UpperRoofHeight     0.3

#define StatueWidth         0.1
#define StatueHeight        0.2

void drawMemorial(GLdouble x, GLdouble y);
void drawPedestal(GLdouble x, GLdouble y);
void drawColumn(GLdouble x, GLdouble y);
void drawRoof(GLdouble x, GLdouble y);
void drawStatue(GLdouble x, GLdouble y);
#endif /* defined(__ex09_Lincoln_Memoria__drawMemoria__) */
