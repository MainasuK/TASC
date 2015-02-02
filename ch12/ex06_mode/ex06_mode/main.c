//
//  main.c
//  ex06_mode
//
//  Created by Cirno MainasuK on 2015-2-2.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "mode.h"


int main(int argc, const char * argv[]) {
    int array[] = {65, 84, 95, 75, 82, 79, 82, 72, 84, 94, 86, 90, 84};
    int nArray = sizeof(array)/sizeof(array[0]);
    printf("Mode is %d.\n", mode(array, nArray));
    return 0;
}
