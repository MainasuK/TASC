//
//  removeDuplicates.c
//  ex08_removeDuplicates
//
//  Created by Cirno MainasuK on 2015-2-3.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "removeDuplicates.h"

static int findLargestInteger(int *array, int low, int high);

int removeDuplicates(int *array, int n) {
    int len = n;
    int max = findLargestInteger(array, 0, n);
    sortIntegerArray(array, n);
    
    for (int i = 1; i < n; i++) {
        if (array[i-1] == array[i]) {
            array[i-1] = max + 1;
            len--;
        }
    }
    
    sortIntegerArray(array, len);
    return (len);
}



static int findLargestInteger(int array[], int low, int high) {
    int i, spos;
    
    spos = low;
    for (i = low; i <= high; i++) {
        if (array[i] > array[spos]) spos = i;
    }
    return (spos);
}