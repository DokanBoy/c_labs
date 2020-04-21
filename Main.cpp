#include <iostream>
#include "PriorityQueue.cpp"

/**
 * Примеры использования
 */


int main() {
    using namespace std;

    auto pq = new PriorityQueue();

    pq->push(10);
    pq->push(12);
    pq->push(3);

    pq->print();

    cout << pq->pop() << " " << endl;
    cout << pq->pop() << " " << endl;
    cout << pq->top() << " " << endl;

    pq->print();

    return 0;
}



