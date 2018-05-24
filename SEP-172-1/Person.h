#pragma once
#include <string>
#include<ctime>

using namespace std;

/*
Класс предназначен для хранения установочных данных студента.
В состав класса входит фамилия имя отчетсво, год рождения, пол
и методы для получения возраста и просмотра членов классов.
version 0.0.001
author
*/

class Person
{
public:
	// Определения пола
	const int MALE = 0;
	const int FEMALE = 1;

private:
	string lastName;	// Фамилия 
	string firstName;	// Имя
	string patronymic;	// Отчество

	int yearOfBirth;	// Год рождения

	int gender;			// Пол

public:
	// Конструктор по умолчанию
	Person();
	// Конструктор инициализации фамилии, имени и отчества
	Person(string lName, string fName, string pName);

	//  ----------- Акцессоры  -----------
	/*
	Метод устанавливает значение года рождения.
	Параметры:
	int year - год рождения
	Возвращаемое значение - void
	*/
	void setYearOfBirth(const int year);
	/*
	Метод устанавливает значение пола.
	Параметры:
	int intGender - значение поля в виде 0 - муж, 1 - жен
	Возвращаемое значение - void
	*/
	void setGender(const int intGender);

	/*
	Метод возвращает значение пола в виде числа.
	Параметры:
	void
	Возвращаемое значение - int пол в виде 0 - муж, 1 - жен
	*/
	int getGender();

	//  ----------- Модификаторы -----------
	/*
	Метод возвращает количество лет в виде числа.
	Параметры:
	void
	Возвращаемое значение - int количество лет
	*/
	inline int getAge();

	//  ----------- Инспекторы  -----------
	/*
	Метод возвращает фамилию, имя, отчество, пол, год рождения.
	Параметры:
	void
	Возвращаемое значение void
	*/
	void toString();
	Person operator=(const Person obj);
	// Деструктор
	virtual ~Person();
};

