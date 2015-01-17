//
//  main.c
//  ex01_drawCrossedBox
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "DrawTools.h"

void drawCrossedBox(GLdouble x, GLdouble y, GLdouble width, GLdouble height) {
    drawBox(x, y, width, height);
    drawLine(x, y, x+width, y+height);
    drawLine(x, y+height, x+width, y);
}
void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    drawCrossedBox(-0.5, -0.5, 0.8, 0.5);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(400, 400);                   //  set window size
    glutCreateWindow("CrossedBox");                    //  set window name
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}