//
//  main.c
//  ex3_inch2cm
//
//  Created by Cirno MainasuK on 2015-1-6.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double feet, inch, cm;
    
    printf("This program converts inches to centimeters.\n");
    printf("Length in feets? ");
    scanf("%lf", &feet);
    printf("Length in inches? ");
    scanf("%lf", &inch);
    cm = (12 * feet + inch) * 2.54;
    
    printf("%g in = %g cm\n", inch, cm);
    
    return 0;
}
