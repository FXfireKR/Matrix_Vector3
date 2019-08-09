#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

class Vector
{
	friend float Dot(Vector& v1, Vector& v2);			//Vector Dot Product
	friend Vector Cross(Vector& v1, Vector& v2);		//Vector Cross Product
	friend ostream& operator<< (ostream& c, const Vector& vec);

public:
	float x, y, z;

public:
	Vector();
	Vector(float x, float y, float z);
	~Vector();

	//Operator Overriding
	Vector operator+ (Vector& vec1);
	Vector operator- (Vector& vec1);
	bool operator==(Vector& vec1);
	bool operator!=(Vector& vec1);
};
