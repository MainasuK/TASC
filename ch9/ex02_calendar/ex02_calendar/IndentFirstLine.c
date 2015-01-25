//
//  IndentFirstLine.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "calendar.h"

//  This procedure indents the first line of the calendar
//  by printing enough blank spaces to get to the position
//  on hte line corresponding to weekday.
void IndentFirstLine(WeekdayT weekday) {
    int i;
    
    for (i = 0; i < weekday; i++) {
        printf("   ");
    }
}