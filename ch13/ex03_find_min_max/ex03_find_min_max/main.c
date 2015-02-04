//
//  main.c
//  ex03_find_min_max
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

#define MAXLENS 100

static int getArray(double *array, int Limit);
static void getArrayRange(double *array, int len, int *min, int *max);

int main(int argc, const char * argv[]) {
    double array[MAXLENS];
    int len, min, max;
    
    len = getArray(array, MAXLENS);
    getArrayRange(array, len, &min, &max);
    printf("The range of values is %d-%d\n", min, max);
    return 0;
}


static int getArray(double *s, int Lim) {
    int i = 0;
    printf("Enter the elements of the array ,one per line.\n");
    printf("Use -1 to signal the end of the list.\n");
    for (i = 0; i < Lim; i++) {
        printf(" ? ");
        scanf("%lf", (s+i));
        if (*(s+i) == -1) {
            break;
        }
    }
    
    return (i);
}

static void getArrayRange(double *s, int len, int *min, int *max) {
    *min = *s;
    *max = *s;
    for (int i = 0; i < len; i++) {
        *min = (s[i] < *min) ? s[i] : *min;
        *max = (s[i] > *max) ? s[i] : *max;
    }
}