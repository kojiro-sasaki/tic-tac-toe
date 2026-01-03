#include "bot.h"
#include "game.h"

void botMove(char board[3][3], char botSymbol, char playerSymbol){
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = botSymbol;
                if (checkWin(board, botSymbol)) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = playerSymbol;
                if (checkWin(board, playerSymbol)) {
                    board[i][j] = botSymbol;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = botSymbol;
                return;
            }
        }
    }
}
