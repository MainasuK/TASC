//
//  main.c
//  7.2.4_oneline
//
//  Created by Cirno MainasuK on 2015-1-16.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  This program draw a line in a window
#include <GLUT/GLUT.h>

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    glColor3f(1.0, 1.0, 1.0);       //  set draw color
    glLineWidth(1.0);               //  set line width
    glBegin(GL_LINES);              //  draw start
    {
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 1.0);
    }
    glEnd();                        //  draw end
    
    glFlush();                      //  force run the code above
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(400, 400);                   //  set window size
    glutCreateWindow("oneline");    //  set window name
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}