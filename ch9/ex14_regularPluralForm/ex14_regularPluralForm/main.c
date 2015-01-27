//
//  main.c
//  ex14_regularPluralForm
//
//  Created by Cirno MainasuK on 2015-1-27.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define STRLENS 100

typedef enum {
    FALSE, TRUE
} bool;

bool isConsonat(char ch);
void regularPluarlForm(char *s);

int main(int argc, const char * argv[]) {
    char str[STRLENS] = "test";
    regularPluarlForm(str);
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

void regularPluarlForm(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    i--;
    switch (s[i]) {
        case 'h':
            if (s[i-1] == 'c' || s[i-1] == 's') {
                ;
            } else {
                s[++i] = 's';
                break;
            }
        case 's':   case 'x':   case 'z':
            s[++i] = 'e';
            s[++i] = 's';
            s[++i] = '\0';
            break;
        case 'y':
            if (isConsonant(s[i-1])) {
                s[i] = 'i';
                s[++i] = 'e';
                s[++i] = 's';
                break;
            } else {
                s[++i] = 's';
                break;
            }
        default:
            s[++i] = 's';
            break;
    }
    s[++i] = '\0';
    
    printf("%s\n", s);
}