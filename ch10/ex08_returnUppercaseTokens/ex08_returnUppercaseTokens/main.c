//
//  main.c
//  ex08_returnUppercaseTokens
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

//  Private funcion prototypes

static void returnUppercaseTokens(string line);
static bool IsLegalWord(string token);


//  Main program

int main() {
    string line;
    
    printf("Enter a line: ");
    line = GetLine();
    returnUppercaseTokens(line);
}

//  Function: TranslateLine
//  Usage: TranslateLine(line);
//  -----------------------------
//  This function takes a line of text and translates
//  the words in the line to Pig Latin, displaying the
//  translation as it goes.

static void returnUppercaseTokens(string line) {
    string token;
    printf("The tokens are: \n");
    InitScanner(line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        if (IsLegalWord(token))
            printf("%s\n", token);
    }
    printf("\n");
}

//  Function: IsLegalWord
//  Usage: if (IsLegalWord(token)) . . .
//  -----------------------------
//  IsLegalWord returns TRUE if every character in the argument
//  token is alphabetic.

static bool IsLegalWord(string token) {
    int i;
    
    for (i = 0; i < StringLength(token); i++) {
        if (!isalpha(IthChar(token, i))) return (FALSE);
    }
    return (TRUE);
}

