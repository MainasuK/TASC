//
//  calendar.h
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __6_4_calendar_calendar_h
#define __6_4_calendar_calendar_h

#define Sunday    0
#define Monday    1
#define Tuesday   2
#define Wednesday 3
#define Thursday  4
#define Friday    5
#define Saturday  6

void GiveInstructions(void);
int GetYearFromUser(void);
void PrintCalendar(int year);
void PrintCalendarMonth(int month, int year);
void IndentFirstLine(int weekday);
int MonthDays(int month, int year);
int FirstDayOfMonth(int month, int year);
char *MonthName(int month);
char IsLeapYear(int year);

#endif
