//
//  main.c
//  ex06_drawMyName
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <math.h>
#include "DrawTools.h"
#include "drawLetter.h"
#define ConerRadius  0.2



void drawRoundedBox(GLdouble x, GLdouble y, GLdouble width, GLdouble height) {
    drawLine(x, y + ConerRadius, x, y + height - ConerRadius);
    drawLine(x + ConerRadius, y + height, x + width - ConerRadius, y + height);
    drawLine(x + width, y + height - ConerRadius, x + width, y + ConerRadius);
    drawLine(x + ConerRadius, y, x + width - ConerRadius, y);
    drawArc(x + ConerRadius, y + ConerRadius, ConerRadius, 180, 270);
    drawArc(x + ConerRadius, y + height - ConerRadius, ConerRadius, 90, 180);
    drawArc(x + width - ConerRadius, y + height - ConerRadius, ConerRadius, 0, 90);
    drawArc(x + width - ConerRadius, y + ConerRadius, ConerRadius, -90, 0);
    
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    drawRoundedBox(-0.9, -0.4, 1.8, 0.6);
    drawC(-0.8, -0.35, 0.5);
    drawM(-0.28, -0.35, 0.5);
    drawK( 0.4, -0.35, 0.5);
    
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