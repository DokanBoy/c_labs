#include <algorithm>
#include <vector>

class BinaryHeap {
private:
    std::vector<int> *heap;

    void heapify(int i) {
        int leftChild;
        int rightChild;
        int largestChild;

        for (;;) {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < heap->size() && heap->at(leftChild) > heap->at(largestChild)) {
                largestChild = leftChild;
            }

            if (rightChild < heap->size() && heap->at(rightChild) > heap->at(largestChild)) {
                largestChild = rightChild;
            }

            if (largestChild == i) {
                break;
            }

            std::swap(heap->at(i), heap->at(largestChild));
            i = largestChild;
        }
    }

public:
    BinaryHeap() {
        heap = new std::vector<int>();
    }

    ~BinaryHeap() {
        heap->clear();
    }

    void add(int value) {
        heap->push_back(value);

        int i = heap->size() - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && heap->at(parent) < heap->at(i)) {
            std::swap(heap->at(i), heap->at(parent));

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    int getMaxAndRemove() {
        int result = heap->at(0);
        heap->at(0) = heap->at(heap->size() - 1);
        heap->erase(heap->begin() + heap->size() - 1);

        return result;
    }

    int getMax() {
        return heap->at(0);
    }

    int getHeapSize() {
        return heap->size();
    }

    void buildHeap(std::vector<int> *sourceVec) {
        heap = sourceVec;
        for (int i = heap->size() / 2; i >= 0; i--) {
            heapify(i);
        }
    }
};
