//
//  main.c
//  ex08_PI_v2
//
//  Created by Cirno MainasuK on 2015-1-15.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define TRUE 1

//  This function calculate the PI, 9 digits are accurate.
long double pi(void);

int main(int argc, const char * argv[]) {
    printf("The PI is %.9Lf", pi());
    return 0;
}

long double pi(void) {
    long double a, b, c,tempPi;
    int ai, bi, ci;
    a = 1.0;
    b = 1.0;
    c = 0.5;
    
    ai = 1;
    bi = 1;
    ci = 1;
    
    long double Pi = a * b * c;
    while (TRUE) {
        tempPi = Pi;
        
        ai += 2;
        a *= (1.0*(ai-2))/(ai-1);
        bi += 2;
        b = 1.0/bi;
        ci += 2;
        c = pow(0.5, ci);
        
        Pi += a*b*c;
        if (tempPi == Pi)
            break;
    }
    return Pi * 6;
}