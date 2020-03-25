#include "Stack.cpp"
#include <string>
#include <regex>

/**
 * Стэковый калькулятор
 *
 * @see https://www.youtube.com/watch?v=Vk-tGND2bfc&t=175s
 */
class StackCalculator {
private:
    Stack<int> *nums{};
    Stack<char> *operators{};

    const std::string DEBUG_LOG = "DEBUG: ";

    void parse(const std::string &expression) {
        std::string builder{};
        bool prev = false; // Предыдущий символ - число?


        for (int i = 0; i < expression.length(); ++i) {
            if (isNum(expression[i])) {
                builder.append(&expression[i]);
                prev = true;
                //std::cout << DEBUG_LOG << expression[i] << "(Line 26) prev = true" << std::endl;
            } else if (isOperator(expression[i])) {
                if (!prev) {
                    //std::cout << DEBUG_LOG << expression[i] << " prev = False (Line 29)" << std::endl;
                    operators->push(expression[i]);
                    prev = false;
                } else {
                    //std::cout << DEBUG_LOG << expression[i] << " prev = True (Line 33)" << std::endl;
                    nums->push(std::stoi(builder));
                    operators->push(expression[i]);
                    builder = "";
                    prev = false;
                }
            } else {
                std::cerr << "Illegal char in " << i << " position! Char: " << expression[i] << std::endl;
                return;
            }
        }
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
};