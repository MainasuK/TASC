//
//  main.c
//  ex6_circle_area
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define PI 3.14159

int main(int argc, const char * argv[]) {
    double radius;
    printf("This is a circle area calculation program.\n");
    printf("Radius? ");
    scanf("%lf", &radius);
    
    printf("The anwser is: %g\n", PI * radius *radius);
    return 0;
}
