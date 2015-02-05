//
//  main.c
//  ex06_tabluate
//
//  Created by Cirno MainasuK on 2015-2-5.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "tabulate.h"

int main(int argc, const char * argv[]) {
    int a[] = {91, 93, 98, 92, 92, 95, 93, 92, 91, 95, 99, 92, 98};
    int n = sizeof(a)/sizeof(a[0]);
    tabluate(a, n);
    return 0;
}
