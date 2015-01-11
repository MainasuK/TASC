//
//  main.c
//  ex03_c2ftable_v2
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program illustrates the use of functions by generating
//  a table of Fahrenheit to Celsius conversions

#include <stdio.h>

//  LowerLimit -- Starting value for temperature table
//  UpperLimit -- Final value for temperature table
//  StepSize   -- Step size between table entries

#define LowerLimit 32
#define UpperLimit 100
#define StepSize 2

double FahrenheitToCelsius(double c);

int main(int argc, const char * argv[]) {
    printf("Fahrenheit to Celsius table.\n");
    printf("  F     C\n");
    for (int i = LowerLimit; i <= UpperLimit; i += StepSize) {
        printf("%3d   %4.1lf\n", i, FahrenheitToCelsius(i));
    }
    return 0;
}

//  conver Fahrenheit to Celsius
double FahrenheitToCelsius(double f) {
    return (f - 32) * 5.0 / 9.0;
}
