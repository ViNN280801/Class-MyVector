#pragma once
template <class M>
class Matrix
{
private:
	M **ptr;
	int size;
public:
	Matrix();
	Matrix(int length);
	Matrix(M **pt, int size);
	void FillMatrixByKeyboard();
	void RandomFillMatrix();
	void MatrixToString();
	Matrix<M> &operator+(Matrix<M> &obj);
	Matrix<M> &operator-(Matrix<M> &obj);
	Matrix<M> &operator*(Matrix<M> &obj);
	Matrix<M> &operator/(Matrix<M> &obj);
	void SearchMinMaxValue();
	~Matrix();
};

