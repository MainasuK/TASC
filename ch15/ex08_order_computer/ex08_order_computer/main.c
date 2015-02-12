//
//  main.c
//  ex08_order_computer
//
//  Created by Cirno MainasuK on 2015-2-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "order.h"

#define BUFFSIZE 100

typedef enum {
    FALSE, TRUE,
} bool;

static FILE *openUserFile(char *prompt, char *mode);

int main(int argc, const char * argv[]) {
    FILE *infile;
    
    infile = openUserFile("Order file: ", "r");
    myOrder(infile);
    return 0;
}

static FILE *openUserFile(char *prompt, char *mode) {
    char *filename;
    FILE *result;
    
    while (TRUE) {
        printf("%s", prompt);
        filename = malloc(BUFFSIZE);
        scanf("%s", filename);
        result = fopen(filename, mode);
        if (result != NULL) break;
        printf("Can't open the file \"%s\"\n", filename);
    }
    return (result);
}