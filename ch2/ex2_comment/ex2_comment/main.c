//
//  main.c
//  ex2_comment
//
//  Created by Cirno MainasuK on 2015-1-6.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

//  user input b, h.
//  prints the value of (b*h)/2
int main(int argc, const char * argv[]) {
    double b, h, a;
    
    printf("Enter b: ");
    scanf("%lf", &b);
    
    printf("Enter h: ");
    scanf("%lf", &h);
    
    a = (b * h) / 2;
    printf("a = %g\n", a);
    
    return 0;
}
