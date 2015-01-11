//
//  main.c
//  ex13_Pascal
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program prints a Pascal triangle.

#include <stdio.h>
#include <math.h>

int getPascal(int line, int n);
void printPascal(int line);

int main(int argc, const char * argv[]) {
    int n;
    printf(" ? line : ");
    scanf("%d", &n);
    
    printPascal(n);
    return 0;
}

int getPascal(int line, int n) {
    if (line == 0 && n ==0) {
        return 1;
    } else if (n == 0) {
        return getPascal(line-1, 0);
    } else if (n == line) {
        return getPascal(line-1, n-1);
    } else {
        return getPascal(line-1, n) + getPascal(line-1, n-1);
    }
}

void printPascal(int line) {
    
    for (int i = 0, n = line; i < line; i++, n--) {
        for (int j = 2*n; j > 0; j--) {
            printf(" ");
        }
        for (int p = 0; p <= i; p++) {
            if (p > 1 &&  (getPascal(i, p-1) > pow(10, 2)) && (getPascal(i, p) > pow(10, 3))   )
                printf(" ");
            printf("%4d", getPascal(i, p));
                    }
        printf("\n");
    }
}