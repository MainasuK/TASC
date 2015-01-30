//
//  fill.c
//  ex12_fill
//
//  Created by Cirno MainasuK on 2015-1-29.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "fill.h"
#include <string.h>

static int margin = 65;

static bool overstepMargin(int i);
void setFillMargin(int n) {
    margin = n;
}

void printFilledString(char *str) {
    string token;
    int i = 0;
    InitScanner(str);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        i += strlen(token);
        if (overstepMargin(i)) {
            printf("\n");
            i %= margin;
        }
        printf("%s", token);
    }
    printf("\n");
}

static bool overstepMargin(int i) {
    if (i > margin) {
        return TRUE;
    }
    return FALSE;
}