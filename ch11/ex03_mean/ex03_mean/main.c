//
//  main.c
//  ex03_mean
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "judgeAverage.h"


int main(int argc, const char * argv[]) {
    double array[] = {1, 4, 6, 3, 5, 2, 0, 5, 7, 9};
    printf("Mean is: %lf\n",
           returnMean(array, sizeof(array) / sizeof(array[0])));
    return 0;
}
