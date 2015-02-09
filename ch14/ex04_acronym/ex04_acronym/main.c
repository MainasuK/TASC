//
//  main.c
//  ex04_acronym
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

#define MAXLENS 100

void myAcronmy(char *dst, char *src) {
    while (*src != '\0') {
        if (*src != ' ') {
            *dst = *src;
            dst++;
            while (*src != ' ' && *src != '\0') {
                src++;
            }
        } else {
            src++;
        }
    }
    *dst = '\0';
}


int main(int argc, const char * argv[]) {
    char dst[MAXLENS];
    char src[] = "This program is print";
    myAcronmy(dst, src);
    printf("%s\n", dst);
    
    return 0;
}


