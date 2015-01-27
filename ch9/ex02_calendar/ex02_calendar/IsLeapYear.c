//
//  IsLeapYear.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

//  This function returns TRUE if yaer is a leap year
char IsLeapYear(int year) {
    return (    ((year%4==0) && (year%100!=0)) || (year%400==0)    );
}
