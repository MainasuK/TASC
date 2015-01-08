//
//  main.c
//  ex4_annual_interest_rete
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    double start, rate;
    printf("Interest calculation program.\n");
    printf("Starting balance? ");
    scanf("%lf", &start);
    printf("Annual interest rate percentage? ");
    scanf("%lf", &rate);
    
    printf("Balance after one year: %.0lf\n", start * (1 + 0.01 *rate));
    return 0;
}
