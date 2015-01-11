//
//  main.c
//  ex06_RaiseRealToPower
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program use a function RaiseInToPower
//  to print power n with integer k from start to end

#include <stdio.h>

long double RaiseRealToPower(int n, int k);

int main(int argc, const char * argv[]) {
    int i, start, end;
    double n;
    
    printf("n^k\n");
    printf(" n ? ");
    scanf("%lf", &n);
    printf(" k start ? ");
    scanf("%d", &start);
    printf(" k end   ? ");
    scanf("%d", &end);
    
    printf("--------------------\n");
    for (i = start; i <= end; i++) {
        if (i < 0)
            printf("%4d        %-6Lg\n", i, RaiseRealToPower(n, i));
        else
            printf("%4d %8Lg\n", i, RaiseRealToPower(n, i));
    }
    return 0;
}

long double RaiseRealToPower(int n, int k) {
    int index = k;
    long double sum = n;
    index = (k<0) ? -k : k;
    if (k == 0) return 1;
    
    for (int i = 1; i < index; i++) {
        sum *= n;
    }
    if (k < 0)
        return 1 / sum;
    else
        return sum;
}
