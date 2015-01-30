//
//  main.c
//  ex10_calc
//
//  Created by Cirno MainasuK on 2015-1-29.
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

static void calculator(string line);
static bool IsLegalWord(string token);

//  Main program

int main() {
    string line;
    
    printf("This program implements a simple calculator.\n");
    printf("When the > prompt apperars, enter an expression\n");
    printf("consisting of integer constants and the operators\n");
    printf("+, -, *, /, and %%,To stop, enter a blank line.\n");
    do {
    printf("> ");
    line = GetLine();
    calculator(line);
    } while (line[0] != '\0');
}


static void calculator(string line) {
    string token;
    enum {
        plus, minus, multiply, divide, modulo
    };
    int mark = plus;
    int sum = 0;
    int flag = 1;

    
    InitScanner(line);
    while (!AtEndOfLine()) {
        token = GetNextToken();
        if (IsLegalWord(token)) {
            if (flag) {
                switch (mark) {
                    case plus:
                        sum += atoi(token);
                        break;
                    case minus:
                        sum -= atoi(token);
                        break;
                    case multiply:
                        sum *= atoi(token);
                        break;
                    case divide:
                        sum /= atoi(token);
                        break;
                    case modulo:
                        sum %= atoi(token);
                        break;
                    default:
                        Error("Illegal input\n");
                        break;
                }
                flag = 0;
            } else {
                if (StringEqual(token, "+")) {
                    mark = plus;
                } else if (StringEqual(token, "-")) {
                    mark = minus;
                } else if (StringEqual(token, "*")) {
                    mark = multiply;
                } else if (StringEqual(token, "/")) {
                    mark = divide;
                } else if (StringEqual(token, "%")) {
                    mark = modulo;
                }
                flag = 1;
            }
        }
    }
    printf("%d\n", sum);
}


static bool IsLegalWord(string token) {

    if (StringEqual(token, " "))
        return (FALSE);
    return (TRUE);
}
