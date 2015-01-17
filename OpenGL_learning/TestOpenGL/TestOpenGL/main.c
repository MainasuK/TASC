//  This project from Web:https://www.youtube.com/watch?v=LPkwd7GoLv0

#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>




float red=1.0, blue=1.0, green=0;


void line()
{
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex2i(20,20);
    glVertex2i(400,400);
    glEnd();
}

void renderScence(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(red, green, blue);
    line();
    glFlush();
    
}


void init(void)
{
    
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize (500,500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Testing");
    
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}



int main(int argc,char ** argv)

{
    
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(renderScence);
    glutIdleFunc(renderScence);
    
    glutMainLoop();
    return 0;
}
