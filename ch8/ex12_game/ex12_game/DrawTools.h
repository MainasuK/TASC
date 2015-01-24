//
//  DrawTools.h
//  DrawTools
//
//  Created by Cirno MainasuK on 2015-1-17.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#ifndef __DrawTools__DrawTools__
#define __DrawTools__DrawTools__

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <math.h>

/*
 * Function: drawLine
 * Usage: drawLine(x1, x2, y1, y2);
 * ------------------------
 * This procedure draws a line extending from the current
 * point by moving the pen dx inches in the x direction
 * and dy inches in the y direction.  The final position
 * becomes the new current point.
 */

void drawLine(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);

/*
 * Function: drawArc
 * Usage: drawArc(x, y, r, start, sweep);
 * --------------------------------
 * This procedure draws a circular arc, which always begins
 * at the current point.  The arc itself has radius r, and
 * starts at the angle specified by the parameter start,
 * relative to the center of the circle.  This angle is
 * measured in degrees counterclockwise from the 3 o'clock
 * position along the x-axis, as in traditional mathematics.
 * For example, if start is 0, the arc begins at the 3 o'clock
 * position; if start is 90, the arc begins at the 12 o'clock
 * position; and so on.  The fraction of the circle drawn is
 * specified by the parameter sweep, which is also measured in
 * degrees.  If sweep is 360, DrawArc draws a complete circle;
 * if sweep is 90, it draws a quarter of a circle.  If the value
 * of sweep is positive, the arc is drawn counterclockwise from
 * the current point.  If sweep is negative, the arc is drawn
 * clockwise from the current point.  The current point at the
 * end of the DrawArc operation is the final position of the pen
 * along the arc.
 *
 * Examples:
 *   drawArc(x, y, r, 0, 360)    Draws a circle to the left of the
 *                         current point.
 *   drawArc(x, y, r, 90, 180)   Draws the left half of a semicircle
 *                         starting from the 12 o'clock position.
 *   drawArc(x, y, r, 0, 90)     Draws a quarter circle from the 3
 *                         o'clock to the 12 o'clock position.
 *   drawArc(x, y, r, 0, -90)    Draws a quarter circle from the 3
 *                         o'clock to the 6 o'clock position.
 *   drawArc(x, y, r, -90, -90)  Draws a quarter circle from the 6
 *                         o'clock to the 9 o'clock position.
 */

void drawArc(GLdouble x, GLdouble y, GLdouble r, GLint start, GLint sweep);

/*
 * Funciton: drawBox
 * Usage: drawBox(x, y, width, height);
 * -----------------------------
 * This function draws rectangle of the given width and
 * height with its lower left corner at (x, y).
 */

void drawBox(GLdouble x, GLdouble y, GLdouble width, GLdouble height);


/*
 * Function: drawCenteredCircle
 * Usage: DrawCenteredCircle(x, y, r);
 * ------------------------------
 * This function draws a circle of radius r with its
 * center at (x, y).
 */

void drawCenteredCircle(GLdouble x, GLdouble y, GLdouble r);


/*
 * Function: drawTriangle
 * Usage: drawTriangle(x, y, base, height);
 * ------------------------------
 * This function draw an isosceles triangle (i.e., one with
 * two equal sides) with a horizontal base.  The coordinate 
 * of the left endpoint of the base is (x, y), and the triangle
 * has the indicated base length and height.  If height is
 * positive, the triangle points upward.  If height is negative,
 * the triangle points downward.
 */

void drawTriangle(GLdouble x, GLdouble y, GLdouble base, GLdouble height);


/*
 * Funtion: drawGrid
 * Usage: drawGird(x, y, width, height, columns, rows);
 * ------------------------------
 * drawGird draws rectangles arranged in a two - dimensional
 * grid.  As always, (x, y) specifies the lower left corner
 * of the figure.
 */

void drawGrid(GLdouble x, GLdouble y, GLdouble width, GLdouble height, GLint columns, GLint rows);

#endif /* defined(__DrawTools__DrawTools__) */
