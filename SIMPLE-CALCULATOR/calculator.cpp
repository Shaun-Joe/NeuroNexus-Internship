#include "calculator.h"

void add(double a, double b) {
    cout << "Result: " << a + b << endl;
}

void subtract(double a, double b) {
    cout << "Result: " << a - b << endl;
}

void multiply(double a, double b) {
    cout << "Result: " << a * b << endl;
}

void divide(double a, double b) {
    if (b != 0) {
        cout << "Result: " << a / b << endl;
    } else {
        cout << "Error: Division by zero is not allowed." << endl;
    }
}

bool isValidDouble(const string& str, double& number) {
    size_t idx;
    try {
        number = stod(str, &idx);
        return idx == str.size();
    } catch (...) {
        return false;
    }
}
