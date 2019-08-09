#include <iostream>
#include <Windows.h>
using namespace std;

#include "Vector.h"
#include "Matrix.h"

int main(){

	srand((unsigned int)GetTickCount());

	float aa[4][4] = { {1,0,3,7},{4,2,0,1}, {7,7,3,0}, {5,0,6,8} };
	//float aa[4][4] = { {1,1,1,1},{1,1,1,1}, {1,1,1,1}, {1,1,1,1} };
	//Matrix m1(Matrix::Identity());
	//Matrix m1(aa);
	Matrix m1;
	m1.Random();
	cout << "[ Random Matrix ]" << m1 << endl;

	Matrix m2(m1.Inverse());
	cout << "[ Inverse Matrix ]\n" << m2 << endl;

	cout << "[  ]" << m1 * m2 << endl;

	system("pause");
	return 0;
}