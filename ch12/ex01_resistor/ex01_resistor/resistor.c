//
//  resistor.c
//  ex01_resistor
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "resistor.h"

#define STRLENS 100

static char *colorTable[] = {
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "grey",
    "white"
};

static colorT getColor(void);

colorT getFirstBand(char *s) {
    printf("%s", s);
    return getColor();
}

colorT getSecondBand(char *s) {
    printf("%s", s);
    return getColor();
}

colorT getThirdBand(char *s) {
    printf("%s", s);
    return getColor();
}

int getResistance(int st, int nd, int rd) {
    int resistance = 0;
    return resistance += (10 * st + nd) * pow(10, rd);
}

static colorT getColor(void) {
    char str[STRLENS];
    int c;
    int i = 0;
    while ((c=getchar()) != '\n') {
        str[i] = tolower(c);
        i++;
    }
    str[i] = '\0';
    
    for (int i = 0; i < nColor; i++) {
        if (strcmp(colorTable[i], str) == 0) {
            return i;
        }
    }
    
    exit(2);
}