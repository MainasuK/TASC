//
//  main.c
//  ex09_randomSort
//
//  Created by Cirno MainasuK on 2015-2-3.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "shuffle.h"


#define NUMS 52

int main(int argc, const char * argv[]) {
    int table[NUMS];
    for (int i = 0; i < NUMS; i++) {
        table[i] = i+1;
    }
    
    shuffleSort(table, NUMS);
    for (int i = 0; i < NUMS; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
    
    return 0;
}
