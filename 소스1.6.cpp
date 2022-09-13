#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5



class Matrix {
private:
	int rows, cols;
	int* data;
public:
	Matrix(int r, int c);
	int get_data();
	int show_data();
	int sort_data();
	int addMatrix(Matrix&);
	int MultiplyMatrix(Matrix&, Matrix&);
};

/* 행렬이 여러 개일 때 하나의 function으로 처리하는 방법을 고안
int get_data(int p[][ACOLS], int n)//int get_data()를 Matrix의 멤버 함수로 구현

{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < ACOLS; j++)
			p[i][j] = rand( ) % (n * n);
	return 1;
}

void show_data(int(*p)[ACOLS], int n) //Matrix의 멤버 함수로 구현
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}
}

void multiply(int matrixA[ ][ACOLS], int ar, int matrixB[ ][BCOLS], int br, int matrixC[ ][CCOLS], int cr) {

}
*/

int main(void)

{
	Matrix matrixA(AROWS, ACOLS);
	Matrix matrixA1(AROWS, ACOLS);
	Matrix matrixB(BROWS, BCOLS);
	Matrix matrixC(CROWS, CCOLS);

	srand(time(NULL));

	/*
	get_data(matrixA, AROWS);//matrixA.get_data();
	show_data(matrixA, AROWS);
	get_data(matrixB, AROWS);//matrixB.get_data();
	show_data(matrixB, AROWS);

	multiply(matrixA, AROWS, matrixB, BROWS, matrixC, CROWS);
	show_data(matrixC, AROWS);
	*/

	matrixA.get_data();
	matrixA.show_data();
	matrixA.sort_data();
	matrixA.addMatrix(matrixA1);
	matrixB.get_data();
	matrixB.show_data();

	system("pause");
	return 0;
}

int Matrix::get_data()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = rand() % (rows * rows);
	return 1;
}

int Matrix::show_data()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d", data[i][j]);
		printf("\n");
	}
	return 1;
}

int Matrix::sort_data()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		}
	}

}

int Matrix::addMatrix(Matrix matrix)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] += matrix.data[i][j];

	show_data();

	return 1;
}

int Matrix::MultiplyMatrix(Matrix matrixM, Matrix matrixN)
{
	Matrix matrixP;

	int sum;

	for (int i = 0; i < matrixM.rows; i++)
	{
		for (int j = 0; j < matrixN.cols; j++)
		{
			sum = 0;
			for (int k = 0; k < matrixM.cols; k++)
				sum += matrixM.data[i][k] * matrixN.data[k][j];
		}
		matrixP.data[i][j] = sum;
	}

	matrixP.show_data();

	return 1;
}