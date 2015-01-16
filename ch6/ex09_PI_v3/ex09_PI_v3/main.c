//
//  main.c
//  ex09_PI_v3
//
//  Created by Cirno MainasuK on 2015-1-16.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program calculate the area of 1/4 cicle(r = 2)
//  to get the value of Pi (4 digits accurate)

#include <stdio.h>
#include <math.h>

#define RECTITEMS 100000

long double pi(void);

int main(int argc, const char * argv[]) {
    printf("The value of PI is : %.5Lf\n", pi());
    return 0;
}

long double pi(void) {
    long double area, w, h, r, x;
    area = 0.0;
    r = 2.0;
    x = 0.0;
    w = r / RECTITEMS;
    for (int i = 0; i < RECTITEMS; i++) {
        x += w / 1.000001;
        h = pow(pow(r, 2) - pow(x, 2), 0.5);
        area += h * w;
    }
    
    return area;
}