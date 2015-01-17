//
//  main.c
//  pfanSampleCode
//
//  This program from bbs.pfan.cn
//
//  http://bbs.pfan.cn/post-184355.html

#include <GLUT/GLUT.h>

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("My first OpenGL program");
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}