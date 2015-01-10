//
//  main.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program is used to generate a calendar for a year


#include <stdio.h>
#include "calendar.h"

int main(int argc, const char * argv[]) {
    int year;
    
    GiveInstructions();
    year = GetYearFromUser();
    PrintCalendar(year);
    return 0;
}
