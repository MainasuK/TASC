//
//  main.c
//  ex09_drawLineGraph
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawLineGraph.h"

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    drawLineGraph(10);
   }


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(500, 500);                   //  set window size
    glutCreateWindow("LineGraph");                     //  set window name
    // glScalef(0.2, 0.2, 0.2);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}
