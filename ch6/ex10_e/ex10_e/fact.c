//
//  fact.c
//  ex10_e
//
//  Created by Cirno MainasuK on 2015-1-16.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "fact.h"

long factorial(long i) {
    if (i == 0)
        return (1);
    else
        return i * factorial(i-1);
}