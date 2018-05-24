#include "stdafx.h"
#include "Person.h"


#include<iostream>
#include<ctime>

// ����������� �� ���������
Person::Person() : yearOfBirth(0), gender(0) {}
//{
//	yearOfBirth = 0;
// 	gender = 0;
//}

// ����������� ������������� �������, ����� � ��������
Person::Person(string lName, string fName, string pName) : Person()
{
	lastName = lName;
	firstName = fName;
	patronymic = pName;
}

// ����� ������������� �������� ���� ��������.
void Person::setYearOfBirth(const int year)
{
	yearOfBirth = year;
}

// ����� ������������� �������� ����.
void Person::setGender(const int intGender)
{
	gender = intGender;
}

// ����� ���������� �������� ���� � ���� �����.
int Person::getGender()
{
	return gender;
}

// ����� ���������� ���������� ��� � ���� �����.
inline int Person::getAge()
{
	struct tm newtime;
	__time64_t seconds = time(NULL);
	_time64(&seconds);
	errno_t err;
	err = _localtime64_s(&newtime, &seconds);
	return newtime.tm_year - yearOfBirth;
}

// ����� ���������� �������, ���, ��������, ���, ��� ��������.
void Person::toString()
{
	cout << "������� - " << lastName;
	cout << " ��� - " << firstName;
	cout << " �������� - " << patronymic<<endl;
	cout << "��� �������� - " << yearOfBirth<<endl;
	cout << "������� - " << getAge()<<endl;
	cout << "��� - " << gender << endl;
}

Person Person::operator=(const Person obj)
{
	lastName=obj.lastName;	// ������� 
	 firstName=obj.firstName;	// ���
	 patronymic=obj.patronymic;	// ��������

	 yearOfBirth=obj.yearOfBirth;	// ��� ��������

	 gender=obj.gender;			// ���
	return *this;
}

// ����������
Person::~Person()
{
}

