#include "Stack.cpp"
#include <string>
#include <regex>

#define PLUS_MINUS_PRIORITY = 1;
#define MULTIPLICATION_DIVISION_PRIORITY = 2;
#define BRACKETS_PRIORITY = 3;

/**
 * Стэковый калькулятор
 *
 * @see https://www.youtube.com/watch?v=Vk-tGND2bfc&t=175s
 */


class StackCalculator {
private:
    const std::string DEBUG_LOG = "DEBUG: ";

    Stack<int> *nums{};
    Stack<char> *operators{};
    int answer{};

    void parse(const std::string &expression) {
        std::string builder{};
        bool prev = false; // Предыдущий символ - число?

        // Проверка на кол-во скобочек
        //validate(expression);

        // аналог цикла for (int i = 0; i < expression.length(); ++i).
        // В этом цикле, i = expression[i]
        for (const char &i : expression) {
            if (isNum(i)) {
                builder.append(&i);
                prev = true;
                //std::cout << DEBUG_LOG << expression[i] << "(Line 26) prev = true" << std::endl;
            } else if (isOperator(i)) {
                if (!prev) {
                    //std::cout << DEBUG_LOG << expression[i] << " prev = False (Line 29)" << std::endl;
                    operators->push(i);
                    prev = false;
                } else {
                    //std::cout << DEBUG_LOG << expression[i] << " prev = True (Line 33)" << std::endl;
                    nums->push(std::stoi(builder));
                    operators->push(i);
                    builder.clear();
                    prev = false;
                }
            }
        }
        nums->push(std::stoi(builder));
    }
    // TODO
/*    bool validate(const std::string &expression) {
        auto *brackets = new Stack<char>;

        for (char i : expression) {
            if (isBracket(i)) {
                if (!brackets->isEmpty() && )
                brackets->push(i);
            }
        }
        return false;
    }*/

    // Тута считаем из наших стеков
    int calculate() {
        return nums->top();
    }

public:
    StackCalculator() {
        std::cerr << "Not enough parameters" << std::endl;
    }

    explicit StackCalculator(const std::string &inputExpression) {
        if (inputExpression.empty()) {
            std::cerr << "You can't pass an empty string" << std::endl;
            return;
        }

        nums = new Stack<int>();
        operators = new Stack<char>();

        std::cout << "Input expression: " << inputExpression << std::endl;

        parse(inputExpression);
        answer = calculate();

        std::cout << "Num stack: ";
        nums->printer();

        std::cout << "Operators stack: ";
        operators->printer();
    }

    ~StackCalculator() {
        delete nums;
        delete operators;
    }

    // TODO Заменить на regex
    static bool isOperator(char element) {
        //std::regex operatorsRegex("()+-*/");
        //return std::regex_match(element.begin(), element.end(), operatorsRegex);
        return (element == '(') ||
               (element == ')') ||
               (element == '+') ||
               (element == '-') ||
               (element == '*') ||
               (element == '/');
    }

    // TODO Заменить на regex
    static bool isNum(char element) {
        //std::regex numsRegex("[0-9]");
        //return std::regex_match(element.begin(), element.end(), numsRegex);
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

    // TODO Заменить на regex
    static bool isBracket(char element) {
        return (element == '(') ||
               (element == ')');
    }

    [[maybe_unused]] [[nodiscard]] int getAnswer() const {
        return answer;
    }
};