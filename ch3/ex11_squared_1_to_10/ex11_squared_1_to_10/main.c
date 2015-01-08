//
//  main.c
//  ex11_squared_1_to_10
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define START 1
#define END 10

int main(int argc, const char * argv[]) {
    printf("%-10s%-10s%-10s\n", "Number", "Square", "Cube");
    for (int i = START; i < END+1; i++) {
        printf("%-10d%-10d%-10d\n", i, (int)pow(i, 2), (int)pow(i, 3));
    }
    return 0;
}
