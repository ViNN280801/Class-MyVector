#include "stdafx.h"
#include <ctime>
#include <iostream>
#include "MTX.h"

using namespace std;

template<class M>
Matrix<M>::Matrix()
{
	ptr = nullptr;
	size = 0;
}

template<class M>
Matrix<M>::Matrix(int length) :Matrix()
{
	size = length;
	*ptr = new M[size];
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
	cout << "Maximal value = " << max << endl;
}

template<class M>
Matrix<M>::~Matrix()
{
	for (int i = 0; i < size; i++)
		delete[] ptr[i];
	delete[] ptr;

}

//Класс MyVector
template <class T>
class MyVector
{
private:
	T * array_buffer;
	int size;
public:
	MyVector();

	MyVector<T>& operator+= (MyVector<T> &obj);

	template <class U>
	friend ostream& operator<< (ostream &os, const MyVector<U> &obj);

	bool is_empty() const;
	unsigned int get_size() const;

	void push_back(const T &data); // Добавления нового элемента в конец вектора
	void pop_back(); // Удалить последний элемент

	void push_front(const T&data); // Добавления нового элемента в начало вектора
	void pop_front(); // Удалить первый элемент

	~MyVector();
};

//Конструктор по умолчанию
template<class T>
MyVector<T>::MyVector() {
	array_buffer = NULL;
	size = NULL;
}

//Конкатенация массивов
template<class T>
MyVector<T>& MyVector<T>::operator+=(MyVector<T>& obj) {
	T *temp = new T[size + obj.size + 1];

	for (short int i = 0; i < size; i++)
		temp[i] = array_buffer[i];

	for (short int j = size; j < size + obj.size; j++)
		temp[j] = obj.array_buffer[j - size];

	delete[] array_buffer;

	array_buffer = temp;
	size = size + obj.size + 1;
	return *this;
}

//Проверка массива на заполненность
template<class T>
bool MyVector<T>::is_empty() const {
	if (array_buffer != NULL) {
		delete[] array_buffer;
		return false;
	}
	else
		return true;
}

//Возвращение длины массива
template<class T>
unsigned int MyVector<T>::get_size() const {
	return size;
}

//Добавление на последнее место нового элемента в массив
template<class T>
void MyVector<T>::push_back(const T & data) {
	T *temp = new T[size + 1];

	for (short int i = 0; i < size; i++)
		temp[i] = array_buffer[i];

	temp[size] = data;

	delete[] array_buffer;
	array_buffer = temp;
	size = size + 1;
}

//Удаление последнего элемента массива
template<class T>
void MyVector<T>::pop_back() {
	T *temp = new T[size];

	for (short int i = 0; i < size - 1; i++)
		temp[i] = array_buffer[i];

	temp[size] = data;

	delete[] array_buffer;
	array_buffer = temp;
}

//Добавление на 1-ое место нового элемента в массив
template<class T>
void MyVector<T>::push_front(const T & data) {
	T *temp = new T[size + 1];

	for (short int i = 0; i < size; i++)
		temp[i + 1] = array_buffer[i];

	temp[0] = data;

	delete[] array_buffer;
	array_buffer = temp;
}

//Удаление первого элемента массива
template<class T>
void MyVector<T>::pop_front() {
	T *temp = new T[size + 1];

	for (short int i = 0; i < size; i++)
		temp[i] = array_buffer[i + 1];

	delete[] array_buffer;
	array_buffer = temp;
}

//Деструктор по умолчанию
template<class T>
MyVector<T>::~MyVector() {
	delete[] array_buffer;
}

//Перегруженный оператор вывода в поток
template<class U>
ostream & operator<<(ostream & os, const MyVector<U>& obj) {
	for (short int i = 0; i < obj.size - 1; i++)
		os << " " << obj.array_buffer[i];

	return os;
}

int main()
{
	srand(time_t(NULL));

	MyVector<int> first, second;

	for (size_t i = 0; i < 10; i++)
	{
		first.push_front(i);
		second.push_back(i);
	}

	cout << first << endl << endl;
	cout << second << endl << endl;

	first += second;

	cout << first << endl << endl;
	cout << second << endl;

	int length = 2;

	Matrix<int> matr1(length);
	Matrix<int> matr2(length);
	matr1.FillMatrixByKeyboard();
	matr1.MatrixToString();
	matr2.FillMatrixByKeyboard();
	matr2.MatrixToString();

	matr1.RandomFillMatrix();
	matr1.MatrixToString();
	matr2.RandomFillMatrix();
	matr2.MatrixToString();


	//matr1.SearchMinMaxValue();
	//matr1.MatrixToString();

	return 0;
}

