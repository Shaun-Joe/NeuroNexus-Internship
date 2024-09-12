#ifndef CALCULATOR_H
#define CALCULATOR_H

    #include <iostream>
    #include <string>
    #include <cctype>

    using namespace std;

    void add(double a, double b);
    void subtract(double a, double b);
    void multiply(double a, double b);
    void divide(double a, double b);
    bool isValidDouble(const string& str, double& number);

#endif