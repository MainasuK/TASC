//
//  main.c
//  ex11_chessBoard
//
//  Created by Cirno MainasuK on 2015-1-21.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawShadedBox.h"

void drawChessBoard(GLdouble x, GLdouble y, GLdouble width, GLdouble density) {
    GLdouble boardGridWidth = width/8.0;
    drawBox(x, y, width, width);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i+j)%2 == 0) {
                drawShadedBox(x+j*boardGridWidth, y+i*boardGridWidth, boardGridWidth, boardGridWidth, density);
            } else {
                drawBox(x+j*boardGridWidth, y+i*boardGridWidth, boardGridWidth, boardGridWidth);
            }
        }
    }
    
    
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    drawChessBoard(-0.9, -0.9, 1.8, 0.016);
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
