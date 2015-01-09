//
//  main.c
//  ex08_Fibonacci
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int fibonacci(int);

//  This program list the Fibonacci sequence
//  the function fibonacci get the result of F(index) 
int main(int argc, const char * argv[]) {
    printf("This program lists the Fibonacci sequence.\n");
    
    printf(" F(%d) = %4d\n", 0, 0);
    printf(" F(%d) = %4d\n", 1, 1);
    
    for (int i = 2; i <= 15; i++) {
        if (i < 10) printf(" ");        //  aline prints
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