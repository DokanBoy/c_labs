#include <iostream>
#include "Matrix.cpp"

/**
 * Примеры использования
 */

int main() {
/*
    auto *calculator = new StackCalculator("21 + (2341 * (2 * 2) + 3 / (1 + 2)) * 2"); // Принимает любую строку

    delete calculator;
*/
    using namespace std;

    auto matrix = new Matrix<int>();
    auto stack1 = new vector<int>();
    auto stack2 = new vector<int>();

    stack1->push_back(123);
    stack1->push_back(456);
    stack1->push_back(789);

    stack2->push_back(789);
    stack2->push_back(456);
    stack2->push_back(123);

    matrix->pushRow(*stack1);
    matrix->pushRow(*stack2);

    matrix->print();

    return 0;
}



