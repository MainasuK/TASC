//
//  removeZeroElements.c
//  ex07_removeZeroElements
//
//  Created by Cirno MainasuK on 2015-2-2.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "removeZeroElements.h"

int removeZeroElements(int *array, int n) {
    int nZero = 0;
    int nMax = 0;
    
    sortIntegerArray(array, n);
    for (int i = 0; i < n; i++) {
        if (array[i] == 0) {
            nZero++;
        }
        
        nMax = (array[i] > nMax) ? array[i] : nMax;
    }
    
    for (int j = 0; j < nZero; j++) {
        array[j] = (nMax+1);
    }
    
    sortIntegerArray(array, n);
    
    return (n-nZero);
}