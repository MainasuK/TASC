//
//  main.c
//  ex07_NDigits
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program gets a integer and return how many digits it has

#include <stdio.h>

int NDigits(int n);

int main(int argc, const char * argv[]) {
    int n;
    printf("number n :");
    scanf("%d", &n);
    printf("Its has %d digits.\n", NDigits(n));
    return 0;
}

int NDigits(int n) {
    int digits = 0;
    
    while (n) {
        n /= 10;
        digits++;
    }
    return digits;
}