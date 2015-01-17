//
//  main.c
//  7.2.4_oneline
//
//  Created by Cirno MainasuK on 2015-1-16.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "genlib.h"
#include "graphics.h"


int main(int argc, const char * argv[]) {
    InitGraphics();
    MovePen(0.5, 0.5);
    DrawLine(0.0, 1.0);
    
    return 0;
}
