//
//  statistic.c
//  ex07_statistic
//
//  Created by Cirno MainasuK on 2015-1-31.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "statistic.h"

#define LEN 11

static int array[LEN];

static char *interval[] = {
    "0-9    |",
    "10-19  |",
    "20-29  |",
    "30-39  |",
    "40-49  |",
    "50-59  |",
    "60-69  |",
    "70-79  |",
    "80-89  |",
    "90-99  |",
    "100    |",
};

static void initArray(void);
static void readInteger(void);

void getIntegerArray(void) {
    initArray();
    readInteger();
}

void printIntegerGraph(void) {
    for (int i = 0; i < LEN; i++) {
        printf("%s ", interval[i]);
        for (int j = 0; j < array[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

static void initArray(void) {
    for (int i = 0; i < LEN; i++) {
        array[i] = 0;
        i++;
    }
}

static void readInteger(void) {
    int c;
    while (TRUE) {
        scanf("%d", &c);
        if (c == -1)
            break;
        array[c/10] += 1;
        
    }

}