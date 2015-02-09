//
//  main.c
//  ex02_greek
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "greek.h"

#define file_PATH "/Users/MainasuK/Documents/Github/TASC/ch15/ex02_greek/ex02_greek/troilus.dat"

int main(int argc, const char * argv[]) {
    FILE *infile;
    infile = fopen(file_PATH, "r");
    greek(infile);
    return 0;
}
