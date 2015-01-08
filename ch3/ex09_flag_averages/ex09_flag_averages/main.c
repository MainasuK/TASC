//
//  main.c
//  ex09_flag_averages
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define TURE 1

int main(int argc, const char * argv[]) {
    int i = 0;
    double value, total;
    
    printf("This program averages a list of integers.\n");
    printf("Enter -1 to signal the end of the list\n");
    
    total = 0;
    while (TURE) {
        printf(" ? ");
        scanf("%lf", &value);
        if (value == -1) break;
        total += value;
        i++;
    }
    
    printf("The total is %g\n", total/(i * 1.0));
    
    return 0;
}
