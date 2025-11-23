#pragma once
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "math.h"

// Note in theory we should implement all the "special" functions 
// for this class - making your lives easier by just asking you to
// implement the default and copy constructors.
template <typename T, std::size_t N>
class Vector
{
public:
	// default constructor (initialize all components to 0)
	Vector();

	// copy constructor
	Vector(const Vector<T,N>& other);

	// dot product with other Vector v
	T dot( Vector<T,N> &v);

	// magnitude of this Vector
	double magnitude();

	// overloaded indexing operator (initial index is 0)
	T& operator[](int index);

	// Overloaded addition operator
	Vector<T,N>& operator+( const Vector<T,N>& v2);

	// Overloaded subtraction operator
	Vector<T,N>& operator-( const Vector<T,N>& v2);

	// Overloaded output stream operator
	template <typename U, std::size_t M>
	friend std::ostream& operator<<(std::ostream& os, const Vector<U,M>& v)
	{
		os << "(";
		for (int i = 0; i < N - 1; i++)
		{
			os << v[i] << ", ";
		}
		os << v[N - 1] << ")";
		return os;
	}

private:
	// components of this Vector
	T components[N];

	// number of components in this Vector
	int numcomponents;

};
