//
//  getData.c
//  ex02_getData
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <string.h>
#include "getData.h"

#define MAXLEN 10

char *monthTable[] = {
    NULL, "Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug", "Otc",
    "Nov", "Dec",
};

static int convertMonthToInt(char *m);

void getDate(int *dp, int *mp, int *yp) {
    char monthString[10];
    printf("Enter a date as dd-mmm-yy: ");
    scanf("%d-%3s-%d", dp, monthString, yp);
    *mp = convertMonthToInt(monthString);
    
}

static int convertMonthToInt(char *m) {
    for (int i = 1; i < 12; i++) {
        if (strcmp(monthTable[i], m) == 0)
            return i;
    }
    return (-1);
}