//
//  main.c
//  ex05_readFile
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "readFile.h"

#define FILE_PATH "/Users/MainasuK/Documents/Github/TASC/ch15/ex05_readFile/ex05_readFile/prospero.txt"
int main(int argc, const char * argv[]) {
    FILE *infile;
    char *p;
    infile = fopen(FILE_PATH, "r");
    p = readFile(infile);
    inverseOrderPrint();
    return 0;
}
