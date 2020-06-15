#include "Queue.cpp"

/**
 * Примеры использования
 */

int main() {
    auto queue = new Queue<int>();
    queue->add(10);
    queue->add(1);
    queue->add(3);
    queue->add(-14);

    while (!queue->isEmpty()) {
        std::cout << queue->peak() << ", ";
    }

    return 0;
}



