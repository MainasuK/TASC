//
//  main.c
//  ex06_longestWord
//
//  Created by Cirno MainasuK on 2015-1-28.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

#define MAXLENS 100

static void longestWord(string line, char *longest);
static bool IsLegalWord(string token);

int main() {
    string line;
    char longest[MAXLENS];
    printf("Enter a line: ");
    line = GetLine();
    longestWord(line, longest);
    printf("The longest word is \"%s\"\n", longest);
}


static void longestWord(string line, char *longest) {
    string token;
    unsigned long len = 0;
    InitScanner(line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        if (IsLegalWord(token)) {
            if (strlen(token) > len) {
                len = strlen(token);
                strcpy(longest, token);
            }
        }
    }
}

static bool IsLegalWord(string token) {
    int i;
    
    for (i = 0; i < StringLength(token); i++) {
        if (!isalpha(IthChar(token, i))) return (FALSE);
    }
    return (TRUE);
}
