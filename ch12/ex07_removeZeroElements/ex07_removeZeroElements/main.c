//
//  main.c
//  ex07_removeZeroElements
//
//  Created by Cirno MainasuK on 2015-2-2.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "removeZeroElements.h"

int main(int argc, const char * argv[]) {
    int scores[] = {65, 0, 95, 0, 0, 79, 82, 0, 84, 94, 86, 90, 0};
    int nScores = sizeof(scores)/sizeof(scores[0]);
    int leftNScores = removeZeroElements(scores, nScores);
    printf("Scores table is :\n");
    for (int i = 0; i < leftNScores; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
    printf("nScores is %d.\n", leftNScores);
    return 0;
}
