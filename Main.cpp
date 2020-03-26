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

    auto matrix = new Matrix<int>();

    auto stack1 = new Stack<int>();
    stack1->push(123);
    stack1->push(4123);
    stack1->push(123);
    stack1->push(645);
    stack1->push(45347);

    matrix->pushRow(*stack1);

    auto stack2 = new Stack<int>();
    stack2->push(123);
    stack2->push(4123);
    stack2->push(123);

    matrix->pushRow(*stack2);

    return 0;
}



