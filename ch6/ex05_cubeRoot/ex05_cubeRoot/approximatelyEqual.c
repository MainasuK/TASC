//
//  approximatelyEqual.c
//  ex10_ApproximatelyEqual
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program approximatelyEqual two number x, y

#include "approximatelyEqual.h"
#include <math.h>

#define Epsilon 0.000001
#define TRUE  1
#define FALSE 0

int approximatelyEqual(double x, double y) {
    double appr;
    appr = fabs(x-y) / ((fabs(x)>fabs(y) ? fabs(x) : fabs(y)));
    if (appr < Epsilon)
        return TRUE;
    else
        return FALSE;
}

#undef TRUE
#undef FALSE