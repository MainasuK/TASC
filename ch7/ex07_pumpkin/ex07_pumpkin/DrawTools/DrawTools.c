//
//  DrawTools.c
//  DrawTools
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "DrawTools.h"



const GLfloat PI = 3.14159265358979;


void drawLine(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    glBegin(GL_LINES);              //  draw start
    {
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    }
    glEnd();                        //  draw end
    glFlush();                      //  force run the code above
}

void drawArc(GLdouble x, GLdouble y, GLdouble r, GLint start, GLint sweep) {
    GLdouble radian, p = PI / (180);
    glBegin(GL_POINTS);              //  draw start
    for (int i = start; i < sweep; i++) {
        radian = i * p;
        glVertex2d(r*cos(radian) + x, r*sin(radian) + y);
    }
    glEnd();                        //  draw end
    glFlush();                      //  force run the code above

}

void drawBox(GLdouble x, GLdouble y, GLdouble width, GLdouble height) {
    glBegin(GL_LINES);              //  draw start
    {
        glVertex2d(x, y);
        glVertex2d(x+width, y);
        
        glVertex2d(x+width, y);
        glVertex2d(x+width, y+height);
        
        glVertex2d(x+width, y+height);
        glVertex2d(x, y+height);
        
        glVertex2d(x, y+height);
        glVertex2d(x, y);
    }
    glEnd();                        //  draw end
    glFlush();                      //  force run the code above
}

void drawCenteredCircle(GLdouble x, GLdouble y, GLdouble r) {
    drawArc(x, y, r, 0, 360);
}

void drawTriangle(GLdouble x, GLdouble y, GLdouble base, GLdouble height) {
    drawLine(x, y, x+base, y);
    drawLine(x, y, x+(base/2.0), y + height);
    drawLine(x+(base/2.0), y+height, x+base, y);
}

void drawGrid(GLdouble x, GLdouble y, GLdouble width, GLdouble height, GLint columns, GLint rows) {
    int i, j;
    for (i = 0; i < columns; i++) {
        for (j = 0; j < rows; j++) {
            drawBox(x + i*width, y + j *height, width, height);
        }
    }
}