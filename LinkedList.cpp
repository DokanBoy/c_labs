#include <iostream>

/**
 * @author Zahar
 * @date 15.03.2020
 *
 * Лаба #3
*/
class LinkedList {
public:
    /**
     * Вложенный класс, который хранит адрес след. элемента(Node - ноды) и значение текущего.
     * Важно уточнит, что класс хранит именно АДРЕС следущего значения в памяти.
     * А значение(data) - это числовое значение текущего элемента.
     */
    class Node {
    public:
        Node *next;
        int data;

        /**
         * @param num значение текущего элемента.
         * Адрес след. элемента устанавливается на nullptr, что означает, что следущего элемента просто не существует.
         */
        Node(int num) {
            data = num;
            next = nullptr;
        }
    };

    /**
     * Создаем первый элемент списка
     */
    Node *first{};

    /**
     * Конструктор №1 (Пустой конструктор)
     *
     * Создаем класс-обертку, который будет работать с Node.
     * Значение первого элемента устанавливается на nullptr
     */
    LinkedList() {
        first = nullptr;
    }

    /**
     * Конструктор №2 (Конструктор принимающий значение первого элемента)
     * @param num - первый элемент
     *
     * Создаем класс-обертку, который будет работать с Node.
     * Значение второго элемента устанавливается на nullptr(его отсутсвие).
    */
    LinkedList(int num) {
        first->data = num;
        first->next = nullptr;
    }

    /**
     * Деструктор. Удаляем всю цепочку элменетов массива
     */
    ~LinkedList() {
        Node *currNode;
        while (first) {
            currNode = first;
            first = first->next;
            delete currNode;
        }
    }

    /**
     * @param num число, добавляемое в начало
     *
     * Создаем новый элемент, в после next передаем текущий элемент, а в data - записываем число, переданное в параметре
     */
    void appendFirst(int num) {
        Node *newList = new Node(num);
        newList->next = first;
        first = newList;
    }

    /**
     * @param num число, добавляемое в конец
     *
    */
    void appendEnd(int num) {
        if (!first)
            appendFirst(num);
        else {
            Node *curr;
            for (curr = first; curr->next; curr = curr->next);

            curr->next = new Node(num);
        }
    }

    /**
     * Печатаем список на экран.
     * Просто проходим по каждому эмеленту и если он не nullptr, то печатаем его.
     */
    void printer() {
        for (Node *curr = first; curr; curr = curr->next) {
            std::cout << curr->data;
        }
        std::cout << std::endl;
    }

    /**
    * Узнаем размер списка
    * Просто проходим по каждому эмеленту и если он не nullptr, то увеличиваем счетчик на 1.
    */
    int size() {
        int counter = 0;
        for (Node *curr = first; curr; curr = curr->next) {
            ++counter;
        }
        return counter;
    }
};

