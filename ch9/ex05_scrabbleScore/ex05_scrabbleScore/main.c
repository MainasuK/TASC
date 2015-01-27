//
//  main.c
//  ex05_scrabbleScore
//
//  Created by Cirno MainasuK on 2015-1-25.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define STRLENS 100

int getScore(char ch);
void scrabbleScore(void);

int main(int argc, const char * argv[]) {
    scrabbleScore();
    return 0;
}


int getScore(char ch) {
    switch (ch) {
        case 'A':   case 'E':   case 'I':   case 'L':
        case 'N':   case 'O':   case 'R':   case 'S':
        case 'T':   case 'U':
            return 1;
            break;
        case 'D':   case 'G':
            return 2;
            break;
        case 'B':   case 'C':   case 'M':   case 'P':
            return 3;
            break;
        case 'F':   case 'H':   case 'V':   case 'W':
        case 'Y':
            return 4;
            break;
        case 'K':
            return 5;
            break;
        case 'J':   case 'X':
            return 8;
            break;
        case 'Q':   case 'Z':
            return 10;
            break;
            
        default:
            return 0;
            break;
    }
}

void scrabbleScore(void) {
    int c, score;
    char str[STRLENS];
    printf("This program tests the ScrabbleScore function.\n");
    printf("Enter words, ending with a blank line.\n");
    while (1) {
        int i = 0;
        score = 0;
        printf("Word: ");
        while ((c=getchar()) != '\n') {
            score += getScore(c);
            str[i] = c;
            i++;
        }
        str[i] = '\0';
        if (str[0] == '\0')
            break;
        printf("The basic score for '%s' is %d.\n", str, score);
    }
}
