//
//  sortFlag.c
//  ex10_Flag_of_the_Netherlands
//
//  Created by Cirno MainasuK on 2015-2-3.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "sortFlag.h"

static int leftmostNotR(char *array, int n);
static int rightmostNotB(char *array, int n);
static int leftmostW(char *array, int n);
static int rightmostW(char *array, int n);
static void swapChar(char *array, int p1, int p2);
static void printLog(char *array, int n, int lh, int rh);

void sortFlag(char *array, int n) {
    int lh, rh;
    int w, flag = 0;
    lh = leftmostNotR(array, n);    //  标记左端非 R 位
    rh = rightmostNotB(array, n);   //  标记右端非 B 位
    
    while (1) {
        
        
        if (array[lh] == 'B' || array[rh] == 'R') {   //  左端为 B，或右端为 R 时
            swapChar(array, lh, rh);    //  交换 lh 与 rh
        } else {                                      //  两端为 W 时
            for (w = 0; w < rh; w++) {  //  交换 W 与其右侧的 B
                if (array[lh] != array[lh+w] && array[lh+w] != 'B') {
                    swapChar(array, lh, lh+w);
                    break;
                }
            }
        }
        
        if (lh != leftmostNotR(array, n))
            lh++;
        if (rh != rightmostNotB(array, n))
            rh--;
//        printLog(array, n, lh, rh);
        for (int i = leftmostW(array, n); i < rightmostW(array, n); i++) {
            int leftmost, rightmost;
            leftmost = leftmostW(array, n);
            rightmost = rightmostW(array, n);
            
            if (array[i] != 'W') {
                flag = 0;
                break;
            }
            
            if (lh == leftmost && rh == rightmost) {
                flag = 1;
            }
        }
        
            if (flag)
                goto end;
    }
end:
    ;
}


static int leftmostNotR(char *array, int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] != 'R') {
            return i;
        }
    }
    return -1;
}

static int rightmostNotB(char *array, int n) {
    for (int i = n-1; i >= 0; i--) {
        if (array[i] != 'B') {
            return i;
        }
    }
    return -1;
}

static int leftmostW(char *array, int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] == 'W') {
            return i;
        }
    }
    return -1;
}

static int rightmostW(char *array, int n) {
    for (int i = n-1; i >= 0; i--) {
        if (array[i] == 'W') {
            return i;
        }
    }
    return -1;
}

static void swapChar(char *array, int p1, int p2) {
    char tmp;
    
    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}

static void printLog(char *array, int n, int lh, int rh) {
    for (int i = 0; i < 15; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
//    printf("[%d %d]\n", lh, rh);
}