//
//  city.h
//  ex11_city
//
//  Created by Cirno MainasuK on 2015-1-24.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex11_city__city__
#define __ex11_city__city__

#include <stdio.h>
#include "random.h"
#include "DrawTools.h"

void drawCity(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid);
void drawPath(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid);
void drawPathUp(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid, int up, int right);
void drawPathRight(GLdouble x, GLdouble y, GLdouble width, GLdouble height, int grid, int up, int right);
#endif /* defined(__ex11_city__city__) */
