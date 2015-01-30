//
//  main.c
//  ex05_theSieveOfEratosthenes
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "theSleveOfEratosthenes.h"

int main(int argc, const char * argv[]) {
    int N;
    printf("This program prints all prime numbers since 2 to a number you want:\n");
    printf("(No more than 9999.)\n");
    printf(" ? ");
    scanf("%d", &N);
    getSlaveTable(N);
    return 0;
}
