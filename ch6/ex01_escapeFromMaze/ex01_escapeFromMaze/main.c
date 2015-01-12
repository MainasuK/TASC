//
//  main.c
//  ex01_escapeFromMaze
//
//  Created by Cirno MainasuK on 2015-1-12.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  suppose we have a lib which has 5 function
//  - void MoveForward(void);
//  - void TurnRight(void);
//  - void TureLeft(void);
//  - bool IfFacingWall(void);
//  - bool IfOutside(void);

#include <stdio.h>
#define bool char
#define TRUE  1
#define FALSE 0
void MoveForward(void);
void TurnRight(void);
void TurnLeft(void);
bool IfFacingWall(void);
bool IfOutside(void);


bool RightIsWall(void) {
    TurnRight();
    if (IfFacingWall()) {
        TurnLeft();
        return (TRUE);
    } else {
        TurnLeft();
        return (FALSE);
    }
}

bool LeftIsWall(void) {
    TurnLeft();
    if (IfFacingWall()) {
        TurnRight();
        return TRUE;
    } else {
        TurnRight();
        return FALSE;
    }
}


bool LeftIsWall(void);
int main(int argc, const char * argv[]) {
    while (!IfOutside)//  - void MoveForward(void);
        //  - void TurnRight(void);
        //  - void TureLeft(void);
        //  - bool IfFacingWall(void);
        //  - bool IfOutside(void);
 {
        if (!IfFacingWall() && RightIsWall()) {
            MoveForward();
        } else if (IfFacingWall() && RightIsWall()) {
            TurnLeft();
        } else if (!RightIsWall()) {
            TurnRight();
            MoveForward();
        }
    }
    return 0;
}
