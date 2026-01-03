#include <iostream>
#include "board.h"

void printBoard(char board[3][3]) {
    std::cout << "\n";
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---------\n";
    }
    std::cout << "\n";
}

bool isFull(char board[3][3]) {
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
