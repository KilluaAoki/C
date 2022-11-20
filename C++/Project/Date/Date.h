#pragma once

//引用头文件
#include "iostream"
#include <cstdio>
#include <cstdlib>

class Date
{
public:
	//无参构造函数
	Date();

	//带参构造函数
	Date(int year, int month, int day);

	//获取某年某月的天数
	static int GetMonthDay(int year, int month);

	//重载"+"运算符，以支持对一个日期类对象添加天数。
	Date operator+(int day);

	//重载"-"运算符，以支持对一个日期类对象减去天数。
	Date operator-(int day);

	//重载"+="运算符，以支持对一个日期类对象添加天数。
	Date& operator+=(int day);

	//重载"-="运算符，以支持对一个日期类对象减去天数。
	Date& operator-=(int day);

	//重载"<"运算符，以支持对两个日期类对象进行比较。
	bool operator<(const Date& d) const;

	//重载"<="运算符，以支持对两个日期类对象进行比较。
	bool operator<=(const Date& d) const;

	//重载">"运算符，以支持对两个日期类对象进行比较。
	bool operator>(const Date& d) const;

	//重载">="运算符，以支持对两个日期类对象进行比较。
	bool operator>=(const Date& d) const;

	//重载"!="运算符，以支持对两个日期类对象进行比较。
	bool operator!=(const Date& d) const;

	//重载"=="运算符，以支持对两个日期类对象进行比较。
	bool operator==(const Date& d) const;

	//重载"++"运算符，以支持对一个日期类对象进行自增。(前置)
	Date& operator++();

	//重载"++"运算符，以支持对一个日期类对象进行自增。(后置)
	const Date operator++(int);

	//重载"--"运算符，以支持对一个日期类对象进行自增。(前置)
	Date& operator--();

	//重载"--"运算符，以支持对一个日期类对象进行自增。(后置)
	const Date operator--(int);

	//重载"-"运算符，以支持对两个日期类对象进行相减，并返回相差的天数。
	int operator-(const Date& d);

	//重载"<<"运算符，以支持对一个日期类对象进行输出。
	friend std::ostream& operator<<(std::ostream& _cout, const Date& d);

	//重载">>"运算符，以支持对一个日期类对象进行输入。
	friend std::istream& operator>>(std::istream& _cin, Date& d);

	//打印日期
	void Show() const;

private:
	int year_;
	int month_;
	int day_;
};

//重载"<<"运算符，以支持对一个日期类对象进行输出。
inline std::ostream& operator<<(std::ostream& _cout, const Date& d)
{
	_cout << d.year_ << "/" << d.month_ << "/" << d.day_;
	return _cout;
}

//重载">>"运算符，以支持对一个日期类对象进行输入。
inline std::istream& operator>>(std::istream& _cin, Date& d)
{
	_cin >> d.year_ >> d.month_ >> d.day_;
	return _cin;
}