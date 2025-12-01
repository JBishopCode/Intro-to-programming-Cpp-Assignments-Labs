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
	Vector() : numcomponents(N) {  //initialize a new N dimensional vector with all coordinates = 0
		for (int i = 0; i < N; ++i){
			components[i] = T{}; 
		}
	}

	// copy constructor
	Vector(const Vector<T,N>& other){ //create a new vector as a copy of an existing one
		numcomponents = other.numcomponents;
		for (int i = 0; i < N; ++i){
			components[i] = other.components[i];
		}
	}

	// dot product with other Vector v
	T dot( Vector<T,N> &v){ //compute the dot product beween this vector and another vector of the same dimension
		T acc{};
		for (int i = 0; i < N; ++i){
			T product = components[i] * v[i];
			acc += product;
		}
		return acc;
	}

	// magnitude of this Vector
	double magnitude(){ //Return the Euclidean length of this vector 
		double acc = 0.0;
		for (int i = 0; i < N; ++i){
			double dubcomp = static_cast<double>(components[i]);
			double square = dubcomp * dubcomp;
			acc += square;
		}
		double mag = sqrt(acc);
		return mag;
	}

	// overloaded indexing operator (initial index is 0)
	T& operator[](int index){ //Provide read and write access to a component by index
		return components[index];
	}

	// Overloaded addition operator
	Vector<T,N> operator+( const Vector<T,N> v2){ //produce a new vector equal to the elemntwise sum of this vector and v2
		Vector<T,N> vsum;
		for (int i = 0; i < N; ++i){
			vsum.components[i] = this->components[i] + v2.components[i];
		}
		return vsum;
	}

	// Overloaded subtraction operator
	Vector<T,N> operator-( const Vector<T,N> v2){ //produce a new vector equal to the elementwise difference of this vector and v2
		Vector<T,N> vdiff;
		for (int i = 0; i < N; ++i){
			vdiff.components[i] = this->components[i] - v2.components[i];
		}
		return vdiff;
	}

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
