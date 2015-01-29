//
//  main.c
//  ex09_ignore_space
//
//  Created by Cirno MainasuK on 2015-1-29.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

//  Private funcion prototypes

static void putToken(string line);
static bool IsLegalWord(string token);


//  Main program

int main() {
    string line;
    
    printf("Enter a line: ");
    line = GetLine();
    putToken(line);
}


static void putToken(string line) {
    string token;
    
    InitScanner(line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        if (IsLegalWord(token))
            printf("%s", token);
    }
    printf("\n");
}

static bool IsLegalWord(string token) {
    int i;
    
    for (i = 0; i < StringLength(token); i++) {
        if (!isalpha(IthChar(token, i))) return (FALSE);
    }
    return (TRUE);
}
