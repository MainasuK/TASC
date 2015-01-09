//
//  main.c
//  ex06_liftoff_v2
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define StartingCount 10

int main(int argc, const char * argv[]) {
    int t = StartingCount;
    do {
        printf("%2d\n", t);
    } while (t--);
    
    printf("Liftoff!\n");
    
    return 0;
}
