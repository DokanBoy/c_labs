#include <iostream>

/**
 * @author Zahar
 * @date 15.03.2020
 *
 * Лаба #1
*/
class Stack {
private:
    const int DEFAULT_LENGTH = 5; // Default 100 elements.

    int currentMaxSize = DEFAULT_LENGTH;
    int currentSize = 0;

    int *array = new int[DEFAULT_LENGTH];

    /**
     * Увеличиваем массив на 10 элементов
     */
    void grow() {
        currentMaxSize += 10;
        int *newArray = new int[currentMaxSize];

        for (int i = 0; i < currentSize; ++i) {
            newArray[i] = array[i];
        }
        array = newArray;

        delete[] newArray;
    }

public:
    Stack() {

    }

    Stack(int num) {
        push(num);
    }

    ~Stack() {
        delete[] array;
    }
    // TODO Добавлять в начало, а не конец. Нужен принцип LIFO, а не FIFO
    void push(int num) {
        if (currentSize >= currentMaxSize) {
            grow();
        }

        array[currentSize] = num;
        ++currentSize;
    }

    void pop() {

    }

    /**
     * Печатаем стэк на экран.
     * Просто проходим по каждому эмеленту и если он не nullptr, то печатаем его.
     */
    void printer() {
        for (int i = 0; i < currentSize; ++i) {
            std::cout << array[i];
        }
        std::cout << std::endl;
    }
};
