#include <iostream> 
#include "Rational.h"

using namespace std;


//CONSTRUCTORS
Rational::Rational(Integer num, Integer den) : numerator(num), denominator(den)
{
    if (denominator == 0){
        cout << "Denominator cannot be 0" << endl; // make sure its not an invalid fraction (divison by 0)
    }
}

Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator){}

Rational::Rational(Rational&& other) : numerator(other.numerator), denominator(other.denominator)
{
    other.denominator = 0; //leave object in a valid state (0/1)
    other.numerator = 1; // makes debugging clearer
}

//ASSIGNMENT
Rational& Rational::operator=(const Rational& other) 
{
    if (this != &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    return *this;
}

Rational& Rational::operator=(const Rational&& other)
{
    numerator = other.numerator; // header uses const rvalue reference, we cant "move from" it
    denominator = other.denominator; // copy the fields instead

    return *this;
}

//ARTHMETIC (value returning)
Rational Rational::operator+(const Rational& rhs)
{
    return Rational(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}

Rational Rational::operator-(const Rational& rhs)
{
    return Rational(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
}

Rational Rational::operator*(const Rational& rhs)
{
    return Rational(numerator * rhs.numerator, denominator * rhs.denominator);
}

Rational Rational::operator/(const Rational& rhs)
{
    if (rhs.numerator == 0) // division by zero rational would create a denominator = 0
    {
        cout << "Division by zero rational" << endl;
    }
    return Rational(numerator * rhs.denominator, denominator * rhs.numerator);
}

// COMPOUND ASSIGNMENT (in place)
Rational& Rational::operator+=(const Rational& rhs) // in place version of '+'
{
    *this = *this + rhs;
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) // in place version of '-'
{
    *this = *this - rhs;
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) // in place version of '*'
{
*this = *this * rhs;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) // in place version of '/'
{
*this = *this / rhs;
    return *this;
}

// UTILITY
double Rational::toDouble() //convert exact fraction to IEEE double
{
    return (static_cast<double>(numerator) / static_cast<double>(denominator));
}

// STREAM
ostream& operator<<(ostream& out, Rational& r) 
{
    return (r.print(out));
}

istream& operator>>(istream& in, Rational& r)
{
    return (r.scan(in));
}
