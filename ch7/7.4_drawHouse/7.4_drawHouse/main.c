//
//  main.c
//  7.4_drawHouse
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//



void myDisplay(void) {
    int i;
    glClear(GL_COLOR_BUFFER_BIT);   //  clear buffer
    glBegin(GL_POLYGON);              //  draw start
    {
        for (i = 0; i < N; i++) {
            glVertex2f(R*cos(2*PI/N*i), R*sin(2*PI/N*i));
        }
        
    }
    glEnd();                        //  draw end
    
    glFlush();
    //  force run the code above
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