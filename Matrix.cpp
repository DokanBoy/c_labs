#include "Stack.cpp"

template<typename T>
class Matrix {
private:
    Stack<Stack<T>> *matrix{};

public:
    Matrix() {
        matrix = new Stack<Stack<T>>();
    }

    Stack<T> *getMatrix() {
        return matrix;
    }

    Stack<T> getRowByIndex(unsigned int index) {
        return matrix->getByIndex(index);
    }

    void pushRow(Stack<T> &row) {
        matrix->push(row);
    }

    Stack<T> top() {
        matrix->top();
    }

    Stack<T> pop() {
        matrix->pop();
    }
};