//
//  main.c
//  ex05_reverseString
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void reverseString(char *src);
void swap(char *s, int lh, int rh);

int main(int argc, const char * argv[]) {
    char a[] = "ABCDE";
    reverseString(a);
    printf("%s\n", a);
    
    return 0;
}

void reverseString(char *s) {
    int len = strlen(s);
    int lh = 0;
    int rh = len - 1;
    while (lh < rh) {
        swap(s, lh, rh);
        lh++;
        rh--;
    }
}

void swap(char *s, int lh, int rh) {
    char tmp;
    
    tmp = s[lh];
    s[lh] = s[rh];
    s[rh] = tmp;
}