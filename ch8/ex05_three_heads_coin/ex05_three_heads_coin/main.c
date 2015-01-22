//
//  main.c
//  ex05_three_heads_coin
//
//  Created by Cirno MainasuK on 2015-1-22.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "random.h"

#define NTRIALS 3
void threeHeads(void);

int main(int argc, const char * argv[]) {
    threeHeads();
    return 0;
}

void threeHeads(void) {
    int heads = 0;
    int loop = 0;
    int condition = 1;
    randomize();
    while (condition) {
        switch (randomChance(0.5)) {
            case 1:
                printf("heads\n");
                heads++;
                loop++;
                if (heads == NTRIALS) condition = 0;
                break;
            case 0:
                printf("tails\n");
                loop++;
                heads = 0;
                break;
        }
    }
    printf("It took %d flips to get heads 3 consecutive times.\n", loop);
}