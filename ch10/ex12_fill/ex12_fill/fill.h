//
//  fill.h
//  ex12_fill
//
//  Created by Cirno MainasuK on 2015-1-29.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __ex12_fill__fill__
#define __ex12_fill__fill__

#include "scanner.h"

//  Function: setFillMargin
//  Usage: setFillMargin(margin);
//  ------------------------------
//  This function sets the fill margin to the value given by the
//  margin parameter.   When strings are displayed using the
//  function PrintFilledString, the output will be broken up
//  into separate lines so that no lines extend past the margin.
//  If no margin is set explicitly, the package uses 65 for the
//  fill margin as a default.

void setFillMargin(int margin);

//  Function: printFilledString
//  Usage: printFilledString(str);
//  -----------------------------
//  The string str is displayed on the screen, starting from
//  where the last string left off. Spaces and newline characters
//  in the string are treated specially.    If a space character
//  appears in an argument, the function may choose to divide
//  the string at that point by moving to the next line.
//  Such division occurs when the next word would not fit
//  within the margin established by setFilMargin.  A newlin
//  character in the string forces the cursor to advance to the
//  beginning of the next line.

void printFilledString(char *str);

#endif /* defined(__ex12_fill__fill__) */
