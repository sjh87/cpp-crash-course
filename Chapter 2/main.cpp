#include <iostream>

enum Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Operation operation;

    Calculator(Operation op) {
        operation = op;
    }

    int calculate(int x, int y) {
        switch (operation) {
            case Operation::Add:
                return x + y;
            case Operation::Subtract:
                return x - y;
            case Operation::Multiply:
                return x * y;
            case Operation::Divide:
                if (y) return x / y;
                return x;
            default:
                return 0;
        }
    }
};

int main(void) {
    Calculator *calculator = new Calculator(Operation::Divide);

    std::cout << "The result is " << calculator->calculate(5, 0);

    free(calculator);

    return 0;
}
