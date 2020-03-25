#include "Stack.cpp"
#include <string>

/**
 * Стэковый калькулятор
 *
 * @see https://www.youtube.com/watch?v=Vk-tGND2bfc&t=175s
 */
class StackCalculator {
private:
    Stack<int> *nums{};
    Stack<char> *operators{};

    void parse(const std::string &expression) {
        std::string builder;
        bool prev = false; // Предыдущий символ - число?


        for (int i = 0; i < expression.length(); ++i) {
            if (isNum(expression[i])) {
                builder.append(&expression[i]);
                prev = true;
            } else if (isOperator(expression[i])) {
                if (!prev) {
                    operators->push(expression[i]);
                    prev = false;
                } else {
                    nums->push(std::stoi(builder));
                    builder = ""; // Или nullptr?
                    prev = false;
                }
            } else {
                std::cerr << "Illegal char in " << i << " position! Char: " << expression[i] << std::endl;
                return;
                //throw "Illegal expression";
            }
        }
    }

public:
    StackCalculator() {
        throw "Not enough parameters";
    }

    explicit StackCalculator(const std::string &inputExpression) {
        if (inputExpression.empty())
            throw "You can't pass an empty string";

        nums = new Stack<int>();
        operators = new Stack<char>();

        parse(inputExpression);

        nums->printer();
        operators->printer();
    }

    ~StackCalculator() {
        delete nums;
        delete operators;
    }

    // TODO Заменить на regex
    static bool isOperator(char element) {
        return (element == '(') ||
               (element == ')') ||
               (element == '+') ||
               (element == '-') ||
               (element == '*') ||
               (element == '/');
    }

    // TODO Заменить на regex
    static bool isNum(char element) {
        return (element == '0') ||
               (element == '1') ||
               (element == '2') ||
               (element == '3') ||
               (element == '4') ||
               (element == '5') ||
               (element == '6') ||
               (element == '7') ||
               (element == '8') ||
               (element == '9');
    }
};