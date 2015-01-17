//
//  DrawTools.c
//  DrawTools
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "DrawTools.h"
#include <GLUT/GLUT.h>
#include <math.h>

const GLfloat PI = 3.14159265358979;


void drawLine(double x1, double y1, double x2, double y2) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    glBegin(GL_LINES);              //  draw start
    {
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    }
    glEnd();                        //  draw end
    
    glFlush();                      //  force run the code above
}

void drawArc(double x, double y, double r, int start, int sweep) {
    double radian, p = PI / (180);
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    glBegin(GL_POINTS);              //  draw start
    for (int i = start; i < sweep; i++) {
        radian = i * p;
        glVertex2d(r*cos(radian) + x, r*sin(radian) + y);
    }
    glEnd();                        //  draw end
    
    glFlush();                      //  force run the code above

}
