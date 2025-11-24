//programs once and includes Vector.hpp for its base class
#pragma once
#include "Vector.hpp"

//creates class Vector3 inheriting from Vector<T,N> with its number of dimensions set to 3
template <typename T>
class Vector3 : public Vector<T,3>
{
public:

	//only function required (constructors are from Vector<3,T>)
	//the cross product method.
	Vector3 cross(Vector3 v){
		float a1 = (*this)[0]; //read each componenet from initial vector 
		float a2 = (*this)[1];
		float a3 = (*this)[2];

		float b1 = v[0]; // read each component from v2 vector 
		float b2 = v[1];
		float b3 = v[2];

		float s1 = a2*b3 - a3*b2; // calculate the cross product of each component
		float s2 = a3*b1 - a1*b3;
		float s3 = a1*b2 - a2*b1;

		Vector3 crossed; //create new vector of the new cross product components
		crossed[0] = s1;
		crossed[1] = s2;
		crossed[2] = s3;

		return crossed; // return the cross product vector
	}
};

