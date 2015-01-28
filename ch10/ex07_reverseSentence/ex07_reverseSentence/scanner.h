//
//  scanner.h
//  10.3_pigLatin
//
//  Created by Cirno MainasuK on 2015-1-27.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This file is the interface to a package that divides
//  a line into individual "tokens". A token is defined
//  to be either
//
//  1. a string of consecutive letters and digits representing
//  a word, or
//
//  2. a one-character string representing a separator
//  character, such as a space or a punctuation mark.
//
//  To use this package, you must first call
//
//          InitScanner(line);
//  Where line is the string (typically a line returned by
//  GetLine) that is to be divided into tokens. To retrieve
//  each token in turn, you call
//
//          token = GetNextToken();
//
//  When the last token has been read, the predicate function
//  AtEndOfLine returns TRUE, so that the loop structure
//
//          while (!AtEndOfLine()) {
//              token = GetNextToken();
//              . . . process the token . . .
//          }
//
//  serves as an idiom for processing each token on the line.
//
//  Further details for each function are given in the
//  individual descriptions below.

#ifndef ___0_3_pigLatin__scanner__
#define ___0_3_pigLatin__scanner__

#include "genlib.h"

//  Function: InitScanner
//  Usage: InitScanner(line);
//  ------------------------------
//  This function initializes the scanner and sets it up so that
//  it reads tokens from line.  After InitScanner has been called,
//  the first call to GetNextToken will return the first token
//  on the line, the next call will return the second token,
//  and so on.

void InitScanner(string line);
void InitEndScanner(string line);

//  Function: GetNextToken
//  Usage: word = GetNextToken();
//  ------------------------------
//  This function returns the next token on the line.

string GetNextToken(void);

string GetPreviousToken(void);

//  Function: AtEndOfLine
//  Usage: if (AtEndOfLine()) . . .
//  -----------------------------
//  This function returns TRUE when the scanner has reached
//  the end of the line.

bool AtEndOfLine(void);


bool AtStartOfLine(void);

#endif /* defined(___0_3_pigLatin__scanner__) */
