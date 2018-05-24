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
	//Констркутор по умолчанию
	Book();
	//Деструктор
	~Book();
	//Конструктор копирования
	Book(const Book& tmp);
	//Перегруженный конструктор инициализации
	Book(const string author, const string name, const string publishing_house, unsigned short year, unsigned short number_pages);
	//Перегруженный конструктор с одним параметром
	explicit Book(unsigned short number_pages);
	//Метод вывода
	void show() const;
	//Метод вывода автора
	void showAuthor(const string author);
	//Метод вывода издательства
	void showPublishing_house(const string publishing_house);
	//Метод выаода даты выпуска
	void showYear(unsigned short year);
	//Сеттер ввода автора
	void setAuthor(const string author);
	//Сеттер ввода Имени
	void setName(const string name);
	//Сеттер ввода издательства
	void setPublishing_house(const string publishing_house);
	//Сеттер ввода года выпуска
	void setYear(unsigned short year);
	//Сеттер ввода колличества страниц
	void setNumber_pages(unsigned short number_pages);
	//Сеттер ввода даты выдачи
	void setoutput_Book(Date time);
	//Сеттер ввода даты приема
	void setinput_Book(Date time);
	//Сеттер ввода человека
	void setchildren(Person children);
	//Геттер вывода Автора
	const string getAuthor()const;
	//Геттер вывода Имени
	const string getName()const;
	//Геттер вывода издательского дома
	const string getPublishing_house()const;
	//Геттер вывода года выпуска
	unsigned short getYear()const;
	//Геттер вывода колличества страниц
	unsigned short getNumber_pages()const;
	//Геттер вывода колличества дней
	int count_Day();
	//Геттер вывода человека
	Person getperson();
};

