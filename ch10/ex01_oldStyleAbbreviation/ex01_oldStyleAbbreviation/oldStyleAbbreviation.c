//
//  oldStyleAbbreviation.c
//  ex01_oldStyleAbbreviation
//
//  Created by Cirno MainasuK on 2015-1-28.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "oldStyleAbbreviation.h"

#define MAXLENS 10

static bool isConsonant(char ch);

void getAddress(char *s) {
    int c;
    printf("Please input the address : ");
    while ((c=getchar()) != '\n') {
        *(s++) = c;
    }
    *s = '\0';
}

void oldStyleAbbreviation(char *s) {
    char lastCh, d[MAXLENS];
    unsigned long len;
    len = strlen(s);
    lastCh = s[len-1];
    
    if (!isConsonant(s[0])) {
        d[0] = s[0];
        d[1] = lastCh;
        d[2] = '.';
        d[3] = '\0';
    } else {
        d[0] = s[0];
        if (isConsonant(s[1])) {
            d[1] = s[1];
            d[2] = lastCh;
            d[3] = '.';
            d[4] = '\0';
        } else {
            d[1] = lastCh;
            d[2] = '.';
            d[3] = '\0';
        }
    }
    
    printf("%s\n", d);
}

static bool isConsonant(char ch) {
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
