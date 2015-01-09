//
//  main.c
//  ex04_sixes_sevens_number
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

//  This program print number which can be divided by 6 or 7 from 1 to 100
int main(int argc, const char * argv[]) {
    for (int i = 0; i < 100; i++) {
        if ((i%6 == 0) || (i%7 == 0)) {
            if (i >= 6) {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
