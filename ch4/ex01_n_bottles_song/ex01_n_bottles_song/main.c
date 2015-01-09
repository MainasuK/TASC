//
//  main.c
//  ex01_n_bottles_song
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define N 99

//  This program print a song again and again
int main(int argc, const char * argv[]) {
    for (int i = N; i >= 0; i--) {
        printf("%d bottles of beer on the wall.\n", i);
        printf("%d bottles of beer.\n", i);
        printf("You take one down, pass it around\n");
    }
    return 0;
}
