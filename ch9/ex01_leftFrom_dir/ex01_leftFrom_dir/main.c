//
//  main.c
//  ex01_leftFrom_dir
//
//  Created by Cirno MainasuK on 2015-1-25.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
typedef enum {
    North, East, South, West
} directionT;

void leftFrom(directionT dir);

int main(int argc, const char * argv[]) {
    printf("This program tests the leftFrom function.\n");
    for (int i = North; i <= West; i++) {
        leftFrom(i);
    }
    return 0;
}


void leftFrom(directionT dir) {
    switch (dir) {
        case North:
            printf("leftFrom(North) = West\n");
            break;
        case East:
            printf("leftFrom(East)  = North\n");
            break;
        case South:
            printf("leftFrom(South) = East\n");
            break;
        case West:
            printf("leftFrom(West)  = South\n");
            break;
            
        default:
            break;
    }
}