//
//  main.c
//  ex06_Monte_Carlo_method_PI
//
//  Created by Cirno MainasuK on 2015-1-22.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program use Monte Carlo method to get the value of PI
#include <stdio.h>
#include "random.h"

#define TIMES 10000

double MonteCarloPI(void);

int main(int argc, const char * argv[]) {
    printf("PI is %lf\n", MonteCarloPI());
    return 0;
}

double MonteCarloPI(void) {
    double x, y;
    int loop = 0;
    randomize();
    x = randomReal(-1, 1);
    y = randomReal(-1, 1);
    for (int i = 0; i < TIMES; i++) {
        x = randomReal(-1, 1);
        y = randomReal(-1, 1);
        if (x * x + y * y < 1) {
            loop++;
        }
    }
    
    return ((double)loop / (double)TIMES) * 4;
}