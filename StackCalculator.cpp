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
    Stack<int> *nums{};
    Stack<char> *operators{};
    int answer{};

    int getOperatorPriority(char element) {
        switch (element) {
            case '(' :
                return 1;
            case ')' :
                return 2;
            case '=' :
                return 3;
            case '+' :
            case '-' :
                return 4;
            case '*' :
            case '/' :
                return 5;
            case '^' :
                return 6;
            default:
                return 0;
        }
    }

    void parse(const std::string &expression) {
        std::string builder{};
        bool prevIsNum = false; // Предыдущий символ - число?

        for (const char &i : expression) {
            if (isNum(i)) {
                builder.append(&i);
                prevIsNum = true;
            } else if (isOperator(i)) {
                if (!prevIsNum) {
                    operators->push(i);
                    prevIsNum = false;
                } else {
                    nums->push(std::stoi(builder));
                    operators->push(i);
                    builder.clear();
                    prevIsNum = false;
                }
            }
        }
        nums->push(std::stoi(builder));
    }

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