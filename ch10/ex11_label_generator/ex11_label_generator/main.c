//
//  main.c
//  ex11_label_generator
//
//  Created by Cirno MainasuK on 2015-1-29.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "labelGenerator.h"

#define MAXLENS 100
#define LOOP    5
int main(int argc, const char * argv[]) {
    char prefix[MAXLENS];
    int c, index;
    int i = 0;
    initLabelGenerator();
    printf("This program tests the labelseq abstraction.\n");
    printf("Prefix to use for labels: ");
    while ((c=getchar()) != '\n') {
        prefix[i++] = c;
    }
    prefix[i] = '\0';
    printf("Starting number: ");
    scanf("%d", &index);
    
    setLabelPrefix(prefix);
    setLabelNumber(index);
    for (int j = 0; j < LOOP; j++) {
        getNextLabel();
    }
    
    
    return 0;
}
