//
//  main.c
//  ex08_cyclic_cipher
//
//  Created by Cirno MainasuK on 2015-1-26.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>


char cyclicCipher(char ch, int i);


int main(int argc, const char * argv[]) {
    int k;
    char c;
    printf("This program encodes a message using a yclic cipher.\n");
    printf("Ener the numeric key: ");
    scanf("%d%*c", &k);
    printf("Enter a message: ");
    while ((c=getchar()) != '\n') {
        static int flag = 1;
        if (flag) {
            printf("Encoded message: ");
            flag = 0;
        }
        putchar(cyclicCipher(c, k));
    }
    printf("\n");
    return 0;
}

char cyclicCipher(char ch, int i) {
    if (ch >= 'a' && ch <= 'z') {
        ch += i;
        if (ch < 'a') {
            ch = ch + 'z' - 'a';
        } else if (ch > 'z') {
            ch = ch - 'z' - 'a';
        }
    } else if (ch >= 'A' && ch <= 'Z') {
        ch += i;
        if (ch < 'A') {
            ch = ch + 'Z' - 'A';
        } else if (ch > 'Z') {
            ch = ch - 'Z' - 'A';
        }
    }
    return ch;
}