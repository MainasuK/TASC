//
//  morseCode.c
//  ex06_Morese
//
//  Created by Cirno MainasuK on 2015-1-31.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <string.h>
#include <ctype.h>
#include "morseCode.h"

static char *morseCode[] = {
    ".-",       //  A
    "-...",     //  B
    "-.-.",     //  C
    "-..",      //  D
    ".",        //  E
    "..-.",     //  F
    "--.",      //  G
    "....",     //  H
    "..",       //  I
    ".---",     //  J
    "-.-",      //  K
    ".-..",     //  L
    "--",       //  M
    "-.",       //  N
    "---",      //  O
    ".--.",     //  P
    "--.-",     //  Q
    ".-.",      //  R
    "...",      //  S
    "-",        //  T
    "..-",      //  U
    "...-",     //  V
    ".--",      //  W
    "-..-",     //  X
    "-.--",     //  Y
    "--..",     //  Z
};

void morseCodeGenerator(void) {
    int c;
    printf("Enter English text: ");
    while ((c=getchar()) != '\n') {
        if (isspace(c)) {
            printf("\n");
            continue;
        }
        if (ispunct(c)) {
            continue;
        }
        
        printf("%s", morseCode[tolower(c)-'a']);
        printf(" ");
    }
    printf("\n");
}

