//
//  main.c
//  ex09_Fibonacci_v2
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int fibonacci(int);

//  This program list the Fibonacci sequence
//  the function fibonacci get the result of F(index)
//  and the result less than 10 000
int main(int argc, const char * argv[]) {
    printf("This program lists the Fibonacci sequence.\n");
    
    printf(" F(%d) = %4d\n", 0, 0);
    printf(" F(%d) = %4d\n", 1, 1);
    
    for (int i = 2; ; i++) {
        if (i < 10) printf(" ");        //  aline prints
        if (fibonacci(i) >= 10000) break;
        
        printf("F(%d) = %4d\n", i, fibonacci(i));
        
    }
    return 0;
}


int fibonacci(int a) {
    if (a == 0)
        return 0;
    else if (a == 1)
        return 1;
    else
        return fibonacci(a-1) + fibonacci(a-2);
}