#include <algorithm>
#include <iostream>

class Queen {
private:
    int board[8][8]{};

    void set(unsigned int x, unsigned int y) {
        for (int i = 0; i < 8; ++i) {
            ++board[i][y];
            ++board[x][i];
            int diagonal;
            diagonal = y - x + i;
            if (diagonal >= 0 && diagonal < 8) {
                ++board[i][diagonal];
            }
            diagonal = y + x - i;
            if (diagonal >= 0 && diagonal < 8) {
                ++board[i][diagonal];
            }
        }
        board[x][y] = -1;
    }

    void reset(unsigned int x, unsigned int y) {
        for (int i = 0; i < 8; ++i) {
            --board[i][y];
            --board[x][i];
            int diagonal;
            diagonal = y - x + i;
            if (diagonal >= 0 && diagonal < 8) {
                --board[i][diagonal];
            }
            diagonal = y + x - i;
            if (diagonal >= 0 && diagonal < 8) {
                --board[i][diagonal];
            }
        }
        board[x][y] = 0;
    }

    bool tryMove(unsigned int i = 0) {
        if ((0 > i) || (i > 7)) {
            std::cerr << "The value must be in [0..7]";
            exit(0);
        }

        bool result = false;
        for (int y = 0; y < 8; ++y) {
            if (board[i][y] == 0) {
                set(i, y);
                if (i == 7) {
                    result = true;
                } else {
                    if (!(result = tryMove(i + 1)))
                        reset(i, y);
                }
            }
            if (result) // все ферзи расставлены
                break;
        }
        return result;
    }

public:
    /**
     * Correctly answer:
     *  Q  .  .  .  .  .  .  .
     *  .  .  .  .  Q  .  .  .
     *  .  .  .  .  .  .  .  Q
     *  .  .  .  .  .  Q  .  .
     *  .  .  Q  .  .  .  .  .
     *  .  .  .  .  .  .  Q  .
     *  .  Q  .  .  .  .  .  .
     *  .  .  .  Q  .  .  .  .
     */
    Queen() {
        for (auto &x : board) // инициализируем матрицу
            for (int &y : x)
                y = 0;

        tryMove();

        std::cout << std::endl;
        std::cout << "Output: " << std::endl;

        for (auto &i : board) {
            for (int j : i) {
                if (j == -1) {
                    std::cout << "Q  ";
                } else {
                    std::cout << ".  ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    ~Queen() {
        for (auto x : board) // удаляем матрицу
            delete[] x;
    }
};
