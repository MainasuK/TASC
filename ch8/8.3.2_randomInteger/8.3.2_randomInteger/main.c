//
//  main.c
//  8.3.2_randomInteger
//
//  Created by Cirno MainasuK on 2015-1-21.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program simulates rolling a die.

#include <stdio.h>
#include "random.h"

//  Constants
//  ----------------------------
//  NTrials -- number of trials

#define NTrials 10

//  Function prototypes
int rollDie(void);

//  Main program

int main(int argc, const char * argv[]) {
    int i;
    
    for (i = 0; i < NTrials; i++) {
        printf("%d\n", rollDie());
    }
    
    return 0;
}

//  Function: rollDie
//  Usage: die = rollDie();
//  ------------------------------
//  This funciton generates and returns a random integer in the
//  range 1 to 6, representing the roll of a six-sided die.
int rollDie(void) {
    return (randomInteger(1, 6));
}
