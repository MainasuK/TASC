//
//  main.c
//  ex07_half_life
//
//  Created by Cirno MainasuK on 2015-1-22.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "random.h"

#define ATOMS 10000
#define YEAR  13
int halfLife(int year, int atoms);

int main(int argc, const char * argv[]) {
    printf("Year      Atoms left\n");
    printf("-----     -----------\n");
    for (int i = 0; i < YEAR + 1; i++) {
        printf("%4d       %8d\n", i, halfLife(i, ATOMS));
    }
    return 0;
}

int halfLife(int year, int atoms) {
    int remains = atoms;
    randomize();
    for (int j = 0; j < year+1; j++) {
        remains = atoms;
        for (int i = 0; i < remains; i++) {
            if (randomChance(0.5))
                atoms--;
        }

    }
    return remains;
}