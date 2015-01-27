//
//  FirstDayOfMonth.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "calendar.h"

//  This function returns the day of the week on which the
//  indicated month begins. This program simply counts
//  forward from January 1, 1900, which was a Monday.
WeekdayT FirstDayOfMonth(MonthT month, int year) {
    int weekday, i;
    
    weekday = Monday;
    for (i = 1900; i < year; i++) {
        weekday = (weekday +365) % 7;
        if (IsLeapYear(i)) weekday = (weekday + 1) & 7;
    }
    for (i = 1; i < month; i++) {
        weekday = (weekday + MonthDays(i, year)) % 7;
    }
    
    return (weekday);
}