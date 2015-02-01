//
//  main.c
//  ex11tic-tac-toe
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

typedef enum {
    FALSE, TRUE,
} bool;

static void TicTacToe(void);
static void readBoard(char board[3][3]);
static bool isWinningPositionOne(char board[3][3], char player);

int main(int argc, const char * argv[]) {
    TicTacToe();
    return 0;
}


static void TicTacToe(void) {
    char board[3][3];
    readBoard(board);
    printf("%c has won\n", (isWinningPositionOne(board, 'X')) ? 'X': 'O');
}

static void readBoard(char s[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%c", &s[i][j]);
        }
    }
}

static bool isWinningPositionOne(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == player)
            return TRUE;
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == player)
            return TRUE;
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == player) {
        return TRUE;
    } else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == player) {
        return TRUE;
    }
    
    return FALSE;
}



