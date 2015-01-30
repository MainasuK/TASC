//
//  main.c
//  ex05_word_count
//
//  Created by Cirno MainasuK on 2015-1-28.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "scanner.h"


static int wordCount(string line);
static bool IsLegalWord(string token);

int main() {
    string line;
    
    printf("Enter a line: ");
    line = GetLine();
    printf("Number of words: %d\n", wordCount(line));
}


static int wordCount(string line) {
    string token;
    int count;
    count = 0;
    
    InitScanner(line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        if (IsLegalWord(token))
            count++;
    }
    return count;
}

static bool IsLegalWord(string token) {
    int i;
    
    for (i = 0; i < StringLength(token); i++) {
        if (!isalpha(IthChar(token, i))) return (FALSE);
    }
    return (TRUE);
}
