//
//  main.c
//  ex05_RaiseInToPower
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program use a function RaiseInToPower
//  to print a table which power n with integer k from 0 to k

#include <stdio.h>

long RaiseInToPower(int n, int k);

int main(int argc, const char * argv[]) {
    int i, n, k;
    
    printf("n^k\n");
    printf(" n ? ");
    scanf("%d", &n);
    printf(" k ? ");
    scanf("%d", &k);
    
    for (i = 0; i <= k; i++) {
        printf("%ld\n", RaiseInToPower(n, i));
    }
    return 0;
}

long RaiseInToPower(int n, int k) {
    long sum = n;
    
    if (k == 0) return 1;
    
    for (int i = 1; i < k; i++) {
        sum *= n;
    }
    return sum;
}