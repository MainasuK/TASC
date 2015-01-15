//
//  main.c
//  ex06_Bode's_law
//
//  Created by Cirno MainasuK on 2015-1-15.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program prints the distance of the Sun to the planets
//  The ? represent Asteroid belt

#include <stdio.h>
#include "theLawOfBode.h"

int main(int argc, const char * argv[]) {
    printf("%-10s%.1lf AU\n", "Mercury", theLawOfBode(1));
    printf("%-10s%.1lf AU\n", "Venus", theLawOfBode(2));
    printf("%-10s%.1lf AU\n", "Earth", theLawOfBode(3));
    printf("%-10s%.1lf AU\n", "Mars", theLawOfBode(4));
    printf("%-10s%.1lf AU\n", "?", theLawOfBode(5));
    printf("%-10s%.1lf AU\n", "Jupiter", theLawOfBode(6));
    printf("%-10s%.1lf AU\n", "Saturn", theLawOfBode(7));
    printf("%-10s%.1lf AU\n", "Uranus", theLawOfBode(8));
    
    return 0;
}
