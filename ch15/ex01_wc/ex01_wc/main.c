//
//  main.c
//  ex01_wc
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "wc.h"

#define MAXLENS 1000
typedef enum {
    FALSE, TRUE,
} bool;

static FILE *openUserFile(char *prompt, char *mode);


int main(int argc, const char * argv[]) {
    FILE *infile = NULL;
    int nLines, nWords, nChars;
    infile = openUserFile("File: ", "r");
    wordCounter(infile, &nLines, &nWords, &nChars);
    printf("Lines:%6d\n", nLines);
    printf("Words:%6d\n", nWords);
    printf("Chars:%6d\n", nChars);
    fclose(infile);
    
    
    return 0;
}


static FILE *openUserFile(char *prompt, char *mode) {
    char *fileName;
    FILE *result;
    fileName = malloc(MAXLENS);
    while (TRUE) {
        printf("%s", prompt);
        scanf("%s", fileName);
        result = fopen(fileName, mode);
        if (result != NULL) break;
        printf("Can't open the file \"%s\"\n", fileName);
    }
    return (result);
}