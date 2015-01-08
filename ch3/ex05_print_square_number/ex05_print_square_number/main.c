//
//  main.c
//  ex05_print_square_number
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define START 1
#define END 10

int main(int argc, const char * argv[]) {
    for (int i = START; i <= END; i++) {
        printf("%d squared is %d\n", i, (int)pow(i, 2));
    }
    return 0;
}
