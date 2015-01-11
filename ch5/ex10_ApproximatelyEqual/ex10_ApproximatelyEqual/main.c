//
//  main.c
//  ex10_ApproximatelyEqual
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program approximatelyEqual two number x, y

#include <stdio.h>
#include <math.h>

#define Epsilon 0.000001
#define TURE  1
#define FALSE 0


int approximateEqual(double x, double y);

int main(int argc, const char * argv[]) {
    for (double x = 1.0; x <= 2.0 || approximateEqual(x, 2.0); x += 0.1) {
        printf("%.1lf\n", x);
    }
    return 0;
}


int approximateEqual(double x, double y) {
    double appr;
    appr = fabs(x-y) / ((fabs(x)>fabs(y) ? fabs(x) : fabs(y)));
    if (appr < Epsilon)
        return TURE;
    else
        return FALSE;
}