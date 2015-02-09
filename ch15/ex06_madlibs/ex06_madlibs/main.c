//
//  main.c
//  ex06_madlibs
//
//  Created by Cirno MainasuK on 2015-2-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "madlibs.h"

#define BUFFSIZE 100

typedef enum {
    FALSE, TRUE,
} bool;

static FILE *openUserFile(char *prompt, char *mode);
void readWord(char **verb, char **sameVerb,
              char **adjective, char **pluraNoun);

int main(int argc, const char * argv[]) {
    char *verb, *sameVerb, *adjective, *pluralNoun;
    FILE *infile;
    
    infile = openUserFile("Input File: ", "r");
    readWord(&verb, &sameVerb, &adjective, &pluralNoun);
    outputMadlibs(infile, verb, sameVerb, adjective, pluralNoun);
    
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

void readWord(char **verb, char **sameVerb,
              char **adjective, char **pluraNoun) {
    char buf[BUFFSIZE], contorlString[BUFFSIZE];
    int len;
    sprintf(contorlString, "%%%ds", BUFFSIZE);
    
    printf("\tverb: ");
    scanf(contorlString, buf);
    len = strlen(buf);
    *verb = malloc(len+1);
    strcpy(*verb, buf);
    
    printf("\tsame verb: ");
    scanf(contorlString, buf);
    len = strlen(buf);
    *sameVerb = malloc(len+1);
    strcpy(*sameVerb, buf);
    
    printf("\tadjective: ");
    scanf(contorlString, buf);
    len = strlen(buf);
    *adjective = malloc(len+1);
    strcpy(*adjective, buf);
    
    printf("\tplural noun: ");
    scanf(contorlString, buf);
    len = strlen(buf);
    *pluraNoun = malloc(len+1);
    strcpy(*pluraNoun, buf);
}