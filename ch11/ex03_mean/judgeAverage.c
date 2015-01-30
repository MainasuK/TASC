//
//  judgeAverage.c
//  ex02_judge_average
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "judgeAverage.h"

#define MAXLENS 100

static double score[MAXLENS];
static int nScore;

void initScore(void) {
    nScore = 0;
    for (int i = 0; i < MAXLENS; i++) {
        score[i] = 0;
    }
}

void getScore(void) {
    double t;
    printf("This program read score and print average score without Min & Max.\n");
    for (int i = 0; i < MAXLENS; i++) {
        printf(" ? ");
        scanf("%lf", &t);
        if (t == 0)
            break;
        score[i] = t;
        nScore++;
    }
}

void removeMinMax(void) {
    int nMin, nMax;
    double min, max;
    min = max = score[0];
    nMin = nMax = 0;
    
    for (int i = 0; i < nScore; i++) {
        if (score[i] < min) {
            min = score[i];
            nMin = i;
        }
        if (score[i] > max) {
            max = score[i];
            nMax = i;
        }
    }
    
    score[nMin] = 0;
    score[nMax] = 0;
}

void printAverage(void) {
    double sum = 0;
    
    for (int i = 0; i < nScore; i++) {
        sum += score[i];
    }
    
    printf("Average is: %lf\n", sum / (nScore - 2));
}

double returnMean(double *array, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    
    return sum / n;
}
