//
//  MonthDays.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "calendar.h"

//  MonthDays returns the number of days in the indicated
//  month and year. The year is required to handle leap years.
int MonthDays(MonthT month, int year) {
    switch (month) {
        case 2:
            if (IsLeapYear(year)) return (29);
            return 28;
        case 4: case 6: case 9: case 11:
            return (30);
            
        default:
            return (31);
    }
}