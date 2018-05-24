#pragma once

#include <iostream>
#include"Date.h"
#include"Person.h"
using namespace std;

class Book {
private:
	string author;
	string name;
	string publishing_house;
	unsigned short year;
	unsigned short number_pages;
	Date output_Book;
	Date input_Book;
	Person children;

public:
	//����������� �� ���������
	Book();
	//����������
	~Book();
	//����������� �����������
	Book(const Book& tmp);
	//������������� ����������� �������������
	Book(const string author, const string name, const string publishing_house, unsigned short year, unsigned short number_pages);
	//������������� ����������� � ����� ����������
	explicit Book(unsigned short number_pages);
	//����� ������
	void show() const;
	//����� ������ ������
	void showAuthor(const string author);
	//����� ������ ������������
	void showPublishing_house(const string publishing_house);
	//����� ������ ���� �������
	void showYear(unsigned short year);
	//������ ����� ������
	void setAuthor(const string author);
	//������ ����� �����
	void setName(const string name);
	//������ ����� ������������
	void setPublishing_house(const string publishing_house);
	//������ ����� ���� �������
	void setYear(unsigned short year);
	//������ ����� ����������� �������
	void setNumber_pages(unsigned short number_pages);
	//������ ����� ���� ������
	void setoutput_Book(Date time);
	//������ ����� ���� ������
	void setinput_Book(Date time);
	//������ ����� ��������
	void setchildren(Person children);
	//������ ������ ������
	const string getAuthor()const;
	//������ ������ �����
	const string getName()const;
	//������ ������ ������������� ����
	const string getPublishing_house()const;
	//������ ������ ���� �������
	unsigned short getYear()const;
	//������ ������ ����������� �������
	unsigned short getNumber_pages()const;
	//������ ������ ����������� ����
	int count_Day();
	//������ ������ ��������
	Person getperson();
};

