//
//  main.c
//  ex02_getData
//
//  Created by Cirno MainasuK on 2015-2-4.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "getData.h"

int main(int argc, const char * argv[]) {
    int day, month, year;
    getDate(&day, &month, &year);
    
    printf("Day = %d\n", day);
    printf("Month = %d\n", month);
    printf("Year = %d\n", year);
    return 0;
}
