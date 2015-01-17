//
//  main.c
//  ex02_NBricksInBase
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "DrawTools.h"
#define NBricksInBase  16
#define BrickWidth     0.2
#define BrickHeight    0.1

void putBricks(GLint n, GLdouble x, GLdouble y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            drawBox(x + (i/2.0 + j) * BrickWidth, y+(BrickHeight*i), BrickWidth, BrickHeight);
        }
    }
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    putBricks(NBricksInBase, -(NBricksInBase * BrickWidth)/2.0, -(NBricksInBase * BrickHeight)/2.0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(800, 600);                   //  set window size
    glutCreateWindow("Bricks");                    //  set window name
    glScalef(0.4, 0.4, 0.4);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}