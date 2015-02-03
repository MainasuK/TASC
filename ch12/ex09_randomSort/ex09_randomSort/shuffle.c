//
//  shuffle.c
//  ex09_randomSort
//
//  Created by Cirno MainasuK on 2015-2-3.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "shuffle.h"

static void swapIntegerElements(int *array, int p1, int p2);

int shuffleSort(int *array, int n) {
    int lh, rh;
    randomize();
    
    for (lh = 0; lh < n; lh++) {
        rh = randomInteger(0, n-1);
        swapIntegerElements(array, lh, rh);
    }
    
    return n;
}

static void swapIntegerElements(int *array, int p1, int p2) {
    int tmp;
    
    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}