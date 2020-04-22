#include <algorithm>
#include "Matrix.cpp"

class Horse {
private:
    Matrix<bool> *board; //отмечаем, где уже был, конь, где ещё нет
    std::vector<int> *moves;//нужно найти 63 хода

    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


public:
    Horse() {
        board = new Matrix<bool>(8);
        moves = new std::vector<int>(63);
    }

    ~Horse() {
        moves->clear();
        delete board;
    }

    int move(int k, int x, int y) {
        if (k == 63) {
            // TODO: Возвращаем 1 + записываем ходы в moves

        } else {
            for (int i = 0; i < 8; ++i) {
                // TODO
                //move(k + 1, .., ..)
            }
        }
        return 0;
    }

    // TODO: Красивый вывод ходов
    void print() {
        board->print();
    }
};
