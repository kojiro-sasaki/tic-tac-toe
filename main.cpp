#include <iostream>
#include "board.h"
#include "game.h"
#include "bot.h"

int main() {
    char board[3][3];
    char player{ 'X' };

    int winsPlayer{};
    int winsBot{};
    int draws{};

    while (true) {

        for (int i{}; i < 3; i++) {
            for (int j{}; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        player = 'X';

        while (true) {
            printBoard(board);

            if (player == 'X') {
                int row{}, col{};
                std::cout << "Player " << player << " (Row Col 1-3): ";
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

            if (checkWin(board, player)) {
                printBoard(board);
                if (player == 'X') {
                    winsPlayer++;
                }
                else {
                    winsBot++;
                }
                break;
            }

            if (isFull(board)) {
                printBoard(board);
                draws++;
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        std::cout << "\nSCORE\n";
        std::cout << "Player: " << winsPlayer << "\n";
        std::cout << "Bot   : " << winsBot << "\n";
        std::cout << "Draws : " << draws << "\n";

        char again{};
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;

        if (again != 'y' && again != 'Y') {
            break;
        }
    }

    return 0;
}
