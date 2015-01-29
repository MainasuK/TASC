//
//  labelGenerator.c
//  ex11_label_generator
//
//  Created by Cirno MainasuK on 2015-1-29.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <string.h>
#include "labelGenerator.h"

#define MAXLENS 100

static char buffer[MAXLENS];
static int indexP;

void initLabelGenerator(void) {
    strcmp(buffer, "Label");
    indexP = 1;
}

void getNextLabel(void) {
    printf("%s", buffer);
    printf("%d", indexP++);
    printf("\n");
}


void setLabelPrefix(char *s) {
    strcpy(buffer, s);
    
}

void setLabelNumber(int n) {
    indexP = n;
}