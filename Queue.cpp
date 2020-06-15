#include "LinkedList.cpp"

template<typename T>
class Queue {
private:
    LinkedList<T> *list{};
public:
    Queue() {
        this->list = new LinkedList<T>();
    }

    void add(T element) {
        list->addLast(element);
    }

    T peak() {
        T data = list->getFirst();
        list->removeFirst();
        return data;
    }

    bool isEmpty() {
        return list->isEmpty();
    }
};
