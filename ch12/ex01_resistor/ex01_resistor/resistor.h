//
//  resistor.h
//  ex01_resistor
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex01_resistor__resistor__
#define __ex01_resistor__resistor__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define nColor 10

typedef enum {
    black,
    brown,
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    grey,
    white
} colorT;



colorT getFirstBand(char *);
colorT getSecondBand(char *);
colorT getThirdBand(char *);
int getResistance(int st, int nd, int rd);

#endif /* defined(__ex01_resistor__resistor__) */
