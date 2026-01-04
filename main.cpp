#include <iostream>
#include <thread>
#include <chrono>
#include "board.h"
#include "game.h"
#include "bot.h"

int main() {
    char board[3][3];
    char player{ 'X' };

    int winsX{};
    int winsO{};
    int draws{};

    int mode{};
    std::cout << "Choose mode:\n";
    std::cout << "1 - Player vs Bot\n";
    std::cout << "2 - Bot vs Bot\n";
    std::cout << "Your choice: ";
    std::cin >> mode;

    const char* nameX{};
    const char* nameO{};

    if (mode == 1) {
        nameX = "Player";
        nameO = "Bot";
    }
    else {
        nameX = "Bot 1";
        nameO = "Bot 2";
    }

    while (true) {

        for (int i{}; i < 3; i++) {
            for (int j{}; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        player = 'X';

        while (true) {
            printBoard(board);

            if (mode == 1) {
                if (player == 'X') {
                    int row{}, col{};
                    std::cout << nameX << " (Row Col 1-3): ";
                    std::cin >> row >> col;

                    row--;
                    col--;

                    if (row < 0 || row > 2 || col < 0 || col > 2) {
                        std::cout << "Wrong input\n";
                        continue;
                    }

                    if (board[row][col] != ' ') {
                        std::cout << "Cell already busy\n";
                        continue;
                    }

                    board[row][col] = player;
                }
                else {
                    botMove(board, 'O', 'X');
                }
            }
            else {
                if (player == 'X') {
                    botMove(board, 'X', 'O');
                }
                else {
                    botMove(board, 'O', 'X');
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }

            if (checkWin(board, player)) {
                printBoard(board);

                if (player == 'X') {
                    winsX++;
                    std::cout << nameX << " WINS!!!\n";
                }
                else {
                    winsO++;
                    std::cout << nameO << " WINS!!!\n";
                }
                break;
            }

            if (isFull(board)) {
                printBoard(board);
                draws++;
                std::cout << "DRAW\n";
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        std::cout << "\nSCORE\n";
        std::cout << nameX << ": " << winsX << "\n";
        std::cout << nameO << ": " << winsO << "\n";
        std::cout << "Draws: " << draws << "\n";

        char again{};
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;

        if (again != 'y' && again != 'Y') {
            break;
        }
    }

    return 0;
}
