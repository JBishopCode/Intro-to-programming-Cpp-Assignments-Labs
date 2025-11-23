//programs once and includes Vector.cpp for its base class
#pragma once
#include "Vector.hpp"

//creates class Vector3 inheriting from Vector<T,N> with its number of dimensions set to 3
template <typename T>
class Vector3 : public Vector<T,3>
{
public:

	//only function required (constructors are from Vector<3,T>)
	//the cross product method.
	Vector3 cross(Vector3 v);
};

