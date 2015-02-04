//
//  main.c
//  ex05_indexArray
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

static void *indexArray(int n);

int main(int argc, const char * argv[]) {
    int *ip;
    
    ip = indexArray(10);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ip+i));
    }
    printf("\n");
    return 0;
}


static void *indexArray(int n) {
    int *p;
    p = (int *)malloc(n);
    
    if (p == NULL)
        exit(-1);
    
    return p;
}

