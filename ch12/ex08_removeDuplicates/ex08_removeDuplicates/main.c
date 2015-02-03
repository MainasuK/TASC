//
//  main.c
//  ex08_removeDuplicates
//
//  Created by Cirno MainasuK on 2015-2-3.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "removeDuplicates.h"

int main(int argc, const char * argv[]) {
    int scores[] = {65, 72, 75, 79, 82, 82, 84, 84, 84, 86, 90, 94, 95};
    int nScores = sizeof(scores)/sizeof(scores[0]);
    
    int len = removeDuplicates(scores, nScores);
    printf("Len is %d.\n", len);
    return 0;
}
