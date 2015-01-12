//
//  primeFactorization.c
//  ex02_prime_factorization
//
//  Created by Cirno MainasuK on 2015-1-12.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "primeFactorization.h"


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


void primeFactorization(long n) {
    while (n != 1) {
        int i;
        
        if (isPrime(n)) {
            printf("%ld\n", n);
            break;
        }
        
        for (i = 0; i <= n; i++) {
            if (!isPrime(i))
                continue;
            else {
                if ((n%i==0) && (n/i!=1)) {
                    printf("%d * ", i);
                    n /= i;
                    break;
                } else if ((n%i==0) && (n/i==1)) {
                    printf("%d\n", i);
                    n /= i;
                    break;
                } else {
                    continue;
                }
            }
        }
    }
}