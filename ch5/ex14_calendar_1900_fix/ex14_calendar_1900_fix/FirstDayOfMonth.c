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
//  indicated month begins.
//  The Algorithm is at http://blog.csdn.net/ycrao/article/details/3825
//  some bug fix
int FirstDayOfMonth(int month, int year) {
    int weekday;
    int D = 1;
    int Y = year, M = month;
    
    if ((M == 1) || (M == 2)){
        M += 12;
        Y--;
    }


    weekday = (D+1 + 2*M + 3*(M+1)/5 + Y + Y/4 - Y/100 + Y/400) % 7;
    return (weekday);
}