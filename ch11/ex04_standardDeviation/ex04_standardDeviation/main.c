//
//  main.c
//  ex04_standardDeviation
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "judgeAverage.h"

int main(int argc, const char * argv[]) {
    double s[] = {312.2, 32.1, 44.1, 435.0, 48.5};
    int nS = sizeof(s)/sizeof(s[0]);
    
    printf("The standard deviation is %lf.\n",
           returnStandardDeviation(s, nS));
    return 0;
}
