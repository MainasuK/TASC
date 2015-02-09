//
//  madlibs.c
//  ex06_madlibs
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <string.h>
#include "madlibs.h"

#define BUFSIZE 100

typedef enum {
    FALSE, TRUE,
} bool;

typedef enum {
    verb,
    sameVerb,
    adjective,
    pluralNoun,
} mark;


static mark markComp(char *mark);
static void printMark(int mark, char *verb, char *sameVerb,
                      char *adjective, char *pluralNoun);

void outputMadlibs(FILE *f, char *v, char *sV,
                   char *a, char *pN) {
    int *nscan, mark, ch;
    char *buf;
    
    buf = malloc(BUFSIZE);
    
    while ((ch=getc(f)) != EOF) {
        if (ch == '<') {
            fscanf(f, "%[^>]>", buf);
            mark = markComp(buf);
            printMark(mark, v, sV,
                      a, pN);
        } else {
            putchar(ch);
        }
    }
    printf("\n");
}


static mark markComp(char *m) {
    if (!strcmp(m, "verb"))
        return verb;
    if (!strcmp(m, "same verb"))
        return sameVerb;
    if (!strcmp(m, "adjective"))
        return adjective;
    if (!strcmp(m, "plural noun"))
        return pluralNoun;
    
    return (-1);
}

static void printMark(int m, char *v, char *sV,
                      char *a, char *pN) {
    switch (m) {
        case verb:
            printf("%s", v);
            break;
        case sameVerb:
            printf("%s", sV);
            break;
        case adjective:
            printf("%s", a);
            break;
        case pluralNoun:
            printf("%s", pN);
            break;
            
        default:
            break;
    }
}