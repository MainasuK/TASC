//
//  main.c
//  ex14_find_max_int
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define TURE 1

int main(int argc, const char * argv[]) {
    int c, max = 0;
    printf("This program finds the largest integer in a list.\n");
    printf("Enter 0 to signal the end of the list.\n");
    
    while (TURE) {
        printf(" ? ");
        scanf("%d", &c);
        
        if (c == 0) {
            break;
        } else {
            max = (c > max) ? c : max;
        }
    }
    
    printf("The largest value is %d\n", max);
    
    return 0;
}
