#include <iostream>

using namespace std;

class Queue {
private:
    const int SIZE = 100;
    int *queue;
    int frnt, rear;

public:
    Queue() {
        queue = new int[SIZE];
        frnt = rear = 0;
    }

    ~Queue() {
        delete[] queue;
    }

    //Помещение элемента в очередь
    void push(int num) {
        if (rear + 1 == frnt || (rear + 1 == SIZE && !frnt)) {
            cout << "очередь полна" << endl;
            return;
        }
        rear++;
        if (rear == SIZE) rear = 0;
        queue[rear] = num;
    }

    //Вывод элементов очереди
    void out() {
        for (int i = frnt + 1; i < rear + 1; i++)
            cout << " " << queue[i];
    }

    //Определение размера очереди
    int size() {
        int s = 0;
        for (int i = frnt; i < rear; i++)
            s++;
        return s;
    }

    // Извлечение элемента из очереди
    void pop() {
        if (frnt == rear) {
            cout << "очередь пуста" << endl;
            return;
        }

        frnt++;
        if (frnt == SIZE) frnt = 0;
    }

    // Последний элемент очереди
    int back() {
        return queue[rear];
    }

    // Первый элемент очереди
    int front() {
        return queue[frnt + 1];
    }

    bool inQueue(int num) {
        for (int i = 0; i < SIZE; ++i) {
            if (queue[i] == num) {
                return true;
            }
        }
        return false;
    }
};
