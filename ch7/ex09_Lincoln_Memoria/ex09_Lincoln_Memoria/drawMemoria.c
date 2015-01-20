//
//  drawMemoria.c
//  ex09_Lincoln_Memoria
//
//  Created by Cirno MainasuK on 2015-1-20.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "drawMemoria.h"

void drawMemorial(GLdouble x,GLdouble y) {
    drawPedestal(x, y);
    drawColumn(x, y);
    drawRoof(x, y);
    drawStatue(x, y);
}

void drawPedestal(GLdouble x, GLdouble y) {
    drawBox(x, y, MemorialWidth, PedestalHeight);
}

void drawColumn(GLdouble x, GLdouble y) {
    GLdouble width = ColumnWidth+(MemorialWidth-NumberOfColumns*ColumnWidth)/(NumberOfColumns-1);
    for (int i = 0; i < NumberOfColumns; i++) {
        drawBox(x+i*width, y+PedestalHeight, ColumnWidth, ColumnHeight);
        drawCenteredCircle(x+i*width+0.5*ColumnWidth, y+PedestalHeight+ColumnHeight+0.5*LowerRoofHeight, ColumnCircleRadius);
    }
}

void drawRoof(GLdouble x, GLdouble y) {
    drawBox(x, y+PedestalHeight+ColumnHeight, MemorialWidth, LowerRoofHeight);
    drawBox(x+MemorialWidth*0.5-UpperRoofWidth*0.5, y+PedestalHeight+ColumnHeight+LowerRoofHeight, UpperRoofWidth, UpperRoofHeight);
}

void drawStatue(GLdouble x, GLdouble y) {
    drawBox(x+0.5*MemorialWidth-0.5*StatueWidth, y+PedestalHeight, StatueWidth, StatueHeight);
    drawCenteredCircle(x+0.5*MemorialWidth, y+PedestalHeight+StatueHeight+ColumnCircleRadius, ColumnCircleRadius);
}