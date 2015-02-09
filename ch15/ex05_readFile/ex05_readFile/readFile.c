//
//  readFile.c
//  ex05_readFile
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <string.h>
#include "readFile.h"

typedef enum {
    FALSE, TRUE,
} bool;

static char *ptr[BUFFLEN];

char *readFile(FILE *f) {
    int *nscan;
    char *buf, *p;
    int i = 0;
    buf = malloc(BUFFLEN);
    while (TRUE) {
        nscan = (int *)fgets(buf, BUFFLEN, f);
        if (nscan == NULL) break;
        ptr[i] = malloc(strlen(nscan)+1);
        strcpy(ptr[i], nscan);
        i++;

        
    }
    ptr[i] = "\0";
    
    p = (char *)ptr;
    return p;
}

void inverseOrderPrint(void) {
    int i;
    for (i = 0; i < BUFFLEN; i++) {
        if (strcmp(ptr[i], "") == 0) break;
    }
    
    for (int j = i-1; j >= 0; j--) {
        printf("%s", ptr[j]);
    }
    
}