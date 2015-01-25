//
//  main.c
//  ex.07_equalIgnoringCase
//
//  Created by Cirno MainasuK on 2015-1-25.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define STRLENS 100

typedef enum {
    FALSE, TRUE
} bool;


bool equalIgnoringCase(char *, char *);

int main(int argc, const char * argv[]) {
    char str1[STRLENS] = "CAT";
    char str2[STRLENS] = "cat";
    (equalIgnoringCase(str1, str2)) ? printf("TRUE\n") : printf("FALSE\n");
    return 0;
}

bool equalIgnoringCase(char *s1, char *s2) {
    int flag = 1;
    while (*s1 != '\0' && *s2 != '\0' && flag) {
        if (tolower(*s1) == tolower(*s2)) {
            ;
        } else {
            flag = 0;
        }
        s1++;
        s2++;
    }
    
    return (flag) ? TRUE : FALSE;
}