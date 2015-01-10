//
//  PrintCalendar.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "calendar.h"

//  This procedure prints a calendar for an entire year.
void PrintCalendar(int year) {
    int month;
    
    for (month = 1; month <= 12; month++) {
        PrintCalendarMonth(month, year);
        printf("\n");
    }
}
