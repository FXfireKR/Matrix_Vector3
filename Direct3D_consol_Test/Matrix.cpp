#include "Matrix.h"

Matrix::Matrix(){}

Matrix::Matrix(float matrix[MATRIX_COL][MATRIX_ROW])
{
	for (int i = 0; i < MATRIX_COL*MATRIX_ROW; ++i)
		elem[i / MATRIX_COL][i % MATRIX_ROW] = matrix[i / MATRIX_COL][i % MATRIX_ROW];
}

Matrix::~Matrix(){}

Matrix Matrix::Identity()
{
	float mtx[4][4] = { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1} };	//Identity Matrix
	return Matrix(mtx);
}

void Matrix::Random()
{
	for (int i = 0; i < MATRIX_COL*MATRIX_ROW; ++i)
		elem[i / MATRIX_COL][i % MATRIX_ROW] = rand() % 10;
}

void Matrix::Print()
{
	cout << "[ Matrix Information ]" << endl;

	for (int i = 0; i < MATRIX_COL; ++i){
		for (int j = 0; j < MATRIX_ROW; ++j) {
			cout << elem[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::Inverse()
{
	//4 x 4 Matrix Fix
	float det = Determinant();
	
	Matrix mtx(Adjoint().elem);

	for (int i = 0; i < MATRIX_COL; ++i) {
		for (int j = 0; j < MATRIX_ROW; ++j) {
			mtx.elem[i][j] *= det;
		}
	}

	if (det < EPSILON && det >(-EPSILON))
		return Matrix::Identity();
	return mtx;
}

Matrix Matrix::Transpose()
{
	Matrix mtx;

	for (int i = 0; i < MATRIX_COL; ++i)
		for (int j = 0; j < MATRIX_ROW; ++j)
			mtx.elem[i][j] = elem[j][i];
		
	return mtx;
}

float Matrix::Determinant()
{
	float det = 0.0f;
	int fixCol = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (elem[fixCol][i] < EPSILON)
			continue;

		det += elem[fixCol][i] * Cofactor(i, fixCol);

		//cout << elem[i][fixCol] * Cofactor(i, fixCol) << endl;
	}

	if (det < EPSILON && det > -EPSILON)
		return 0.0f;
	return (float)(1/det);
}

float Matrix::Cofactor(int row, int col)
{
	//cout << ((row + col) % 2 ? -1 : 1) * Minor(row, col) << " is Cofactor" << endl;
	return ((row + col) % 2 ? -1 : 1) * Minor(row, col);
}

float Matrix::Minor(int row, int col)
{
	Matrix mtx;
	Matrix mtx2;
	int ii, jj;
	ii = jj = 0;

	//3X3 행렬로 변환
	for (int i = 0; i < MATRIX_COL; ++i) {
		for (int j = 0; j < MATRIX_ROW; ++j) {

			mtx.elem[i][j] = 0;
			mtx2.elem[i][j] = 0;

			if (i == col || j == row)continue;

			mtx.elem[ii][jj] = elem[i][j];

			++jj;
			if (jj > 2)
			{
				++ii;
				jj = 0;
			}
		}
	}
	ii = jj = 0;
	//cout << mtx << endl;

	float det = 0.0000f;
	//get Det

	//cout << "getConf" << endl;
	for (int i = 0; i < 3; ++i)
	{
		if (mtx.elem[0][i] < EPSILON &&  mtx.elem[0][i] > -EPSILON)
			continue;

		//get Confactor
		float Confactor = 0.0000f;
		//cout << i << " get Confactor" << endl;
		ii = jj = 0;
		//2x2 행렬로 변환
		for (int k = 0; k < 3; ++k) {
			for (int l = 0; l < 3; ++l) {

				if (k == 0 || l == i) continue;

				mtx2.elem[ii][jj] = mtx.elem[k][l];

				++jj;
				if (jj > 1)
				{
					++ii;
					jj = 0;
				}
			}
		}
		//cout << mtx2 << endl;

		Confactor = (i % 2 ? -1 : 1) * (mtx2.elem[0][0] * mtx2.elem[1][1] - mtx2.elem[0][1] * mtx2.elem[1][0]);
		det += mtx.elem[0][i] * Confactor;
	}

	return det;
}

Matrix Matrix::Adjoint()
{
	Matrix adj;
	Matrix mtx;
	Matrix mtx2;
	int ii, jj;
	ii = jj = 0;

	float Confactor = 0.0000f;
	float det = 0.0000f;

	for (int col = 0; col < MATRIX_COL; ++col) {
		for (int row = 0; row < MATRIX_ROW; ++row) {
			//adj.elem[col][row]

			//3X3 행렬로 변환
			for (int i = 0; i < MATRIX_COL; ++i) {
				for (int j = 0; j < MATRIX_ROW; ++j) {

					mtx.elem[i][j] = 0;
					mtx2.elem[i][j] = 0;

					if (i == col || j == row)continue;

					mtx.elem[ii][jj] = elem[i][j];

					++jj;
					if (jj > 2)
					{
						++ii;
						jj = 0;
					}
				}
			}
			ii = jj = 0;

			//cout << mtx << endl;
			det = 0.0000f;
			adj.elem[col][row] = 0;

			for (int i = 0; i < 3; ++i)
			{
				if (mtx.elem[0][i] < EPSILON &&  mtx.elem[0][i] > -EPSILON) 
					continue;

				ii = jj = 0;
				//2x2 행렬로 변환
				for (int k = 0; k < 3; ++k) {
					for (int l = 0; l < 3; ++l) {

						if (k == 0 || l == i) continue;

						mtx2.elem[ii][jj] = mtx.elem[k][l];

						++jj;
						if (jj > 1)
						{
							++ii;
							jj = 0;
						}
					}
				}

				//cout << mtx2 << endl;

				Confactor = (i % 2 ? -1 : 1) * (mtx2.elem[0][0] * mtx2.elem[1][1] - mtx2.elem[0][1] * mtx2.elem[1][0]);

				//cout << mtx.elem[0][i] << " * " << Confactor << endl;
				det += mtx.elem[0][i] * Confactor;
				//cout << "minor :: " << mtx.elem[0][i] * Confactor << endl;
				//cout << "det :: " << det << endl;
				adj.elem[col][row] = ((col + row) % 2 ? -1 : 1) * det;
			}

			ii = jj = 0;
			//cout << adj.elem[col][row] << endl;
		}
	}

	return adj.Transpose();
}

Matrix Matrix::operator+(Matrix & mtx)
{
	Matrix rt;
	for (int i = 0; i < MATRIX_COL; ++i) 
		for (int j = 0; j < MATRIX_ROW; ++j) 
			rt.elem[i][j] = elem[i][j] + mtx.elem[i][j];
	
	return rt;
}

Matrix Matrix::operator-(Matrix & mtx)
{
	Matrix rt;
	for (int i = 0; i < MATRIX_COL; ++i)
		for (int j = 0; j < MATRIX_ROW; ++j)
			rt.elem[i][j] = elem[i][j] - mtx.elem[i][j];

	return rt;
}

//Matrix Matrix::operator*(Matrix & mtx)
//{
//	Matrix rt;
//	for (int i = 0; i < MATRIX_COL; ++i) {
//		for (int j = 0; j < MATRIX_ROW; ++j) {
//
//			rt.elem[i][j] = 0.000f;
//
//			for (int ii = 0; ii < MATRIX_COL; ++ii)
//			{
//				rt.elem[i][j] += (float)((double)elem[i][ii] * (double)mtx.elem[ii][j]);
//				//cout << elem[i][ii] * mtx.elem[ii][j] << endl;
//			}
//
//			if (rt.elem[i][j] < EPSILON && rt.elem[i][j] > -EPSILON)
//				rt.elem[i][j] = 0;
//		}
//	}
//
//	return rt;
//}

ostream & operator<<(ostream & c, const Matrix & mtx)
{
	//c << " [ Matrix Information ]" << endl;

	for (int i = 0; i < MATRIX_COL; ++i) {
		c << "\t";
		for (int j = 0; j < MATRIX_ROW; ++j) {
			c << mtx.elem[i][j] << " ";
		}
		c << endl;
	}

	return c;
}

Matrix operator*(Matrix& mtx1, Matrix& mtx2)
{
	Matrix rt;
	for (int i = 0; i < MATRIX_COL; ++i) {
		for (int j = 0; j < MATRIX_ROW; ++j) {

			rt.elem[i][j] = 0.000f;

			for (int ii = 0; ii < MATRIX_COL; ++ii)
			{
				rt.elem[i][j] += (float)((double)mtx1.elem[i][ii] * (double)mtx2.elem[ii][j]);
				//cout << elem[i][ii] * mtx.elem[ii][j] << endl;
			}

			if (rt.elem[i][j] < EPSILON && rt.elem[i][j] > -EPSILON)
				rt.elem[i][j] = 0;
		}
	}

	return rt;
}