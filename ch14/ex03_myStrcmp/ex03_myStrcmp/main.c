//
//  main.c
//  ex03_myStrcmp
//
//  Created by Cirno MainasuK on 2015-2-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int myStrcmpI(char *s1, char *s2);
int myStrcmpII(char *s1, char *s2);


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


int myStrcmpI(char *s1, char *s2) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') {
            return (0);
        } else {
            i++;
        }
    }
    return (s1[i] - s2[i]);
}

int myStrcmpII(char *s1, char *s2) {
    while (*s1 == *s2) {
        if (*s1) {
            return (0);
        } else {
            s1++;
            s2++;
        }
    }
    return (*s1 - *s2);
}