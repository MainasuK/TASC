//
//  main.c
//  ex01_oldStyleAbbreviation
//
//  Created by Cirno MainasuK on 2015-1-28.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

#include "oldStyleAbbreviation.h"

#define MAXLENS 100

int main(int argc, const char * argv[]) {
    char address[MAXLENS];
    
    getAddress(address);                //  getAddress
    oldStyleAbbreviation(address);      //  convert to abbreviation
    return 0;
}
