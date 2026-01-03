#include "game.h"

bool checkWin(char board[3][3], char s) {
    for (int i{}; i < 3; i++) {
        if (board[i][0] == s &&
            board[i][1] == s &&
            board[i][2] == s) {
            return true;
        }
    }

    for (int j{}; j < 3; j++) {
        if (board[0][j] == s &&
            board[1][j] == s &&
            board[2][j] == s) {
            return true;
        }
    }

    if (board[0][0] == s &&
        board[1][1] == s &&
        board[2][2] == s) {
        return true;
    }

    if (board[0][2] == s &&
        board[1][1] == s &&
        board[2][0] == s) {
        return true;
    }

    return false;
}
