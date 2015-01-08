//
//  main.c
//  ex7_fahrenheit2celsius
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int fahr;
    printf("Program to convert Fahrenheit to Celsius\n");
    printf("Fahrenheit temperature? ");
    scanf("%d", &fahr);
    
    printf("Celsius equivalent: %d\n", (int)(5.0/9.0 * (fahr-32)));
    
    return 0;
}
