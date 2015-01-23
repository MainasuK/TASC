//
//  main.c
//  ex10_pop
//
//  Created by Cirno MainasuK on 2015-1-23.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "random.h"
#include "DrawTools.h"

#define ITEMS 10

int inTheBox(GLdouble boxX, GLdouble boxY, GLdouble boxWidth, GLdouble boxHeight,
              GLdouble popX, GLdouble popY, GLdouble popRadius) {
    int flag = 0;
    GLdouble dX, dY;
    
    dX = popX - boxX;
    dY = popY - boxY;
    
    if ((popRadius > dX) || (popRadius > (boxWidth-dX)))
        flag = 1;
    if ((popRadius > dY) || (popRadius > (boxHeight-dY)))
        flag = 1;
    return (flag) ? 0 : 1;
}

void drawPop(GLdouble boxX, GLdouble boxY, GLdouble boxWidth, GLdouble boxHeight,
             GLdouble radiusLow, GLdouble radiusHigh, int i) {
    GLdouble x, y, radius;
    drawBox(boxX, boxY, boxWidth, boxHeight);
    randomize();
    while (i) {
        x = randomReal(boxX, boxX+boxWidth);
        y = randomReal(boxY, boxY+boxHeight);
        radius = randomReal(radiusLow, radiusHigh);
        if (inTheBox(boxX, boxY, boxWidth, boxHeight, x, y, radius)) {
            drawCenteredCircle(x, y, radius);
            printf("%d: x:%lf y:%lf r:%lf\n", ITEMS - i, x, y, radius);
            i--;
        }
    }
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    drawPop(-0.9, -0.9, 1.8, 1.8, 0.05, 0.5, ITEMS);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);                          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(500, 500);                   //  set window size
    glutCreateWindow("Pop");                        //  set window name
    //    glScalef(0.4, 0.4, 0.4);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}
