//
//  main.c
//  ex02_myStrlen_pointer
//
//  Created by Cirno MainasuK on 2015-2-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int myStrlen(char *src);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


int myStrlen(char *src) {
    int i = 0;
    while (*(src+i) != '\0') {
        i++;
    }
    
    return i;
}