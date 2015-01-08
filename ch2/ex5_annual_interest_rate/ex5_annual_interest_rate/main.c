//
//  main.c
//  ex4_annual_interest_rete
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double start, rate, yearRate, year1;
    printf("Interest calculation program.\n");
    printf("Starting balance? ");
    scanf("%lf", &start);
    printf("Annual interest rate percentage? ");
    scanf("%lf", &rate);
    yearRate = (1 + 0.01 * rate);
    
    printf("Balance after one year: %g\n", year1 = start * yearRate);
    printf("Balance after two year: %g\n", year1 * yearRate);
    return 0;
}
