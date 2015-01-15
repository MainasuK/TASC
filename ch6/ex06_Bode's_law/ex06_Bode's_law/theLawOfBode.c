//
//  theLawOfBode.c
//  ex06_Bode's_law
//
//  Created by Cirno MainasuK on 2015-1-15.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  Bode's Law is di = (4 + bi) / 10
//  b1 = 1      b2 = 3      b3 = 6
//  b4 = 12     b5 = 24     b6 = 48
//  …
//  bi = 2 * b(i-1)     (just b1 = 1, b2 = 3)

#include "theLawOfBode.h"

double theLawOfBode(int i) {
    int b[8] = {1, 3, 6, 12, 24, 48, 96, 192};
    
    if (i > 1)
        return (4.0 + b[i-1]) / 10.0;
    else
        return (0.5);
}