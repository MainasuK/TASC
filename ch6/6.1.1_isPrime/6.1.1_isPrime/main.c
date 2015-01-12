//
//  main.c
//  6.1.1_isPrime
//
//  Created by Cirno MainasuK on 2015-1-12.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define TRUE  1
#define FALSE 0

long isPrime(long n);

int main(int argc, const char * argv[]) {
    long n;
    printf("This program read a number and judge if it's a prime.\n");
    printf("n ? ");
    scanf("%ld", &n);
    printf("This number is %sprime.\n", (isPrime(n) ? "" : "not "));
    return 0;
}

long isPrime(long n) {
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