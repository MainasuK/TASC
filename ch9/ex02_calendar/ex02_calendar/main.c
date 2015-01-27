//
//  main.c
//  ex02_calendar
//
//  Created by Cirno MainasuK on 2015-1-25.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "calendar.h"

int main(int argc, const char * argv[]) {
    int year;
    
    GiveInstructions();
    year = GetYearFromUser();
    PrintCalendar(year);
    return 0;
}
