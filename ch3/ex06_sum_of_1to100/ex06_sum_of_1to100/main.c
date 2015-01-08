//
//  main.c
//  ex06_sum_of_1to100
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int sum = 0;
    for (int i = 0; i <= 100; i++) {
        sum += i;
    }
    
    printf("Anwser: %d\n", sum);
    return 0;
}
