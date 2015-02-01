//
//  sort.c
//  ex04_alphabetize
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  File: sort.c
//  --------------
//  This file implements the sort.h interface using the selection
//  sort algorithm.

#include <string.h>
#include "sort.h"
#include "genlib.h"
#include "sort.h"

//  private function prototypes

static int findSamllestInteger(int array[], int low, int high);
static void swapIntegerElements(int array[], int p1, int p2);

//  Function: sortIntegerArray
//  ----------------------------
//  This implementtation uses an algorithm called selection sort,
//  which can be described in English as follows.   With your left
//  hand, point at each element in the array in turn, starting at
//  index 0.    At each step in the cycle:
//
//  (1) Find the smallest element in the range between your left
//      hand and the end of the array, and point at that element
//      with your right hand.
//
//  (2) Move that element into its correct index position by
//      switching the elements indicated by your left and right
//      hands.

void sortIntegerArray(int array[], int n) {
    int lh, rh;
    
    for (lh = 0; lh < n; lh++) {
        rh = findSamllestInteger(array, lh, n-1);
        swapIntegerElements(array, lh, rh);
    }
}

void sortAlphabetize(char *array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (strcmp(array[i], array[j]) > 0) {
                char *tmp;
                
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

//  Function: findSamllestInteger
//  Usage: index = findSmallestInteger
//  ---------------------------
//  This funcion returns the index of the smallest value in the
//  specified array of integers, searching only between the index
//  positions low and high, inclusive.  It operates by keeping track
//  of the index of the smallest so far in the variable spos.   If the
//  index range is empty, the function returns low.

static int findSamllestInteger(int array[], int low, int high) {
    int i, spos;
    
    spos = low;
    for (i = low; i <= high; i++) {
        if (array[i] < array[spos]) spos = i;
    }
    return (spos);
}

//  Function: swapIntegerElements
//  Usage: swapIntegerElements(array, p1, p2);
//  ------------------------------
//  This funcion swaps the elements in array at index
//  positions p1 and p2.

static void swapIntegerElements(int array[], int p1, int p2) {
    int tmp;
    
    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}


                