//
//  tabulate.c
//  ex06_tabluate
//
//  Created by Cirno MainasuK on 2015-2-5.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdlib.h>
#include "tabulate.h"
#include "sort.h"

static int nElementsInArray(int *array, int n);
static void outputCount(int *array, int *ip, int n, int nip);
static void getCount(int *array, int *p, int n, int nip);
static void initCountTable(int *ip, int nip);

static void plog(int *array, int *ip, int n, int nip);

void tabluate(int *s, int n) {
    int elements, *ip;
    sortIntegerArray(s, n);
    elements = nElementsInArray(s, n);
    ip = malloc(elements * sizeof(int));
    if (ip == NULL)
        exit(-1);
    
    getCount(s, ip, n, elements);
    outputCount(s, ip, n, elements);
}

static int nElementsInArray(int *s, int n) {
    int p = 1;
    for (int i = 1; i < n; i++) {
        if (s[i-1] != s[i]) {
            p++;
        }
    }
    return p;
}


static void outputCount(int *s, int *p, int n, int nip) {
    for (int i = 1, j = 0; j < nip; i++) {
        //printf("i:%d j:%d\n", i, j);
        if (s[i-1] != s[i]) {
            printf("%d: %d\n", s[i-1], p[j]);
            j++;
        }
    }
}

static void getCount(int *s, int *p, int n, int nip) {
    int bit = 0;
    initCountTable(p, nip);
    
    for (int i = 1; i < n; i++) {
        //plog(s, p, n, nip);
        if (s[i-1] != s[i]) {
            bit++;
        } else {
            p[bit] += 1;
        }
    }
}

static void initCountTable(int *p, int nip) {
    for (int i = 0; i < nip; i++) {
        p[i] = 1;
    }
}

static void plog(int *s, int *p, int n, int nip) {
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    
    for (int i = 0; i < nip; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    printf("\n");
}