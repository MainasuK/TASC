//
//  main.c
//  ex05_cubeRoot
//
//  Created by Cirno MainasuK on 2015-1-15.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "cubeRoot.h"

int main(int argc, const char * argv[]) {
    int x;
    printf("This program return the cube root of a number.");
    printf(" ? ");
    scanf("%d", &x);
    printf("The cube root is %g.\n", cubeRoot(x));
    return 0;
}

