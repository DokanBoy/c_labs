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

    void print10First() {
        for (int num : *binaryHeap->get10First()) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void print10Middle() {
        for (int num : *binaryHeap->get10Middle()) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void print10Last() {
        for (int num : *binaryHeap->get10Last()) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void print() {
        for (int i = 0; i < binaryHeap->getHeapSize(); ++i) {
            std::cout << binaryHeap->getMax() << " ";
        }
        std::cout << std::endl;
    }
};
