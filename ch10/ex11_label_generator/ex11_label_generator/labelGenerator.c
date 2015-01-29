//
//  labelGenerator.c
//  ex11_label_generator
//
//  Created by Cirno MainasuK on 2015-1-29.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "labelGenerator.h"

#define MAXLENS 100

static char buffer[MAXLENS];
static int indexP;

static void readPrefix(char *s);
static void readStartNumber(int *n);


void readLable(void) {
    readPrefix(buffer);
    readStartNumber(&indexP);
}

void printLable(int loop) {
    for (int i = 0; i < loop; i++) {
        printf("%s", buffer);
        printf("%d", indexP++);
        printf("\n");
    }
}

static void readPrefix(char *s) {
    int c;
    printf("Prefix to use for labels: ");
    while ((c=getchar()) != '\n') {
        *(s++) = c;
    }
    *s = '\0';
    
}

static void readStartNumber(int *n) {
    printf("Starting number: ");
    scanf("%d", n);
}