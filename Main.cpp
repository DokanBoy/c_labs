#include <iostream>
#include "LinkedList.cpp"
#include "Stack.cpp"

int main() {
/*    auto *list = new LinkedList();
    list->appendEnd(123);
    list->appendEnd(456);
    list->appendFirst(789);
    list->printer();
    delete list;*/

    auto *stack = new Stack();
    stack->push(10);
    stack->push(5);
    stack->push(6);
    stack->push(7);
    stack->push(3);
    stack->push(8);
    stack->push(1);
    stack->printer();

    delete stack;

    return 0;
}
