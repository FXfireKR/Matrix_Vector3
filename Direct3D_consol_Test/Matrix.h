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

	// 역행렬 계산 함수
	Matrix Inverse();			// 역행렬이 없는경우 항등행렬 반환
	Matrix Transpose();							// 전치행렬
	float Determinant();						// 판별식
	float Cofactor(int row, int col);			// 여인수
	float Minor(int row, int col);				// 소행렬
	Matrix Adjoint();							// 수반행렬

	Matrix operator+(Matrix& mtx);
	Matrix operator-(Matrix& mtx);
	//Matrix operator*(Matrix& mtx2);
};