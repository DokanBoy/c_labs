#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include "LinkedList.cpp"

/**
 * Примеры использования односвязного списка и стэка
 */
int main() {
    LinkedList *list = new LinkedList();
    list->appendEnd(123);
    list->appendEnd(456);
    list->appendFirst(789);
    list->printer();

    delete list;

    Stack *stack = new Stack();
    stack->push(10);
    stack->push(5);
    stack->push(6);
    stack->push(7);
    stack->push(3);
    stack->push(8);
    stack->push(1);
    stack->printer();

    delete stack;

    Queue *queue = new Queue();
    queue->push(123);
    queue->push(321);
    queue->push(456);
    std::cout << queue->front();
    queue->back();
    std::cout << queue->back();
    if (queue->inQueue(123)) {
        std::cout << "DA EST" << std::endl;
    } else {
        std::cout << "NET" << std::endl;
    }

    std::cout << queue->size();

    delete queue;

    return 0;
}



