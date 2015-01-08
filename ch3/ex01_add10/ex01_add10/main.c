//
//  main.c
//  ex01_add10
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define TURE 1
int main(int argc, const char * argv[]) {
    int value, total;
    
    printf("This program adds a list of numbers.\n");
    printf("Signal end of list with a 0.\n");
    total = 0;
    while (TURE) {
        printf(" ? ");
        scanf("%d", &value);
        if (value == 0) break;
        total += value;
    }
    
    printf("The total is %d\n", total);
    
    return 0;
}
