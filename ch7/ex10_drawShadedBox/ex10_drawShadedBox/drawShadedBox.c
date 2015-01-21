//
//  drawShadedBox.c
//  ex10_drawShadedBox
//
//  Created by Cirno MainasuK on 2015-1-20.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawShadedBox.h"

void drawShadedBox(GLdouble x, GLdouble y, GLdouble boxWidth, GLdouble boxHeight, GLdouble density) {
    GLdouble lineLeftY, lineRightX;
    GLdouble lineLeftX, lineRightY;
    GLdouble lineX, lineY;

    drawBox(x, y, boxWidth, boxHeight);

    {
        //  draw diagonal
        {
            if (boxWidth == boxHeight) {    //  square
                glBegin(GL_POLYGON);
                {
                    glVertex2d(x, y);
                    glVertex2d(x, y+density*0.5);
                    glVertex2d(x+boxWidth-density*0.5, y+boxHeight);
                    glVertex2d(x+boxWidth, y+boxHeight);
                    glVertex2d(x+boxWidth, y+boxHeight-density*0.5);
                    glVertex2d(x+density*0.5, y);
                }
                glEnd();
                glFlush();
            } else if (boxWidth > boxHeight) {  //  rectangle
                glBegin(GL_POLYGON);            //  rectangle: left diagonal
                {
                    glVertex2d(x, y);
                    glVertex2d(x, y+density*0.5);
                    glVertex2d(x+boxHeight-density*0.5, y+boxHeight);
                    glVertex2d(x+boxHeight+density*0.5, y+boxHeight);
                    glVertex2d(x+density*0.5, y);
                }
                glEnd();
                glFlush();
                
                glBegin(GL_POLYGON);            //  rectangle: right diagonal
                {
                    glVertex2d(x+boxWidth-boxHeight-0.5*density, y);
                    glVertex2d(x+boxWidth-0.5*density, y+boxHeight);
                    glVertex2d(x+boxWidth, y+boxHeight);
                    glVertex2d(x+boxWidth, y+boxHeight-0.5*density);
                    glVertex2d(x+boxWidth-boxHeight+0.5*density, y);
                }
                glEnd();
                glFlush();
            } else {
                glBegin(GL_POLYGON);            // rectangle: upper diagonal
                {
                    glVertex2d(x, y+boxHeight-boxWidth+density*0.5);
                    glVertex2d(x+boxWidth-density*0.5, y+boxHeight);
                    glVertex2d(x+boxWidth, y+boxHeight);
                    glVertex2d(x+boxWidth, y+boxHeight-density*0.5);
                    glVertex2d(x, y+boxHeight-boxWidth-density*0.5);
                }
                glEnd();
                glFlush();
                
                glBegin(GL_POLYGON);            // rectangle: lower diagonal
                {
                    glVertex2d(x, y);
                    glVertex2d(x, y+density*0.5);
                    glVertex2d(x+boxWidth, y+boxWidth+density*0.5);
                    glVertex2d(x+boxWidth, y+boxWidth-density*0.5);
                    glVertex2d(x+density*0.5, y);
                }
                glEnd();
                glFlush();

            }
        }
        
        // draw shadow
        if (boxWidth >= boxHeight) {
            lineLeftY = y + 0.5*density;
            lineRightX = x + boxHeight - 0.5*density;
            
            //  draw left part shadow
            while (lineLeftY+density < y+boxHeight) {
                    lineLeftY += 2*density;
                    lineRightX -= 2*density;
                if (lineLeftY < y+boxHeight) {
                    glBegin(GL_POLYGON);
                    {
                        glVertex2d(x, lineLeftY);
                        glVertex2d(lineRightX, y+boxHeight);
                        glVertex2d(lineRightX+density, y+boxHeight);
                        glVertex2d(x, lineLeftY-density);
                    }
                    glEnd();
                    glFlush();
                } else {
                        glBegin(GL_POLYGON);
                        {
                            glVertex2d(x, y+boxHeight);
                            glVertex2d(x, lineLeftY-density);
                            glVertex2d(lineRightX+density, y+boxHeight);
                        }
                        glEnd();
                        glFlush();
                    }
                }
            
            //  draw middle part shadow
            lineX = x + 0.5*density;
            while (lineX+density*2 < x+boxWidth-boxHeight-0.5*density) {
                glBegin(GL_POLYGON);
                {
                    glVertex2d(lineX+density, y);
                    glVertex2d(boxHeight+lineX+density, y+boxHeight);
                    glVertex2d(boxHeight+lineX+density*2, y+boxHeight);
                    glVertex2d(lineX+density*2, y);
                }
                glEnd();
                glFlush();
                lineX += 2*density;
            }
            
            //  draw right part shadow
            lineLeftX = x + boxWidth - boxHeight + 0.5*density;
            lineRightY = y + boxHeight - 0.5* density;
            while (lineLeftX+density < x+boxWidth) {
                lineLeftX += 2*density;
                lineRightY -= 2*density;
                if (lineRightY > y) {
                    glBegin(GL_POLYGON);
                    {
                        glVertex2d(lineLeftX-density, y);
                        glVertex2d(x+boxWidth, lineRightY+density);
                        glVertex2d(x+boxWidth, lineRightY);
                        glVertex2d(lineLeftX, y);
                    }
                    glEnd();
                    glFlush();
                } else {
                    glBegin(GL_POLYGON);
                    {
                        glVertex2d(x+boxWidth, y);
                        glVertex2d(lineLeftX-density, y);
                        glVertex2d(x+boxWidth, lineRightY+density);
                    }
                    glEnd();
                    glFlush();
                }
            }
        } else {
            lineLeftY = y + boxHeight- boxWidth + 0.5*density;
            lineRightX = x + boxWidth - 0.5*density;
            
            //  draw upper part shadow
            while (lineLeftY+density < y+boxHeight) {
                lineLeftY += 2*density;
                lineRightX -= 2*density;
                if (lineLeftY < y+boxHeight) {
                    glBegin(GL_POLYGON);
                    {
                        glVertex2d(x, lineLeftY);
                        glVertex2d(lineRightX, y+boxHeight);
                        glVertex2d(lineRightX+density, y+boxHeight);
                        glVertex2d(x, lineLeftY-density);
                    }
                    glEnd();
                    glFlush();
                } else {
                    glBegin(GL_POLYGON);
                    {
                        glVertex2d(x, y+boxHeight);
                        glVertex2d(x, lineLeftY-density);
                        glVertex2d(lineRightX+density, y+boxHeight);
                    }
                    glEnd();
                    glFlush();
                }
            }
            
            //  draw middle part shadow
            lineY = y + 0.5*density;
            while (lineY+density < y+boxHeight-boxWidth-0.5*density) {
                glBegin(GL_POLYGON);
                {
                    glVertex2d(x, lineY+density*2);
                    glVertex2d(x+boxWidth, boxWidth+lineY+density*2);
                    glVertex2d(x+boxWidth, boxWidth+lineY+density);
                    glVertex2d(x, lineY+density);
                }
                glEnd();
                glFlush();
                lineY += 2*density;
            }
            
            //  draw lower part shadow
            lineLeftX = x + 0.5*density;
            lineRightY = y + boxWidth - 0.5* density;
            while (lineLeftX+density < x+boxWidth) {
                lineLeftX += 2*density;
                lineRightY -= 2*density;
                if (lineRightY > y) {
                    glBegin(GL_POLYGON);
                    {
                        glVertex2d(lineLeftX-density, y);
                        glVertex2d(x+boxWidth, lineRightY+density);
                        glVertex2d(x+boxWidth, lineRightY);
                        glVertex2d(lineLeftX, y);
                    }
                    glEnd();
                    glFlush();
                } else {
                    glBegin(GL_POLYGON);
                    {
                        glVertex2d(x+boxWidth, y);
                        glVertex2d(lineLeftX-density, y);
                        glVertex2d(x+boxWidth, lineRightY+density);
                    }
                    glEnd();
                    glFlush();
                }
            }

            
        }

    }
}
