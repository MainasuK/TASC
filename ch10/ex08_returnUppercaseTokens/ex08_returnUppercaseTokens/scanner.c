//
//  scanner.c
//  10.3_pigLatin
//
//  Created by Cirno MainasuK on 2015-1-27.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "scanner.h"

//  Private variables
//  ------------------------------
//  buffer      -- Private copy of the string passed to InitScanner
//  buflen      -- Length of the buffer, saved for efficiency
//  cpos        -- Current character position in the buffer

static string buffer;
static int  buflen;
static int  cpos;

//  Function: initScanner
//  ------------------------------
//  All this function has to do is initialize the private
//  variables used in the package.

void InitScanner(string line) {
    if (UppercaseFlag)
        buffer = ConvertToUpperCase(line);
    else
        buffer = line;
    buflen = StringLength(buffer);
    cpos = 0;
}

//  Function: getNextToken
//  -----------------------------
//  The implementation of getNextToken follows its behavioral
//  description as given in the interface: if the next character
//  is alphanumeric (i.e., a letter or digit), the function
//  searches to find an unbroken string of such characters and
//  returns the entire string.  If the current character is not
//  a letter or digit, a one-character string containing that
//  character is returned.

string GetNextToken(void) {
    char ch;
    int start;
    
    if (cpos >= buflen) Error("No more tokens");
    ch = IthChar(buffer, cpos);
    if (isalnum(ch)) {
        start = cpos;
        while (cpos < buflen && isalnum(IthChar(buffer, cpos))) {
            cpos++;
        }
        return (SubString(buffer, start, cpos- 1 ));
    } else {
        cpos++;
        return (CharToString(ch));
    }
}

//  Function: AtEndOfLine
//  ---------------------------
//  This implementation compares the current buffer position
//  against the saved length.

bool AtEndOfLine(void) {
    return (cpos >= buflen);
}

#undef MAXLENS