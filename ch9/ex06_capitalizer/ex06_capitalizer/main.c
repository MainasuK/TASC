//
//  main.c
//  ex06_capitalizer
//
//  Created by Cirno MainasuK on 2015-1-25.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define STRLENS 100

void capitalizer(char *);

int main(int argc, const char * argv[]) {
    char str[STRLENS] = "BOOLEAN";
    capitalizer(str);
    return 0;
}

void capitalizer(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (i != 0) {
            str[i] = tolower(str[i]);
            i++;
        } else {
            str[i] = toupper(str[i]);
            i++;
        }
    }
    printf("%s\n", str);
}