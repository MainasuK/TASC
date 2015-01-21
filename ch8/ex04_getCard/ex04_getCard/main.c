//
//  main.c
//  ex04_getCard
//
//  Created by Cirno MainasuK on 2015-1-21.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "random.h"

void getCard(void);

int main(int argc, const char * argv[]) {
    getCard();
    return 0;
}


void getCard(void) {
    int c;
    char cardNumber[20];
    char *suits;
    
    randomize();

    switch (randomInteger(1, 4)) {
        case 1:
            suits = "clubs";
            break;
        case 2:
            suits = "diamonds";
            break;
        case 3:
            suits = "hearts";
            break;
        case 4:
            suits = "spades";
            break;
            
        default:
            break;
    }
    
    switch (c = randomInteger(1, 13)) {
        case 1:
            strcpy(cardNumber, "A");
            break;
        case 11:
            strcpy(cardNumber, "Jack");
            break;
        case 12:
            strcpy(cardNumber, "Queen");
            break;
        case 13:
            strcpy(cardNumber, "King");
            break;
            
        default:
            sprintf(cardNumber, "%d", c);
            break;
    }
    

    printf("%s of %s\n", cardNumber, suits);
}