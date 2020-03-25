#include "Stack.cpp"
#include <string>

class StackCalculator {
private:
    Stack<int> *nums{};
    Stack<char> *operators{};

    void parse(const std::string& expression) {
        std::string builder;
        bool prev = false; // Предыдущий символ число?
        int i = 0;

        while (true) {
            if (isNum((expression[i]))) {
                builder.append(&expression[i]);
                prev = true;
            } else {
                if (!prev) {
                    operators->push(expression[i]);
                    prev = false;
                } else {
                    nums->push(std::stoi(builder));
                    builder = ""; // Или nullptr?
                    prev = false;
                }
            }

            if (expression.size() == i - 1)
                break;
            else
                i++;
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

    static bool isNum(char element) {
        return element == '(' ||
               element == ')' ||
               element == '+' ||
               element == '-' ||
               element == '*' ||
               element == '/';
    }
};