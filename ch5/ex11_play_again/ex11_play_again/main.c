//
//  main.c
//  ex11_play_again
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program ask player if play again
//  anwser must be yes or no, not others

#include <stdio.h>
#include <string.h>

#define TURE  1
#define FALSE 0
#define MAXLENS 1000
int GetYesOrNo(void);
void playOneGame(void);

int main(int argc, const char * argv[]) {
    while (TURE) {
        playOneGame();
        if (!GetYesOrNo()) break;
    }
    
    return 0;
}

void playOneGame(void) {
    printf(". . . play the game\n");
}

int GetYesOrNo(void) {
    char a[MAXLENS];
    
    while (TURE) {
        printf("Would you like to play again? ");
        gets(a);
        
        if (strcmp(a, "yes") == 0) {
            return 1;
        } else if (strcmp(a, "no") == 0) {
            return 0;
        } else {
            printf("please answer yes or no.\n");
            continue;
        }
    }
}