//
//  main.c
//  ex12_myFindString
//
//  Created by Cirno MainasuK on 2015-1-27.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

typedef enum {
    FALSE, TRUE
} bool;

int myFindString(char *str, char *find);

int main(int argc, const char * argv[]) {
    printf("%s\n", (myFindString("isTRUE?", "TRUE")) ? "TRUE" : "FALSE");
    return 0;
}

int myFindString(char *str, char *find) {
    int mark = 0;
    int p = 1;
    int flag = 0;
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] != find[j]) {
            i++;
        } else {
            if (p) {
                mark = i - j;
                p = 0;
            }
            i++;
            j++;
        }
        if (find[j] == '\0' && mark == i-j) {
            flag = 1;
        }
    }
    return (flag) ? TRUE : FALSE;
}