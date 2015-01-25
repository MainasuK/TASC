//
//  calendar.h
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __6_4_calendar_calendar_h
#define __6_4_calendar_calendar_h

typedef enum {
    Sunday = 0,
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6
} WeekdayT;

typedef enum {
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
} MonthT
;
void GiveInstructions(void);
int GetYearFromUser(void);
void PrintCalendar(int year);
void PrintCalendarMonth(MonthT month, int year);
void IndentFirstLine(WeekdayT weekday);
int MonthDays(MonthT month, int year);
WeekdayT FirstDayOfMonth(MonthT month, int year);
char *MonthName(MonthT month);
char IsLeapYear(int year);

#endif
