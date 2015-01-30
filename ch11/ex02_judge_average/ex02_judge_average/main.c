//
//  main.c
//  ex02_judge_average
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "judgeAverage.h"

int main(int argc, const char * argv[]) {
    initScore();
    getScore();
    removeMinMax();
    printAverage();
    return 0;
}
