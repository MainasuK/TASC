//
//  main.c
//  ex11_dateString
//
//  Created by Cirno MainasuK on 2015-1-26.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

void dateString(int day, int month, int year);

int main(int argc, const char * argv[]) {
    dateString(22, 11, 1963);
    return 0;
}

void dateString(int day, int month, int year) {
    char *m;
    switch (month) {
        case 1:
            m = "Jan";
            break;
        case 2:
            m = "Feb";
            break;
        case 3:
            m = "Mar";
            break;
        case 4:
            m = "Apr";
            break;
        case 5:
            m = "May";
            break;
        case 6:
            m = "Jun";
            break;
        case 7:
            m = "July";
            break;
        case 8:
            m = "Aug";
            break;
        case 9:
            m = "Sep";
            break;
        case 10:
            m = "Oct";
            break;
        case 11:
            m = "Nov";
            break;
        case 12:
            m = "Dec";
            break;
            
        default:
            m = "Illegal month";
            break;
    }
    printf("%d-%s-%d\n", day, m, year);
}