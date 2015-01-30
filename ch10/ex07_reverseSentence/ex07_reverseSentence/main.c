//
//  main.c
//  ex07_reverseSentence
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
//  Private funcion prototypes

static void reverseSentence(string line);
static bool IsLegalWord(string token);


//  Main program

int main() {
    string line;
    
    printf("Enter a line: ");
    line = GetLine();
    reverseSentence(line);
}

static void reverseSentence(string line) {
    string token;

    InitEndScanner(line);
    while (!AtStartOfLine()) {
        token = GetPreviousToken();
        if (IsLegalWord(token)) {
            printf("%s ", token);
        }
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

