#include <iostream>

/**
 * @author Zahar
 * @date 15.03.2020
 *
 * Лаба #3
*/
class LinkedList {
private:
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
    Node *first;
public:
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
     * @return получаем значение первого элемента
     * Если него не сущестуем, то возвращаем -91919191
     */
    int getHeadData() {
        if (first == nullptr)
            return -91919191;

        return first->data;
    }

    /**
    * @return получаем удаленный элемент
    * Если него не сущестуем, то возвращаем -91919191
    */
    int removeFirstNode() {
        if (first == nullptr)
            return -91919191;

        Node *temp = first;
        first = first->next;

        delete temp;
        return first->data;
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

    bool inList(int num) {
        for (Node *curr = first; curr; curr = curr->next) {
            if (curr->data == num)
                return true;
        }
        return false;
    }

    /**
     * Печатаем список на экран.
     * Просто проходим по каждому эмеленту и если он не nullptr, то печатаем его.
     */
    void printer() {
        for (Node *curr = first; curr; curr = curr->next) {
            std::cout << curr->data << " ";
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

