//
//  main.c
//  ex04_randomWord
//
//  Created by Cirno MainasuK on 2015-1-25.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "random.h"

#define TIMES 5
#define MinLetters 2
#define MaxLetters 8
void randomWord(int times);


int main(int argc, const char * argv[]) {
    printf("This program generates %d random words.\n", TIMES);
    randomWord(TIMES);
    return 0;
}


void randomWord(int times) {
    int letterLenght;

    randomize();
    for (int i = 0; i < times; i++) {
        letterLenght = randomInteger(MinLetters, MaxLetters);
        for (int j = 0; j < letterLenght; j++) {
            printf("%c",randomInteger('A', 'Z'));
        }
        printf("\n");
    }
    
    
}