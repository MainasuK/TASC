//
//  judgeAverage.h
//  ex02_judge_average
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex02_judge_average__judgeAverage__
#define __ex02_judge_average__judgeAverage__

#include <stdio.h>

void initScore(void);
void getScore(void);
void removeMinMax(void);
void printAverage(void);

double returnMean(double *array, int n);
double returnStandardDeviation(double *array, int n);

#endif /* defined(__ex02_judge_average__judgeAverage__) */
