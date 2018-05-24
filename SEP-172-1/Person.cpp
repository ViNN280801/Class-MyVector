#include "stdafx.h"
#include "Person.h"


#include<iostream>
#include<ctime>

// Конструктор по умолчанию
Person::Person() : yearOfBirth(0), gender(0) {}
//{
//	yearOfBirth = 0;
// 	gender = 0;
//}

// Конструктор инициализации фамилии, имени и отчества
Person::Person(string lName, string fName, string pName) : Person()
{
	lastName = lName;
	firstName = fName;
	patronymic = pName;
}

// Метод устанавливает значение года рождения.
void Person::setYearOfBirth(const int year)
{
	yearOfBirth = year;
}

// Метод устанавливает значение пола.
void Person::setGender(const int intGender)
{
	gender = intGender;
}

// Метод возвращает значение пола в виде числа.
int Person::getGender()
{
	return gender;
}

// Метод возвращает количество лет в виде числа.
inline int Person::getAge()
{
	struct tm newtime;
	__time64_t seconds = time(NULL);
	_time64(&seconds);
	errno_t err;
	err = _localtime64_s(&newtime, &seconds);
	return newtime.tm_year - yearOfBirth;
}

// Метод возвращает фамилию, имя, отчество, пол, год рождения.
void Person::toString()
{
	cout << "Фамилия - " << lastName;
	cout << " Имя - " << firstName;
	cout << " Отчетсво - " << patronymic<<endl;
	cout << "Год рождения - " << yearOfBirth<<endl;
	cout << "Возраст - " << getAge()<<endl;
	cout << "Пол - " << gender << endl;
}

Person Person::operator=(const Person obj)
{
	lastName=obj.lastName;	// Фамилия 
	 firstName=obj.firstName;	// Имя
	 patronymic=obj.patronymic;	// Отчество

	 yearOfBirth=obj.yearOfBirth;	// Год рождения

	 gender=obj.gender;			// Пол
	return *this;
}

// Деструктор
Person::~Person()
{
}

