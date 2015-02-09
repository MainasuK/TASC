//
//  main.c
//  ex07_subString
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char *subString(char *s, int p1, int p2);

int main(int argc, const char * argv[]) {
    char a[] = "A brown fox jumps over the lazy dog";
    printf("%s\n", subString(a, 0, 10));
    return 0;
}


char *subString(char *s, int p1, int p2) {
    char *p;
    int len = p2 - p1;
    
    p1 = (p1 < 0) ? 0 : p1;
    p2 = (p2 > strlen(s)) ? strlen(s)-1 : p2;
    if (len < 0) {
        p = malloc(sizeof(char));
        *p = '\0';
        return p;
    } else {
        p = malloc(sizeof(len+1));
        int i;
        for (i = 0; i < len; i++) {
            *(p+i) = *(s+p1+i);
        }
        *(p+i) = '\0';
    }
    return p;
}