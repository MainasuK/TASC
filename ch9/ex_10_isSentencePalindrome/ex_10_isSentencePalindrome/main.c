//
//  main.c
//  ex_10_isSentencePalindrome
//
//  Created by Cirno MainasuK on 2015-1-26.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRLENS 100

typedef enum {
    FALSE, TRUE
} bool;

bool isPalindrome(char *str);


int main(int argc, const char * argv[]) {
    printf("This program checks for palindromes.\n");
    printf("Indicate the end of the input with a blank line.\n");
    char str[STRLENS];
    do {
        char c;
        int i = 0;
        printf("Enter a string: ");
        while ((c=getchar()) != '\n') {
            if (isalpha(c)) {
                str[i] = c;
                i++;
            }
        }
        str[i] = '\n';
        if (str[0] != '\n')
            printf("%s", isPalindrome(str) ? "That is a palindrome.\n" : "That is not a palindrome\n");
    } while (str[0] != '\n');
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
        if (tolower(str[j]) != tolower(str[i-1])) {
            flag = 0;
        }
        i--;
    }
    
    return (flag) ? TRUE : FALSE;
}