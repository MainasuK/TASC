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
void sayCorrect(int sum);

int main(int argc, const char * argv[]) {
    questions(TIMES);
    return 0;
}


void questions(int times) {
    randomize();
    int x, y, sum, answer, correct, loop;
    int op;
    int ref, c;
    while (times) {
        x = randomInteger(1, 20);
        y = randomInteger(1, 20);
        op = randomChance(0.5);
        correct = 1;
        sum = (op) ? x+y : x-y;
        loop = 0;
        
        if (sum > 0 && sum < 20) {
            printf("What is %d %s %d? ", x, (op) ? "+" : "-", y);
            while (correct) {
                ref = scanf("%d", &answer);
                while ((c=getchar()) != '\n')
                    ;
                if (loop == 2) {
                    printf("No, the answer is %d.\n", sum);
                    times--;
                    break;
                }
                if (ref != 0) {
                    if (answer == sum) {
                        sayCorrect(sum);
                        correct = 0;
                        times--;
                    } else {
                        printf("That's incorrect. Try a different answer: ");
                        loop++;
                    }
                } else {
                    printf("That's incorrect. Try a different answer: ");
                    loop++;
                }
            }
        }
    }
}

void sayCorrect(int sum) {
    int i;
    i = randomInteger(1, 4);
    switch (i) {
        case 1:
            printf("Correct!\n");
            break;
        case 2:
            printf("You got it. The answer is %d.\n", sum);
            break;
        case 3:
            printf("That's answer.\n");
            break;
        case 4:
            printf("That's right.\n");
        default:
            break;
    }
    
}