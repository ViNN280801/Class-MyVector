#include "stdafx.h"
#include "Matrix.h"
#include <ctime>

template<class M>
Matrix<M>::Matrix()
{
	ptr = NULL;
	size = 0;
}

template<class M>
Matrix<M>::Matrix(int length) :Matrix()
{
	size = length;
	ptr = new M[size];
	for (int i = 0; i < size; i++)
		ptr[i] = new M[size];
}

template<class M>
Matrix<M>::Matrix(M **pt, int size) :Matrix()
{
	this->size = size;

	ptr = new M[size];
	for (int i = 0; i < size; i++)
		ptr[i] = new M[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			ptr[i][j] = pt[i][j];
}

template<class M>
void Matrix<M>::FillMatrixByKeyboard()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cout << "Enter some value: " << endl;
			cin >> ptr[i][j];
		}
}

template<class M>
void Matrix<M>::RandomFillMatrix()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			ptr[i][j] = -50 + rand() % 100;
}

template<class M>
void Matrix<M>::MatrixToString()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d\t", ptr[i][j]);
	}
	cout << endl;
}


template<class M>
Matrix<M> & Matrix<M>::operator+(Matrix<M> & obj)
{
	M **mtx = nullptr;

	mtx = new M[size];
	for (int i = 0; i < size; i++)
		mtx[i] = new M[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mtx[i][j] = this->ptr[i][j] + obj.ptr[i][j];

	Matrix<M> temp(mtx, size);

	for (int i = 0; i < size; i++)
		delete[] mtx[i];
	delete[] mtx;

	return temp;
}

template<class M>
Matrix<M> & Matrix<M>::operator-(Matrix<M> & obj)
{
	M **mtx = nullptr;

	mtx = new M[size];
	for (int i = 0; i < size; i++)
		mtx[i] = new M[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mtx[i][j] = this->ptr[i][j] - obj.ptr[i][j];

	Matrix temp(mtx, size);

	for (int i = 0; i < size; i++)
		delete[] mtx[i];
	delete[] mtx;

	return temp;
}

template<class M>
Matrix<M> & Matrix<M>::operator*(Matrix<M> & obj)
{
	M **mtx = nullptr;

	mtx = new M[size];
	for (int i = 0; i < size; i++)
		mtx[i] = new M[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int inner = 0; inner < size; inner++)
				mtx[i][j] += this->ptr[i][inner] * obj.ptr[inner][j];


	Matrix<M> temp(mtx, size);

	for (int i = 0; i < size; i++)
		delete[] mtx[i];
	delete[] mtx;

	// TODO: insert return statement here
	return temp;
}

template<class M>
Matrix<M>& Matrix<M>::operator/(Matrix<M>& obj)
{
	M **mtx = nullptr;

	mtx = new M[size];
	for (int i = 0; i < size; i++)
		mtx[i] = new M[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int inner = 0; inner < size; inner++)
				mtx[i][j] += pow(this->ptr[i][inner], -1) * obj.ptr[inner][j];


	Matrix<M> temp(mtx, size);

	for (int i = 0; i < size; i++)
		delete[] mtx[i];
	delete[] mtx;

	// TODO: insert return statement here
	return temp;
}

template<class M>
void Matrix<M>::SearchMinMaxValue()
{
	int min = 100, max = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (min > ptr[i][j])
				min = ptr[i][j];
			if (max < ptr[i][j])
				max = ptr[i][j];
		}

	cout << "Minimal value = " << min << endl;
	cout << "Maximal value = " << max 
}


template<class M>
Matrix<M>::~Matrix()
{
	for (int i = 0; i < size; i++)
		delete[] ptr[i];
	delete[] ptr;

}
