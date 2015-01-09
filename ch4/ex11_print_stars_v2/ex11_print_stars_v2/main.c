//
//  main.c
//  ex11_print_stars_v2
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

//  This program print stars, likes triangle
int main(int argc, const char * argv[]) {
    int n;
    printf(" ? lines: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for(int j = n - i; j > 0; j--)
            printf(" ");
        
        
        for(int j = 0; j < i; j++)
            printf("*");
        
        for(int j = 0; j < i - 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}

