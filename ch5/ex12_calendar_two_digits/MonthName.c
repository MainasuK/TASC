//
//  MonthName.c
//  5.6.4_calendar
//
//  Created by Cirno MainasuK on 2015-1-10.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

//  MonthName converts a numeric month in the range 1-12
//  into the strng name for that month.
char *MonthName(int month) {
    switch (month) {
        case  1: return ("January");
        case  2: return ("February");
        case  3: return ("March");
        case  4: return ("April");
        case  5: return ("May");
        case  6: return ("June");
        case  7: return ("Junly");
        case  8: return ("August");
        case  9: return ("September");
        case 10: return ("October");
        case 11: return ("November");
        case 12: return ("December");
        default: return ("Illegal month");
    }
}
