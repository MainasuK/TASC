//
//  main.c
//  ex08_math_quiz
//
//  Created by Cirno MainasuK on 2015-1-23.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "random.h"

#define TIMES 5

void questions(int times);

int main(int argc, const char * argv[]) {
    questions(TIMES);
    return 0;
}


void questions(int times) {
    randomize();
    int x, y, sum, answer, correct;
    int op;
    int ref, c;
    while (times) {
        x = randomInteger(1, 20);
        y = randomInteger(1, 20);
        op = randomChance(0.5);
        correct = 1;
        sum = (op) ? x+y : x-y;
        if (sum > 0 && sum < 20) {
            printf("What is %d %s %d? ", x, (op) ? "+" : "-", y);
            while (correct) {
                ref = scanf("%d", &answer);
                while ((c=getchar()) != '\n')
                    ;
                if (ref != 0) {
                    if (answer == sum) {
                        printf("That's the answer!\n");
                        correct = 0;
                        times--;
                    } else {
                        printf("That's incorrect. Try a different answer: ");
                    }
                } else {
                    printf("That's incorrect. Try a different answer: ");

                }
            }
        }
        
    }
}