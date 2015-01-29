//
//  main.c
//  ex12_fill
//
//  Created by Cirno MainasuK on 2015-1-29.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fill.h"

#define MAXLENS 1000

bool isPrime(long n);

int main(int argc, const char * argv[]) {
    char str[MAXLENS];

    for (long i = 0; i < 200; i++) {
        string p[MAXLENS];
        if (isPrime(i)) {
            sprintf(p, "%ld, ", i);
            strcat(str, p);
        }
    }
    setFillMargin(55);
    printFilledString(str);
    return 0;
}

bool isPrime(long n) {
    long i, limit;
    
    if (n <= 1) return (FALSE);
    if (n == 2) return (TRUE);
    if (n % 2 == 0) return (FALSE);
    limit = sqrt(n) + 1;
    for (i = 3; i <= limit; i += 2) {
        if (n % i == 0) return (FALSE);
    }
    return (TRUE);
}