//
//  main.c
//  ex05_median
//
//  Created by Cirno MainasuK on 2015-2-2.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "median.h"

int main(int argc, const char * argv[]) {
    double array[] = {12.2, 10.0, 13.4, 14.5, 56.2, 23.3};
    int nArray = sizeof(array)/sizeof(array[0]);
    
    printf("Median is %lf.\n", median(array, nArray));
    return 0;
}
