#include "stdafx.h"
#include "Book.h"
#include<iostream>
#include<string>


Book::Book()
{
	author = nullptr;
	name = nullptr;
	publishing_house = nullptr;
	year = 0;
	number_pages = 0;

}


Book::~Book()
{
}

Book::Book(const Book & tmp)
{
	author=tmp.author;
	name = tmp.name;
	publishing_house = tmp.publishing_house;
	year = tmp.year;
	number_pages = tmp.number_pages;
}

Book::Book(const string author, const string name, const string publishing_house, unsigned short year, unsigned short number_pages)
{
	this->author = author;
	this->name = name;
	this->number_pages = number_pages;
	this->publishing_house = publishing_house;
	this->year = year;
}

Book::Book(unsigned short number_pages)
{
	this->number_pages = number_pages;
}

void Book::show() const
{
	cout << "Author - " << author << endl;
	cout << "Name - " << name << endl;
	cout << "Publishing house - " << publishing_house << endl;
	cout << "Year - " << year << endl;
	cout << "Number pages - " << number_pages << endl;
}

void Book::showAuthor(const string author)
{
	cout << "Author - " << author << endl;
}

void Book::showPublishing_house(const string publishing_house)
{
	cout << "Publishing house - " << publishing_house << endl;
}

void Book::showYear(unsigned short year)
{
	cout << "Year - " << year << endl;
}

void Book::setAuthor(const string author)
{
	this->author = author;
}

void Book::setName(const string name)
{
	this->name = name;
}

void Book::setPublishing_house(const string publishing_house)
{
	this->publishing_house = publishing_house;
}

void Book::setYear(unsigned short year)
{
	this->year = year;
}

void Book::setNumber_pages(unsigned short number_pages)
{
	this->number_pages = number_pages;
}

void Book::setoutput_Book(Date time)
{
	this->output_Book = time;
}

void Book::setinput_Book(Date time)
{
	this->input_Book = time;
}

void Book::setchildren(Person children1)
{
	this -> children = children1;
}

const string Book::getAuthor() const
{
	return author;
}

const string Book::getName() const
{
	return name;
}

const string Book::getPublishing_house() const
{
	return publishing_house;
}

unsigned short Book::getYear() const
{
	return year;
}

unsigned short Book::getNumber_pages() const
{
	return number_pages;
}

int Book::count_Day()
{
	return output_Book- input_Book;
}

Person Book::getperson()
{
	return children;
}
