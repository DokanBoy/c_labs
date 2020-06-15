#include <iostream>

/**
 * @author Zahar
 * @date 15.03.2020
 *
 * Лаба #3
*/
template<typename T>
class LinkedList {
private:
    /**
    * Вложенный класс, который хранит адрес след. элемента(Node - ноды) и значение текущего.
    * Важно уточнит, что класс хранит именно АДРЕС следущего значения в памяти.
    * А значение(data) - это числовое значение текущего элемента.
    */
    class Node {
    public:
        Node *next{};
        T data{};

        /**
         * @param num значение текущего элемента.
         * Адрес след. элемента устанавливается на nullptr, что означает, что следущего элемента просто не существует.
         */
        explicit Node(T e) {
            data = e;
            next = nullptr;
        }
    };

    /**
    * Создаем первый элемент списка
    */
    Node *first{};
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

    void addFirst(T e) {
        Node *newList = new Node(e);
        newList->next = first;
        first = newList;
    }

    void addLast(T num) {
        if (!first)
            addFirst(num);
        else {
            Node *curr;
            for (curr = first; curr->next; curr = curr->next);

            curr->next = new Node(num);
        }
    }

    T getFirst() {
        return first->data;
    }

    T getLast() {
        for (Node *curr = first; curr; curr = curr->next) {
            if (curr->next == nullptr) {
                std::cout << "getLast: " << curr->data << std::endl;
                printer();
                return curr->data;
            }
        }
    }

    void removeFirst() {
        if (first == nullptr)
            return;

        Node *temp = first;
        first = first->next;

        delete temp;
    }

    bool contains(T e) {
        for (Node *curr = first; curr; curr = curr->next) {
            if (curr->data == e)
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

    bool isEmpty() {
        return first == nullptr;
    }
};

