#include <iostream>
//#include "PriorityQueue.cpp"
#include "PriorityQueueV2.cpp"
#include <ctime>

/**
 * Примеры использования
 */


int main() {
    using namespace std;

    auto pq = new PriorityQueueV2();
    int start, end;

    start = clock();

    for (int i = 0; i < 30000000; ++i) {
        pq->push(rand());
    }

    end = clock();
    cout << "PUSH x30M: " << end - start << "ms" << endl;


    start = clock();

    pq->pop();

    end = clock();
    cout << "#1 POP x1: " << end - start << "ms" << endl;


    start = clock();

    pq->pop();

    end = clock();
    cout << "#2 POP x1: " << end - start << "ms" << endl;

    start = clock();

    pq->pop();

    end = clock();
    cout << "#3 POP x1: " << end - start << "ms" << endl;
    return 0;
}



