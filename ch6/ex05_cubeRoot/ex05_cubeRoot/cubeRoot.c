//
//  cubeRoot.c
//  ex05_cubeRoot
//
//  Created by Cirno MainasuK on 2015-1-15.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "cubeRoot.h"
#include "approximatelyEqual.h"

double cubeRoot(double x) {
    double g;

    if (x == 0) return (0);
    if (x < 0) printf("cubeRoot called with negative arguments %g", x);
    g = x;
    
    while (!approximatelyEqual(x, g * g * g)) {
        g = (g + x/(g*g)) / 2;
    }
    
    return g;
}