//
//  mode.c
//  ex06_mode
//
//  Created by Cirno MainasuK on 2015-2-2.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "mode.h"

static int findLargestInteger(int array[], int low, int high);

int mode(int array[], int n) {
    int npos, nTimes[n];
    int num;
    npos = 0;
    num = array[0];
    
    for (int i = 1; i < n; i++) {
        if (num == array[i]) {
            nTimes[npos]++;
        } else {
            npos = i;
        }
    }
    
    return (array[findLargestInteger(nTimes, 0, n)]);
    
}


static int findLargestInteger(int array[], int low, int high) {
    int i, spos;
    
    spos = low;
    for (i = low; i <= high; i++) {
        if (array[i] > array[spos]) spos = i;
    }
    return (spos);
}
