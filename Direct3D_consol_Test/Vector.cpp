#include "Vector.h"

Vector::Vector(){}

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z){}

Vector::~Vector(){}

Vector Vector::operator+(Vector & vec1){
	return Vector(x + vec1.x, y + vec1.y, z + vec1.z);
}

Vector Vector::operator-(Vector & vec1){
	return Vector(x - vec1.x, y - vec1.y, z - vec1.z);
}

bool Vector::operator==(Vector & vec1){
	if (x - vec1.x >= EPSILON |
		y - vec1.y >= EPSILON |
		z - vec1.z >= EPSILON)
		return false;
	return true;
}

bool Vector::operator!=(Vector & vec1){
	return (!(*this == vec1));
}

float Dot(Vector& v1, Vector& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector Cross(Vector& v1, Vector& v2) {
	return Vector(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

ostream& operator<< (ostream& c, const Vector& vec) {
	c << "[ Vector Information ]\n" << "X : " << vec.x << "\nY : " << vec.y << "\nZ : " << vec.z << "\n";
	return c;
}