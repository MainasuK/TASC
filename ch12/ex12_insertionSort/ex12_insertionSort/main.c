//
//  main.c
//  ex12_insertionSort
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "insertionSort.h"

int main(int argc, const char * argv[]) {
    int a[] = {31, 41, 59, 26, 53, 58, 97, 93};
    int n = sizeof(a)/sizeof(a[0]);

    insertionSort(a, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
