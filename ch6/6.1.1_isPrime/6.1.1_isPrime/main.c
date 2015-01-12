//
//  main.c
//  6.1.1_isPrime
//
//  Created by Cirno MainasuK on 2015-1-12.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

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
    long divisors, i;
    
    divisors = 0;
    for (i = 1; i <= n; i++) {
        if (n % i == 0)
            divisors++;
    }
    return (divisors == 2);
}