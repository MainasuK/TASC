//
//  main.c
//  ex03_isConsonant
//
//  Created by Cirno MainasuK on 2015-1-25.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>


typedef enum {
    FALSE = 0,
    TRUE  = 1
} bool;

bool isConsonant(char ch);


int main(int argc, const char * argv[]) {
    printf("The English consonants are:\n");
    for (char i = 'A'; i <= 'Z'; i++) {
        if (isConsonant(i))
            printf("%c ", i);
    }
    return 0;
}

bool isConsonant(char ch) {
    if (tolower(ch) >= 'a' && tolower(ch) <= 'z') {
        switch (tolower(ch)) {
            case 'a':   case 'e':   case 'i':   case 'o':   case 'u':
                return (FALSE);
                break;
                
            default:
                return (TRUE);
                break;
        }

    } else {
        return FALSE;
    }
}
