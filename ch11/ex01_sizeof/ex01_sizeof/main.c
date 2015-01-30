//
//  main.c
//  ex01_sizeof
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    printf("Values of type char require %lu byte.\n", sizeof(char));
    printf("Values of type int require %lu byte.\n", sizeof(int));
    printf("Values of type short require %lu byte.\n", sizeof(short));
    printf("Values of type long require %lu byte.\n", sizeof(long));
    printf("Values of type float require %lu byte.\n", sizeof(float));
    printf("Values of type double require %lu byte.\n", sizeof(double));
    return 0;
}
