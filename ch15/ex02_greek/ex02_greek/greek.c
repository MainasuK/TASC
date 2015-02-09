//
//  greek.c
//  ex02_greek
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "greek.h"
#include "random.h"

#define MAXLENS 1000

typedef enum {
    FALSE, TRUE,
} bool;

static void convertLine(char *p);

void greek(FILE *f) {
    char *nscan, *p;
    p = malloc(MAXLENS);
    while (TRUE) {
        nscan = fgets(p, MAXLENS, f);
        if (nscan == NULL) break;
        convertLine(nscan);
        printf("%s", nscan);
    }
    printf("\n");
    
}

static void convertLine(char *p) {
    char *c, i = 0;
    randomize();
    while (*(c=(p+i)) != '\0') {
        if (*c >= 'a' && *c <= 'z')
            *c = randomInteger('a', 'z');
        if (*c >= 'A' && *c <= 'Z')
            *c = randomInteger('A', 'Z');
//        printf("%c", *c);
        i++;
    }
}