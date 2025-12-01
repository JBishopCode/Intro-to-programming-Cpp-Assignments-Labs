#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char operation;

    // Prompt for first number
    std::cout << "Enter first integer: ";
    std::cin >> num1;

    // Prompt for operator
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;

    // Prompt for second number
    std::cout << "Enter second integer: ";
    std::cin >> num2;

    // Perform calculation and display result
    // (Students will implement the logic here using if/else if/switch statements)
     if (operation == '+') {
        int result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (operation == '-') {
        int result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (operation == '*') {
        int result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (operation == '/') {
        if (num2 == 0){
            cout << "Invalid: Cannot divide by 0";
            return 0;
        }
        int result = num1 / num2;
        cout << num1 << " / " << num2 << " = " << result << endl;
    }
    else {
        cout << "The operation you provided is invalid";
    }
   
    return 0;
}


//Then follow the instructions in main.cpp to add the desired functionality to the simple
//calculator to add, multiply, subtract or divide two numbers