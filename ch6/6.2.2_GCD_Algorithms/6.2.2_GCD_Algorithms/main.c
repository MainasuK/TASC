//
//  main.c
//  6.2.2_GCD_Algorithms
//
//  Created by Cirno MainasuK on 2015-1-12.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define TURE  1
#define FALSE 0


int GCD(int x, int y);

int main(int argc, const char * argv[]) {
    int x, y;
    printf("input two integers to get them GCD\n");
    printf(" ? ");
    scanf("%d", &x);
    printf(" ? ");
    scanf("%d", &y);
    
    printf("The GCD is %d.\n", GCD(x, y));
    return 0;
}


//  This is a GCD algorithms writen by Euclid
int GCD(int x, int y) {
    int r;
    
    while (TURE) {
        r = x % y;
        if (r == 0) break;
        x = y;
        y = r;
    }
    
    return (y);
}