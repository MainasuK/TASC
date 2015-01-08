//
//  main.c
//  ex07_the_mean_of_5_number
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int c, sum = 0;
    printf("This program averages a list of 5 integers.\n");
    for (int i = 0; i < 5; i++) {
        printf(" ? ");
        scanf("%d", &c);
        sum += c;
    }
    
    printf("The average is %g\n", sum / 5.0);
    return 0;
}
