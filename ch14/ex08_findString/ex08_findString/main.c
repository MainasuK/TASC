//
//  main.c
//  ex08_findString
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int findString(char *s, char *text, int start);

int main(int argc, const char * argv[]) {
    char a[] = "A brown fox jumps over the lazy dog.";
    char b[] = "lazy";
    printf("%d\n", findString(a, b, 0));
    return 0;
}

int findString(char *s, char *text, int start) {
    if (start < 0 || start > strlen(s)) return (-1);
    
    for (int i = start; i < strlen(s); i++) {
        if (s[i] == text[0]) {
            int j;
            for (j = 0; j < strlen(text); j++) {
                if (s[i+j] != text[j]) {
                    break;
                }
            }
            if (j == strlen(text)) {
                return i;
            }
        }
    }
    
    return (-1);
}