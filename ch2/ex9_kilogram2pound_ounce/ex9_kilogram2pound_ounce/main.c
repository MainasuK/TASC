//
//  main.c
//  ex9_kilogram2pound_ounce
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double kg, lb, oz;
    printf("Kilogram? ");
    scanf("%lf", &kg);
    lb = 2.2 * kg;
    oz = 16 * lb;
    
    printf("%g lb\n", lb);
    printf("%g oz\n", oz);
    return 0;
}
