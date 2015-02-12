//
//  order.c
//  ex08_order_computer
//
//  Created by Cirno MainasuK on 2015-2-11.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "order.h"

#define BUFSIZE 100
#define NINDEX 6
#define NNAME 20
#define NNQUAN

void myOrder(FILE *f) {
    int nscan, quantity, termch;
    char buf[BUFSIZE+1], index[NINDEX+1], name[NNAME+1];
    double unitPrice, sum;
    
    sum = 0.0;
    
    while (fgets(buf, BUFSIZE, f) != NULL) {
        nscan = sscanf(buf, "%6s %[^/]/ %d @ %lf%c",
                       index, name, &quantity, &unitPrice,
                       &termch);
        if (nscan != 5 || termch != '\n') exit(-1);
        printf("%-8s%-20s%3d @ %7.2lf = %7.2lf\n",
               index, name, quantity, unitPrice,
               unitPrice*quantity);
        sum += unitPrice*quantity;
    }
    
    printf("---------------------------------------------------\n");
    printf("TOTAL%46.2lf\n", sum);
}