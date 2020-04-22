#include <iostream>
#include "PriorityQueueV3Test.cpp"

/**
 * Примеры использования
 */

int main() {
    auto *pqTest = new PriorityQueueV3Test();

    pqTest->testTime();
    pqTest->testCorrectness();

    delete pqTest;
    return 0;
}



