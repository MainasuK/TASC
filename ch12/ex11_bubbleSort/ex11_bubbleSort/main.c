//
//  main.c
//  ex11_bubbleSort
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "bubbleSort.h"


int main(int argc, const char * argv[]) {
    int s[] = {13, 42, 14, 63, 35, 76, 21, 45, 64, 14, 8, 69, 43};
    int n = sizeof(s)/sizeof(s[0]);
    bubbleSort(s, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    return 0;
}
