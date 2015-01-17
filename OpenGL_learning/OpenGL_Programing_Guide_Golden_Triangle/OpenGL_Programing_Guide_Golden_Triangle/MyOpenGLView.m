//
//  MyOpenGLView.m
//  OpenGL_Programing_Guide_Golden_Triangle
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#import "MyOpenGLView.h"
#include <OpenGL/gl.h>

@implementation MyOpenGLView
static void drawAnObject () {
    glColor3f(1.0f, 0.85f, 0.35f);
    glBegin(GL_TRIANGLES);
    {
        glVertex3f(  0.0,  0.6, 0.0);
        glVertex3f( -0.2, -0.3, 0.0);
        glVertex3f(  0.2, -0.3, 0.0);
        
    }
    glEnd();
}
- (void) drawRect: (NSRect) bounds {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawAnObject();
    glFlush();
}

@end
