//
//  main.c
//  ex03_isPerfect
//
//  Created by Cirno MainasuK on 2015-1-15.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program read number and return TURE or FALSE when
//  the number is a perfect number or not.

#include <stdio.h>
#define TRUE  1
#define FALSE 0
#define MAXNUM   9999
//  This function read a positive integer and tell the user
//  whether it is a perfect number or not.
int isPerfect(int n);

int main(int argc, const char * argv[]) {
    for (int i = 1; i < MAXNUM; i++)
        if (isPerfect(i)) {
            printf("It's a perfect number : %d.\n", isPerfect(i));
        }
    return 0;
}

int isPerfect(int p) {
    int n, sum;
    n = p;
    sum = 0;
    if (n == 1) return FALSE;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            sum +=i;
    }
    if (sum == p)
        return p;
    else
        return FALSE;
}

#undef TRUE 
#undef FALSE