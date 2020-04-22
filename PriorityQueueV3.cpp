#include <vector>
#include <iostream>
#include "BinaryHeap.cpp"

class PriorityQueueV3 {
private:
    BinaryHeap *binaryHeap;
public:
    PriorityQueueV3() {
        binaryHeap = new BinaryHeap();
    }

    void push(int num) {
        binaryHeap->add(num);
    }

    int pop() {
        binaryHeap->getMaxAndRemove();
    }

    int top() {
        binaryHeap->getMax();
    }

    int size() {
        binaryHeap->getHeapSize();
    }

    void print() {
        for (int i = 0; i < binaryHeap->getHeapSize(); ++i) {
            std::cout << binaryHeap->getMax() << " ";
        }
        std::cout << std::endl;
    }
};
