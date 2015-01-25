//
//  MonthName.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "calendar.h"

//  MonthName converts a numeric month in the range 1-12
//  into the strng name for that month.
char *MonthName(MonthT month) {
    switch (month) {
        case January:   return ("January");
        case February:  return ("February");
        case March:     return ("March");
        case April:     return ("April");
        case May:       return ("May");
        case June:      return ("June");
        case July:      return ("July");
        case August:    return ("August");
        case September: return ("September");
        case October:   return ("October");
        case November:  return ("November");
        case December:  return ("December");
        default:        return ("Illegal month");
    }
}
