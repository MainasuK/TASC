//
//  wc.c
//  ex01_wc
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "wc.h"
#include <ctype.h>

#define MAXLENS 1000

typedef enum {
    FALSE, TRUE,
} bool;

static int readWord(char *p);
static int readChar(char *p);

void wordCounter(FILE *f, int *l, int *w, int *ch) {
    char *nscan, *p;
    
    p = malloc(MAXLENS+1);
    *l = *w = *ch = 0;
    
    while (TRUE) {
        nscan = fgets(p, MAXLENS, f);
        if (nscan == NULL) break;
        *l += 1;
        *w += readWord(p);
        *ch += readChar(p);
    }
}

static int readWord(char *p) {
    int c, i = 0, w = 0;
    while ((c=*(p+i)) != '\0') {
        if (c == ' ' && !isspace(*(p+i+1))) {
            w++;
//            printf("%d %s ", w, (p+i));
        }
        i++;
    }
    return (w+1);
}

static int readChar(char *p) {
    int c, i = 0, ch = 0;
    while ((c=*(p+i)) != '\0') {
        if (!isspace(c)) {
            ch++;
//            printf("%d %s", ch, (p+i));
        }
        i++;
    }
    return ch;
}