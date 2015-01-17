//
//  main.c
//  ex03_heart
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//


#include <math.h>
#include "DrawTools.h"
#define RADIOUS  0.3
#define root2    pow(2, 0.5)

void myHeart(GLdouble x, GLdouble y, GLdouble r) {
    drawLine(x, y - r*root2, x - r*root2, y);
    drawLine(x, y - r*root2, x + r*root2, y);
    drawArc(x - 0.5*(r*root2), y + 0.5*(r*root2), r,  45, 225);
    drawArc(x + 0.5*(r*root2), y + 0.5*(r*root2), r, -45, 135);
}
void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    myHeart(0.0, 0.0, RADIOUS);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(800, 800);                   //  set window size
    glutCreateWindow("Heart");                     //  set window name
    glScalef(0.4, 0.4, 0.4);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}