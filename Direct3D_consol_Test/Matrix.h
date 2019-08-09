#pragma once
//4 by 4 Matrix
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

#define MATRIX_COL	4
#define MATRIX_ROW	4

class Matrix
{
	friend ostream& operator<< (ostream& c, const Matrix& mtx);
	friend Matrix operator*(Matrix& mtx1, Matrix& mtx2);

public:
	float elem[MATRIX_COL][MATRIX_ROW];

public:
	Matrix();
	Matrix(float matrix[MATRIX_COL][MATRIX_ROW]);
	~Matrix();

	static Matrix Identity();
	void Random();
	void Print();

	/*
	0 0 0 0
	0 0 0 0
	0 0 0 0
	0 0 0 0
	*/

	// ����� ��� �Լ�
	Matrix Inverse();			// ������� ���°�� �׵���� ��ȯ
	Matrix Transpose();							// ��ġ���
	float Determinant();						// �Ǻ���
	float Cofactor(int row, int col);			// ���μ�
	float Minor(int row, int col);				// �����
	Matrix Adjoint();							// �������

	Matrix operator+(Matrix& mtx);
	Matrix operator-(Matrix& mtx);
	//Matrix operator*(Matrix& mtx2);
};