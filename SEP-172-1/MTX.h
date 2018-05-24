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
	Matrix &operator+(Matrix &obj);
	Matrix &operator-(Matrix &obj);
	Matrix &operator*(Matrix &obj);
	Matrix &operator/(Matrix &obj);
	void SearchMinMaxValue();
	~Matrix();
};

