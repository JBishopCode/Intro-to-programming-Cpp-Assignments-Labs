In this lab we were tasked to design and implement a C++ program that demonstrates inheritance and polymorphism using a restaurant example.

The program defines several classes:

Restaurant
Base class containing the restaurant name and year opened. Includes constructors, accessors, mutators, and a virtual print() function.

EatInRestaurant
Derived from Restaurant. Adds a variable for the maximum number of patrons and overrides print() to display that information.

DeliveryRestaurant
Derived from Restaurant. Adds a variable for the maximum delivery distance and overrides print() to display that information.

comboRestaurant
Demonstrates how a restaurant could combine both EatIn and Delivery functionality using composition.

The main program dynamically allocates objects of each class type, stores them in an array of Restaurant* pointers, and uses virtual functions to call the correct print() method for each object. This shows how polymorphism and dynamic binding work in C++.

How to Run

Compile the program:

g++ Lab3.cpp -o Lab3


Run the executable:

./Lab3

Example Output
Plain Place (EST. 1999)
TableTop's maximum number of patrons allowed: 80
FastBites's maximum delivery distance is: 15 km
