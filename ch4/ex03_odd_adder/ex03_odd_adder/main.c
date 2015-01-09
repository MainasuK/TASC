//
//  main.c
//  ex03_odd_adder
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int sum = 0, odd = 1;
    printf("This program add first N odd numbers. N =\n");
    printf(" ? ");
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        sum += odd;
        odd += 2;
    }
    
    printf("Sum is : %d\n", sum);
    
    return 0;
}
