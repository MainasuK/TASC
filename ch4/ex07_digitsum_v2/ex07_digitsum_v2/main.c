//
//  main.c
//  ex07_digitsum_v2
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define TURE 1

int main(int argc, const char * argv[]) {
    int n, copy;
    int i = 0, anti = 0;
    
    printf("This program sums the the digits in an integer.\n");
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    copy = n;
    while (copy) {
        copy /= 10;
        i++;
    }
    
    while (n > 0) {
        int temp = n % 10;
        n /= 10;
        anti += temp * pow(10, --i);
    }
    
    printf("The anti order number is : %d\n", anti);
    return 0;
}
