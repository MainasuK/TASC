//
//  main.c
//  ex03_isSorted
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

typedef enum {
    FALSE, TRUE
} bool;


static bool isSorted(int *array, int n) {
    for (int i = 1; i < n; ++i) {
        if (array[i] - array[i-1] < 0)
            return FALSE;
    }
    return TRUE;
}

int main(int argc, const char * argv[]) {
    int a[] = {0, -1, 2, 3, 4, 5, 6, 7};
    int nArray = sizeof(a)/sizeof(*a);
    printf("%s\n", isSorted(a, nArray) ? "Yes" : "No");
    return 0;
}
