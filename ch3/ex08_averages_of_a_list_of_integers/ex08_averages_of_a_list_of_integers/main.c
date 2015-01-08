//
//  main.c
//  ex08_averages_of_a_list_of_integers
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int c, lim, sum = 0;
    printf("This program averages a list of 5 integers.\n");
    printf("How many values are there in the list? ");
    scanf("%d", &lim);
    
    for (int i = 0; i < lim; i++) {
        printf(" ? ");
        scanf("%d", &c);
        sum += c;
    }
    
    printf("The average is %g\n", sum / 5.0);
    return 0;
}
