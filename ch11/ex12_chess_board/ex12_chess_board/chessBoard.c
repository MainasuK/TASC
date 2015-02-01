//
//  chessBoard.c
//  ex12_chess_board
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "chessBoard.h"

static char board[8][8];

void initCheckerBoard(void) {
    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if ((column+row)%2)
                board[row][column] = '-';
            else
                board[row][column] = ' ';
        }
    }
    
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 8; column++) {
            if ((column+row)%2)
                board[row][column] = 'b';
        }
    }
    
    for (int row = 5; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if ((column+row)%2)
                board[row][column] = 'r';
        }
    }
}

void displayCheckerBoard(void) {
    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
                printf("%c ", board[row][column]);
        }
        printf("\n");
    }
}