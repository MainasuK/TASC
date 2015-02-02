//
//  median.c
//  ex05_median
//
//  Created by Cirno MainasuK on 2015-2-2.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "median.h"

double median(double *array, int n) {
    sortDoubleArray(array, n);
    
    if (n % 2) {
        return (array[n/2] + array[n/2+1])*0.5;
    } else {
        return (array[n/2+1]);
    }
}
