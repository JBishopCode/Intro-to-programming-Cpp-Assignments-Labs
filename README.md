In this assignment we were tasked to design and implement a set of C++ classes (on header files) that model N dimensional vector algebra using templates and inheritance.

The project defines two main files:

Vector.hpp
Template class that stores N values of type T. Includes a default constructor, copy constructor, indexing operator, addition, subtraction, dot product, magnitude, and formatted output. Each operation handles all N components. All templates are implemented directly in the header.

Vector3.hpp
Derived from Vector<T,3>. Adds a cross product function that computes a new 3D vector from two inputs. The function follows the standard formula using the three components of each vector.

The program used by the autograder creates vectors of different sizes and types, performs arithmetic, and checks each result. This verifies template logic, operator overloading, and correct inheritance behavior for the 3D extension.

How to Build
Place Vector.hpp and Vector3.hpp in the same directory.
Compile using any C++ compiler with standard template support.

Example Usage
A 3D float vector supports operations such as:

Reading and writing components

Adding two vectors

Subtracting two vectors

Computing dot product

Computing magnitude

Computing cross product

Example Output
(1.0, 2.0, 3.0)
Cross: (−3.0, 6.0, −3.0)
Magnitude: 3.74
