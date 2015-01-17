//
//  main.c
//  ex04_peaceSymbol
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <math.h>
#include "DrawTools.h"
#define RADIOUS  0.5
#define root2    pow(2, 0.5)


void peaceSymbol(GLdouble x, GLdouble y, GLdouble r) {
    drawLine(x, y + r, x, y-r);
    drawLine(x - r*root2/2, y - r*root2/2, x, y);
    drawLine(x + r*root2/2, y - r*root2/2, x, y);
    drawArc(x, y, r, 0, 360 * 3);

}
void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    peaceSymbol(0.0, 0.0, RADIOUS);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(5-00, 500);                   //  set window size
    glutCreateWindow("Heart");                     //  set window name
//    glScalef(0.4, 0.4, 0.4);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}