//
//  main.c
//  ex02_random_even_2to100
//
//  Created by Cirno MainasuK on 2015-1-21.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "random.h"

#define NTRIALS 10

int randomEven(int low, int high);

int main(int argc, const char * argv[]) {
    for (int i = 0; i < NTRIALS; i++) {
        printf("%d\n", randomEven(2, 100));
    }
    return 0;
}

int randomEven(int low, int high) {
    return 2 * randomInteger(low/2, high/2);
}