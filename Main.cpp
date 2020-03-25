#include <iostream>
//#include "Stack.cpp"
#include "Queue.cpp"
#include "LinkedList.cpp"
#include "StackCalculator.cpp"

/**
 * Примеры использования
 */
int main() {
    /*LinkedList *list = new LinkedList();
    list->appendEnd(123);
    list->appendEnd(456);
    list->appendFirst(789);
    list->printer();

    delete list;

    Stack<int> *stack = new Stack<int>();
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

    delete queue;*/

    auto *calculator = new StackCalculator("21+2341*(2*2)");

    delete calculator;

    return 0;
}



