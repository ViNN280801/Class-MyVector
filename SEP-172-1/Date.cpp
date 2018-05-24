#include "stdafx.h"
#include <iostream>
#include<ctime>
#include"Date.h"


//3. Создать конструктор по умолчанию.
Date::Date()
{
	second = 0;
	year = 0;
	month = 0;
	day = 0;
}
//4. Создайте конструктор для ввода даты в виде Date(день, месяц, год).
Date::Date(int out_Day, int out_Month, int out_Year)
{
	day = out_Day;
	month = out_Month;
	year = out_Year;
	second_Time();
}
Date::Date(const Date & time)
{
	day = time.day;
	month = time.month;
	year = time.year;
	second = time.second;
}
//5. Создать метод, не возвращающий значения, для получения текущего системного времени.
void Date::second_Time()
{
	struct tm newtime;
	__time64_t seconds = time(NULL);
	_time64(&seconds);
	errno_t err;
	err = _localtime64_s(&newtime, &seconds);
}
////6. Создайте метод для вывода в консоль времени в виде ДД.ММ.ГГГГ.
//void Date::out_Time()
//{
//	time_t seconds = second;
//	struct tm*ptm = localtime(&seconds);
//	ptm = gmtime(&seconds);
//	cout << ptm->tm_mday << "." << ptm->tm_mon + 1 << "." << ptm->tm_year + 1900 << endl;
//}

int Date::operator-(Date time)
{
	return int(((((this->second - time.second) / 60)) / 60) / 24);
}

//Date Date::operator+(int days)
//{
//	return Date(this->day + days, this->month, this->year);
//}
//
//void Date::operator+=(int days)
//{
//	this->second += days * 86400;
//}

Date Date::operator=(const Date time)
{
	day = time.day;
	month = time.month;
	year = time.year;
	second = time.second;
	return *this;
}
