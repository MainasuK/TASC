//
//  main.c
//  ex13_replaceAll
//
//  Created by Cirno MainasuK on 2015-1-27.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

#define STRLENS 100

void replaceAll(char *str, char s, char d);

int main(int argc, const char * argv[]) {
    char string[STRLENS] = "Beebee";
    replaceAll(string, 'e', 'o');
    return 0;
}

void replaceAll(char *str, char s, char d) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == s) {
            str[i] = d;
        }
        i++;
    }
    printf("%s\n", str);
}