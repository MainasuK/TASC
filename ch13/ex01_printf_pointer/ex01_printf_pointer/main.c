//
//  main.c
//  ex01_printf_pointer
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

static int globalCount;
static double globalArray[100];
static char *globalPointer;

int main(int argc, const char * argv[]) {
    int count;
    double array[100];
    char *cp;
    
    printf("globalCount = %p\n", &globalCount);
    printf("globalArray = %p\n", globalArray);
    printf("globalPointer = %p\n", &globalPointer);
    printf("count = %p\n", &count);
    printf("array = %p\n", array);
    printf("cp = %p\n", &cp);

    return 0;
}
