//
//  main.c
//  ex10_mean_calculator
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i, c, sum = 0;
    for (i = 0; i < 4; i++) {
        scanf("%d", &c);
        sum += c;
    }
    
    printf("The mean of 4 numbers is: %g\n", sum / 4.0);
    return 0;
}
