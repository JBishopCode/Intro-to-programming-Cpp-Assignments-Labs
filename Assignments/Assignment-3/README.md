In this assignment we were tasked to implement a Rational class that represents fractions using two integers: a numerator and a denominator.

The provided Rational.h file defines the interface and function declarations. Our job was to create the Rational.cpp file and implement all constructors, assignment operators, arithmetic operators (+ - * /), compound operators (+= -= *= /=), stream operators (<< and >> using the given print() and scan() methods), and a toDouble() function. The denominator must never be zero, and the class must behave predictably under arithmetic operations.

No reduction to simplest form is required, and no main function should be included in submission—only Rational.h and the implemented Rational.cpp file.

To test the code locally (not for submission), you can create a small main.cpp file that constructs Rational objects and performs arithmetic or streaming operations.

For example:

Rational a(3, 4), b(5, 6);
cout << a + b;
