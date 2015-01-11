//
//  main.c
//  ex09_IsPerfectSquare_n
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program judge a number perfect square
#include <stdio.h>

#define TURE 1
#define FALSE 0

int IsPerfectSquare(int n);

int main(int argc, const char * argv[]) {
    int n;
    printf("Is perfect square number ?\n ? ");
    scanf("%d", &n);
    
    printf("%s\n", IsPerfectSquare(n) ? "TURE" : "FALSE");
    return 0;
}

int IsPerfectSquare(int n) {
    int i;
    for (i = 0; i * i <= n; i++) {
        if (n == i*i) {
            return TURE;
        }
    }
    
    return FALSE;
}