//
//  bubbleSort.c
//  ex11_bubbleSort
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "bubbleSort.h"

static void swapArrayElements(int *array, int p1, int p2);
static void printLog(int *array, int n);

void bubbleSort(int *s, int n) {
    int lh, rh;
    lh = 0;
    rh = n;
    while (lh < rh) {
        for (int j = lh; j < rh-1; j++) {
            if (s[j] > s[j+1]) {
                swapArrayElements(s, j, j+1);
                // printLog(s, n);
                // printf("lh:%d, rh:%d, j:%d\n", lh, rh, j);
            }
        }
        rh--;
    }
}

static void swapArrayElements(int *s, int p1, int p2) {
    int temp;
    
    temp = s[p1];
    s[p1] = s[p2];
    s[p2] = temp;
}

static void printLog(int *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}