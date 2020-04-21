#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueueV2 {
private:
    std::vector<int> *queue{};
    bool sorted = true;

    bool isSorted() {
        if (queue->size() == 1 || queue->empty()) {
            return true;
        }
        return sorted;
    }

public:
    PriorityQueueV2() {
        queue = new std::vector<int>();
    }

    ~PriorityQueueV2() {
        queue->clear();
    }

    void push(int num) {
        queue->push_back(num);
        sorted = false;
    }

    int pop() {
        if (!isSorted()) {
            std::sort(queue->begin(), queue->end());
            sorted = true;
        }

        int temp = queue->back();
        queue->pop_back();

        return temp;
    }

    int top() {
        if (!isSorted()) {
            std::sort(queue->begin(), queue->end());
            sorted = true;
        }
        return queue->back();
    }

    size_t size() {
        return queue->size();
    }

    void print() {
        if (queue->empty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        if (!isSorted()) {
            std::sort(queue->begin(), queue->end());
            sorted = true;
        }

        for (int n : *queue) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
};