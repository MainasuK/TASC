//
//  main.c
//  ex10_Flag_of_the_Netherlands
//
//  Created by Cirno MainasuK on 2015-2-3.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "sortFlag.h"

int main(int argc, const char * argv[]) {
    char a[15] = {'R', 'B', 'W', 'W', 'B',
                  'B', 'R', 'W', 'W', 'R',
                  'R', 'W', 'R', 'B', 'W'};
    sortFlag(a, 15);
    
    for (int i = 0; i < 15; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
    return 0;
}
