//
//  statistic.c
//  ex07_statistic
//
//  Created by Cirno MainasuK on 2015-1-31.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "statistic.h"

#define STRLENS 100
#define LEN ((Max - Min) / INTERVAL + 1)

static int array[LEN];
static char interval[LEN][STRLENS];

static void initArray(void);
static void readInteger(void);
static bool isLegal(int c);

void getIntegerArray(void) {
    initArray();
    readInteger();
}

void printIntegerGraph(void) {
    printf("\n");
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
    
    for (int i = 0; i < LEN; i++) {
        sprintf(interval[i], "%-2d-%-3d| ", Min+i*INTERVAL, Min+(i+1)*INTERVAL-1);
    }
    sprintf(interval[LEN-1], "%-7d| ", Max);
}

static void readInteger(void) {
    int c;
    while (TRUE) {
        scanf("%d", &c);
        if (!isLegal(c))
            break;
        array[(c-Min)/INTERVAL] += 1;
    }
}

static bool isLegal(int c) {
    if (c == -1)
        return FALSE;
    if (c < Min || c > Max)
        return FALSE;
    return TRUE;
}