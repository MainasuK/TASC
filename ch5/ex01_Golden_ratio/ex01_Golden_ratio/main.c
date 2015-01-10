//
//  main.c
//  ex01_Golden_ratio
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

//  This program prints Golden ratio in a line.
#include <stdio.h>
#include <math.h>

void PrintGoldenRatio(void);

int main(int argc, const char * argv[]) {
    PrintGoldenRatio();
    
    return 0;
}


void PrintGoldenRatio(void) {
    double g;
    g = 0.5 * (1 + pow(5, 0.5));
    
    printf("%lf\n", g);
}