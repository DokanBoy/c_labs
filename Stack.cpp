#include <iostream>

/**
 * Стэки
 *
 * @see https://codelessons.ru/cplusplus/realizaciya-steka-stack-v-c.html (в самом низу есть рассказ о реализации,
 * как у меня)
 *
 * Создаем пустой массив, а потом с помощью метода push можно будет запихивать элементы.
 * С помощью pop получаем и удаляем верхний элемент. С помощью top получаем верхний элемент
*/
template<typename T>
class Stack {
private:
    // Начальный размер стэка.
    const int DEFAULT_LENGTH = 100;

    // Текущий размер стэка
    int currentMaxSize = DEFAULT_LENGTH;
    // Текущее кол-во элементов
    int currentSize = 0;

    // тот самый массив, куда будем запихивать новые элементы
    T *array;

    /**
     * Увеличиваем массив на 10 элементов
     */
    void grow() {
        currentMaxSize += 10;
        T *newArray = new T[currentMaxSize];

        for (int i = 0; i < currentSize; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
    
    /**
     * Уменьшаем массив на 10 элементов
     */
    void reduce() {
        // TODO
    }

public:
    /**
     * Конструктор №1 (Конструктор создающий пустой стэк)
    */
    Stack() {
        array = new T[currentMaxSize];
    }

    /**
     * Конструктор №2 (Конструктор принимающий значение первого элемента)
     * @param num - первый элемент
     *
     * Создаем массив и пушим(запихиваем) туда наш первый элемент
    */
    explicit Stack(int size) {
        currentMaxSize = size;
        array = new T[currentMaxSize];
    }

    /**
     * Деструктор. Удаляем массив со стэком
     */
    ~Stack() {
        delete[] array;
    }

    /**
     * @param element элемент, который нужно запихнуть в стэк
     */
    void push(T element) {
        if (currentSize >= currentMaxSize) {
            grow();
        }

        array[currentSize] = element;
        ++currentSize;
    }

    /**
     * Снимаем верхний элемент в стэки
     * Получаем и удаляем(!)
     */
    T pop() {
        return array[--currentSize];
    }

    /**
     * Берем верхний элемент в стэки
     * Получаем без(!) удаления
     */
    T top() {
        int temp = currentSize - 1;
        return array[temp];
    }

    /**
     * Стэк пустой?
     * true - да
     * false - нет
     */
    bool isEmpty() {
        return currentSize == 0;
    }

    /**
     * Печатаем стэк на экран.
     * Проходим по каждому эмеленту и если он не nullptr, то печатаем его.
     */
    void printer() {
        for (int i = 0; i < currentSize; ++i) {
            std::cout << array[i] << " ";;
        }
        std::cout << std::endl;
    }
};
