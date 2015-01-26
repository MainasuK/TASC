//
//  main.c
//  ex09_palindrome
//
//  Created by Cirno MainasuK on 2015-1-26.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define STRLENS 100

typedef enum {
    FALSE, TRUE
} bool;

bool isPalindrome(char *str);


int main(int argc, const char * argv[]) {
    char str[STRLENS];
    char c;
    int i = 0;
    while ((c=getchar()) != '\n') {
        str[i] = c;
        i++;
    }
    str[i] = '\n';
    
    printf("%s", isPalindrome(str) ? "TRUE\n" : "FALSE\n");
    return 0;
}


bool isPalindrome(char *str) {
    int i = 0;
    int flag = 1;
    int mid;
    while (str[i] != '\n') {
        i++;
    }
    
    mid = i / 2;
    
    for (int j = 0; j < mid; j++) {
        if (str[j] != str[i-1]) {
            flag = 0;
        }
        j++;
        i--;
    }
    
    return (flag) ? TRUE : FALSE;
}