//
//  GetYearFromUser.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define TURE 1

//  This function read in a year from the user and returns
//  that value. If the user enters a year before 1900, the
//  function gives the user another chance.
int GetYearFromUser(void) {
    int year;
    
    while (TURE) {
        printf("Which year? ");
        scanf("%d", &year);
        if (year < 100)
            return (1900 + year);
        return (year);
    }
}

#undef TURE