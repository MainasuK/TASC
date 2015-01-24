//
//  main.c
//  ex12_game
//
//  Created by Cirno MainasuK on 2015-1-24.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#include "game.h"

#define INIT 50




void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    game(-0.9, -0.4, 1.8, 0.8, INIT);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);          //  init GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    //  set display mode
    glutInitWindowPosition(100, 100);               //  set window position
    glutInitWindowSize(500, 500);                   //  set window size
    glutCreateWindow("ChessBoard");                     //  set window name
    //    glScalef(0.4, 0.4, 0.4);
    glutDisplayFunc(&myDisplay);                    //  run function to  draw
    glutMainLoop();                                 //  display window on the screen
    return 0;
}
