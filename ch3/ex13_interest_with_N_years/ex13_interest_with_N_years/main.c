//
//  main.c
//  ex13_interest_with_N_years
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

double balanceCalculator(int year, double balance, double rate);

//  input balance, rate, yearAfter, next N year to print a interest table
int main(int argc, const char * argv[]) {
    
    int N, toNYearLater;
    double start, rate, yearRate;
    printf("Interest calculation program.\n");
    printf("Starting balance? ");
    scanf("%lf", &start);
    
    printf("Annual interest rate percentage? ");
    scanf("%lf", &rate);
    yearRate = (1 + 0.01 * rate);
    
    printf("Calculate for ? years: ");
    scanf("%d", &toNYearLater);
    
    printf("print every ? years balance: ");
    scanf("%d", &N);
    
    printf("Year %-3d  |  balance %10g\n", 1, balanceCalculator(1, start, rate));
           
    for (int i = 1; i <= toNYearLater/N; i++) {
        if ((i*N) == 1)
            continue;
        
        printf("Year %-3d  |  balance %10g\n", i * N, balanceCalculator(i * N, start, rate));
    }
    
    return 0;
}


double balanceCalculator(int year, double balance, double rate) {
    for (int i = 0; i < year; i++) {
        balance = balance * (1+ rate * 0.01);
    }
    
    return (double)balance;
}