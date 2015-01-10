//
//  quadratic.c
//  ex02_quadratic_function
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "quadratic.h"

void GetCoefficients(void) {
    int a, b, c;
    double r1, r2;
    
    printf("Enter coefficients for the quadratic equation: \n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    
    r1 = (-b + pow(b*b-4*a*c,0.5))/(2.0*a);
    r2 = (-b - pow(b*b-4*a*c,0.5))/(2.0*a);
    printf("The first solution is %g\n", r1);
    printf("The second solution is %g\n", r2);
}

void PrintResult(void) {
    
}
