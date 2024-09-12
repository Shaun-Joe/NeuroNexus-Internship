#include "calculator.h"

int main()
{
    string input1, input2;
    double num1, num2;
    char operation;

    cout << "Welcome to the Simple Calculator!" << endl;

    cout << "Enter the first number: ";
    getline(cin, input1);

    if (!isValidDouble(input1, num1))
    {
        cout << "Invalid input. Please enter a valid number." << endl;
        return 1;
    }

    cout << "Enter the second number: ";
    getline(cin, input2);

    if (!isValidDouble(input2, num2))
    {
        cout << "Invalid input. Please enter a valid number." << endl;
        return 1;
    }

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation)
    {
    case '+':
        add(num1, num2);
        break;
    case '-':
        subtract(num1, num2);
        break;
    case '*':
        multiply(num1, num2);
        break;
    case '/':
        divide(num1, num2);
        break;
    default:
        cout << "Invalid operation. Please choose +, -, *, or /." << endl;
        return 1;
    }

    return 0;
}
