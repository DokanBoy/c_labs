#include <iostream>
#include "Queue.cpp"
#include "LinkedList.cpp"
#include "StackCalculator.cpp"

/**
 * Примеры использования
 */
int main() {
    auto *calculator = new StackCalculator("21 + (2341 * (2 * 2) + 3 / (1 + 2)) * 2"); // Принимает любую строку

    delete calculator;
    return 0;
}



