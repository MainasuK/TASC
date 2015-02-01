//
//  main.c
//  ex04_alphabetize
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "sort.h"

int main(int argc, const char * argv[]) {
    char *a[] = {
        "hello",
        "world",
        "no",
        "all",
        "good",
        "b",
        "c",
        "d",
        "e",
        "f",
    };
    
    sortAlphabetize(a, 10);
    
    for (int i = 0; i < 10; i++) {
        puts(a[i]);
    }

    return 0;
}
