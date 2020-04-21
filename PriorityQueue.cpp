#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueue {
private:
    std::vector<int> *queue{};
public:
    PriorityQueue() {
        queue = new std::vector<int>();
    }

    ~PriorityQueue() {
        queue->clear();
    }

    void push(int num) {
        queue->push_back(num);
        std::sort(queue->begin(), queue->end());
    }

    int pop() {
        int temp = queue->back();
        queue->pop_back();

        return temp;
    }

    int top() {
        return queue->back();
    }

    void print() {
        for (int n : *queue) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
};