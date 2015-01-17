//
//  main.c
//  7.4_drawHouse
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "house.h"


void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    drawHouse(-HouseWidth/2.0, -HouseHeight/2.0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(400, 400);                   //  set window size
    glutCreateWindow("House");                    //  set window name
    glScalef(0.3, 0.3, 0.3);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}