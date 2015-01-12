//
//  main.c
//  ex02_prime_factorization
//
//  Created by Cirno MainasuK on 2015-1-12.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "primeFactorization.h"

int main(int argc, const char * argv[]) {
    long n;
    printf("Enter number to be factored: ");
    scanf("%ld", &n);
    primeFactorization(n);
    
    return 0;
}
