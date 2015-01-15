//
//  main.c
//  ex07_PI
//
//  Created by Cirno MainasuK on 2015-1-15.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define MAXITEM 10000

//  This function calculate the approximate value of PI (4 digits accurate：3.141）
long double pi(void);

int main(int argc, const char * argv[]) {
    printf("The Pi is %Lf.\n", pi());
    return 0;
}

long double pi(void) {
    int n = 1;
    long double Pi = 0;
    for (int i = 0; i <= MAXITEM; i++) {
        Pi +=  (1.0/n) * pow(-1, i);
        n += 2;
    }
    
    return Pi * 4;
}

