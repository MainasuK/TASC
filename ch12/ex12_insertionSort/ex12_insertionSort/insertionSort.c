//
//  insertionSort.c
//  ex12_insertionSort
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "insertionSort.h"

typedef enum {
    FALSE, TRUE
} bool;

static bool isSort(int *array, int start, int end);
static int nIsSort(int *array, int n);
static void swapOfInsertionSortMethod(int *array, int lh, int rh);
static void swapArrayElements(int *array, int p1, int p2);
static int findSmallestElement(int *array, int start, int end);

void insertionSort(int *s, int n) {
    int lh, rh;
    while (!isSort(s, 0, n)) {
        rh = nIsSort(s, n);
        lh = findSmallestElement(s, 0, rh-1);
        swapOfInsertionSortMethod(s, lh, rh);
    }
}

static bool isSort(int *s, int start, int end) {
    for (int i = start+1; i < end; i++) {
        if (s[i-1] > s[i]) {
            return FALSE;
        }
    }
    
    return TRUE;
}

static int nIsSort(int *s, int n) {
    for (int i = 1; i < n; i++) {
        if (s[i-1] > s[i]) {
            return i;
        }
    }
    
    return (-1);
}

static void swapOfInsertionSortMethod(int *s, int lh, int rh) {
    for (int i = rh; i > lh; i--) {
        swapArrayElements(s, i, i-1);
    }
}

static void swapArrayElements(int *s, int p1, int p2) {
    int temp;
    
    temp = s[p1];
    s[p1] = s[p2];
    s[p2] = temp;
}

static int findSmallestElement(int *s, int start, int end) {
    int min;
    int index;
    min= s[start];
    index = start;
    for (int i = start; i < end; i++) {
        if (s[i] < min) {
            min = s[i];
            index = i;
        }
    }
    
    return index;
}