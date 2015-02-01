//
//  main.c
//  ex01_resistor
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//


#include "resistor.h"

int main(int argc, const char * argv[]) {
    colorT st, nd, rd;
    printf("This program interprets the resistor color code.\n");
    st = getFirstBand("Color of first band: ");
    nd = getSecondBand("Color of second band: ");
    rd = getThirdBand("Color of third band: ");
    printf("Resistance = %d ohms.\n", getResistance(st, nd, rd));
    
    return 0;
}
