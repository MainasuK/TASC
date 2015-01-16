//
//  main.c
//  ex10_e
//
//  Created by Cirno MainasuK on 2015-1-16.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program prints the e (mathematical constant)
//  with 10 significant digits after decimal point.

#include <stdio.h>
#include "fact.h"
#define TRUE 1

long double e(void);

int main(int argc, const char * argv[]) {
        printf("The value of e is : %.10Lf\n", e());
    return 0;
}

long double e(void) {
    long double i, e, eTemp;
    e = 0;
    while (eTemp != e) {
        eTemp = e;
        e += 1.0/factorial(i);
        i++;
        
    }
    return e;
}