//
//  main.c
//  ex01_add10
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i;
    double value, total;
    
    printf("This program adds a list of numbers.\n");
    printf("Signal end of list with a 0.\n");

    total = 0;
    for (i = 0; i < 10; i++) {
        printf(" ? ");
        scanf("%lf", &value);
        total += value;
    }
    
    printf("The total is %g\n", total);
    
    return 0;
}
