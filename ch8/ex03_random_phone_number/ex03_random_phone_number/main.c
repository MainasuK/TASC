//
//  main.c
//  ex03_random_phone_number
//
//  Created by Cirno MainasuK on 2015-1-21.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

void printRandomPhoneNumber(void);
void randomize(void);

int main(int argc, const char * argv[]) {
    randomize();
    printRandomPhoneNumber();
    return 0;
}

void printRandomPhoneNumber(void) {
    printf("%d%d%d-%d%d%d%d\n", randomInteger(2, 9), randomInteger(2, 9), randomInteger(0, 9), randomInteger(0, 9), randomInteger(0, 9), randomInteger(0, 9), randomInteger(0, 9));
}

void randomize(void) {
    srand((unsigned)time(NULL));
}
