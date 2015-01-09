//
//  main.c
//  ex10_print_stars
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

//  This program print stars with n * n
int main(int argc, const char * argv[]) {
    int n;
    printf(" ? lines: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
