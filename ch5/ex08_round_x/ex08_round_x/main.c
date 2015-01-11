//
//  main.c
//  ex08_round_x
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program rounding off a number

#include <stdio.h>

int round_V2(double x);

int main(int argc, const char * argv[]) {
    double x;
    printf("The number is : ");
    scanf("%lf", &x);
    
    printf("Anwser is %d\n", round_V2(x));
    return 0;
}

int round_V2(double x) {
    if (x > 0)
        return (int)(x + 0.5);
    else
        return (int)(x - 0.5);
}