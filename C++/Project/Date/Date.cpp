#include "Date.h"

//无参构造函数
Date::Date()
{
	year_ = month_ = day_ = 1;
}

//带参构造函数
Date::Date(int year, int month, int day)
{
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > GetMonthDay(year, month))
	{
		std::cout << "非法日期！" << std::endl;
	}
	year_ = year;
	month_ = month;
	day_ = day;
}

//获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	static int monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
	{
		return 29;
	}
	return monthDayArray[month];
}

//重载"+"运算符，以支持对一个日期类对象添加天数。
Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}

//重载"-"运算符，以支持对一个日期类对象减去天数。
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

//重载"+="运算符，以支持对一个日期类对象添加天数。
Date& Date::operator+=(int day)
{
	if (day < 0)
		return *this -= std::abs(day);
	day_ += day;
	while (day_ > GetMonthDay(year_, month_))
	{
		day_ -= GetMonthDay(year_, month_);
		++month_;
		if (month_ > 12)
		{
			month_ = 1;
			++year_;
		}
	}
	return *this;
}

//重载"-="运算符，以支持对一个日期类对象减去天数。
Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this += std::abs(day);
	day_ -= day;
	while (day_ <= 0)
	{
		--month_;
		if (month_ <= 0)
		{
			month_ = 12;
			--year_;
		}
		day_ += GetMonthDay(year_, month_);
	}
	return *this;
}

//重载"<"运算符，以支持对两个日期类对象进行比较。
bool Date::operator<(const Date& d) const
{
	if (year_ < d.year_)
		return true;
	else if (year_ == d.year_ && month_ < d.month_)
		return true;
	else if (year_ == d.year_ && month_ == d.month_ && day_ < d.day_)
		return true;
	return false;
}

//重载"<="运算符，以支持对两个日期类对象进行比较。
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}

//重载">"运算符，以支持对两个日期类对象进行比较。
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

//重载">="运算符，以支持对两个日期类对象进行比较。
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

//重载"!="运算符，以支持对两个日期类对象进行比较。
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//重载"=="运算符，以支持对两个日期类对象进行比较。
bool Date::operator==(const Date& d) const
{
	return ((this->year_ == d.year_) && (this->month_ == d.month_) && (this->day_ == d.day_));
}

//重载"++"运算符，以支持对一个日期类对象进行自增。(前置)
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//重载"++"运算符，以支持对一个日期类对象进行自增。(后置)
const Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//重载"--"运算符，以支持对一个日期类对象进行自增。(前置)
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//重载"--"运算符，以支持对一个日期类对象进行自增。(后置)
const Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}

//重载"-"运算符，以支持对两个日期类对象进行相减，并返回相差的天数。
int Date::operator-(const Date& d)
{
	Date max(*this);
	Date min(d);
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (max != min)
	{
		++count;
		--max;
	}
	return count * flag;
}

//打印日期
void Date::Show() const
{
	std::printf("%04d/%02d/%02d\n", year_, month_, day_);
}