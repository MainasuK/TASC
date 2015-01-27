//
//  PrintCalendarMonth.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "calendar.h"

//  This procedure prints a calendar for the given month
//  and year.
void PrintCalendarMonth(MonthT month, int year) {
    int weekday, nDays, day;

    printf("     %s %d\n", MonthName(month), year);
    printf(" Su Mo Tu We Th Fr Sa\n");
    nDays = MonthDays(month, year);
    weekday = FirstDayOfMonth(month, year);
    IndentFirstLine(weekday);
    for (day = 1; day <= nDays; day++) {
        printf(" %2d", day);
        if (weekday == Saturday) printf("\n");
        weekday = (weekday + 1) % 7;
    }
    if (weekday != Sunday) printf("\n");
}