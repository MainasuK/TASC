//
//  main.c
//  ex10_drawShadedBox
//
//  Created by Cirno MainasuK on 2015-1-20.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawShadedBox.h"


void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    drawShadedBox(-0.9, -0.9, 1.8, 1.2, 0.03);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(500, 500);                   //  set window size
    glutCreateWindow("RoundedBox");                     //  set window name
//    glScalef(0.4, 0.4, 0.4);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}
