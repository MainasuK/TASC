//
//  mySizeof.c
//  ex08_mySizeof
//
//  Created by Cirno MainasuK on 2015-2-5.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <ctype.h>
#include "string.h"
#include "mySizeof.h"
#include "simpio.h"

#define NTypes 6

char *myType[NTypes] = {
    "char",
    "int",
    "short",
    "long",
    "float",
    "double",
    
};

long unsigned mySizeofTable[NTypes] = {
    sizeof(char),
    sizeof(int),
    sizeof(short),
    sizeof(long),
    sizeof(float),
    sizeof(double),
};

static bool isLegalToken(string token);
static int getMark(string token);

void mySizeof(void) {
    string line, token;
    printf("Enter variable declarations, ending with a blank line.\n");
    
    do {
        int mark = 0, flag = 1, index = 0;
        string brace;
        line = GetLine();
        InitScanner(line);
        
        while (!AtEndOfLine()) {
            if (flag) {
                mark = getMark(GetNextToken());
                flag = 0;
            }
            
            token = GetNextToken();
            if (isLegalToken(token)) {
//                printf("%s ", token);
                
                if (strcmp(token, "*") != 0) {
                    if (strcmp(brace = GetNextToken(), ",") == 0 || strcmp(brace, ";") == 0) {
                        printf("%s requires %lu byte%s\n",
                               token, mySizeofTable[mark],
                               (mySizeofTable[mark]>1) ? "s" : "");
                    } else if (strcmp(brace, "[") == 0) {
                        index = atoi(GetNextToken());
                        GetNextToken();
                        GetNextToken();
                        printf("%s requires %lu byte%s\n",
                               token, index*mySizeofTable[mark],
                               (index*mySizeofTable[mark]>1) ? "s" : "");
                    }
                }
                
                if (strcmp(token, "*") == 0) {
                    printf("%s requires %lu bytes\n",
                           GetNextToken(), sizeof(void *));
                }
            }
            
        }

        
    } while (line[0] != '\0');

}

static bool isLegalToken(string token) {
    int flag = 1;
    if (strcmp(token, ";") == 0 || strcmp(token, " ") == 0)
        flag = 0;
    return (flag) ? TRUE : FALSE;
}

static int getMark(string token) {
    for (int i = 0; i < NTypes; i++) {
        if (strcmp(token, myType[i]) == 0) {
            return i;
        }
    }
    return (-1);
}