#include "Date.h"

void Test_Date_01()
{
	Date d1(2022, 1, 1);
	Date d2(d1);

	std::cout << std::endl;
	(d1 + 31).Show();
	(d2 - 31).Show();
	(d1 - 10000).Show();
	(d2 + 10000).Show();

	std::cout << std::endl;
	(d1 -= 10000).Show();
	(d2 += 10000).Show();

	std::cout << std::endl;
	d1 > d2 ? std::cout << "(d1 > d2) == true" << std::endl : std::cout << "(d1 > d2) == false" << std::endl;
	d1 < d2 ? std::cout << "(d1 < d2) == true" << std::endl : std::cout << "(d1 < d2) == false" << std::endl;
	d1 >= d2 ? std::cout << "(d1 >= d2) == true" << std::endl : std::cout << "(d1 >= d2) == false" << std::endl;
	d1 <= d2 ? std::cout << "(d1 <= d2) == true" << std::endl : std::cout << "(d1 <= d2) == false" << std::endl;
	d1 != d2 ? std::cout << "(d1 != d2) == true" << std::endl : std::cout << "(d1 != d2) == false" << std::endl;
	d1 == d2 ? std::cout << "(d1 == d2) == true" << std::endl : std::cout << "(d1 == d2) == false" << std::endl;
}

void Test_Date_02()
{
	Date d1(2022, 1, 1);
	Date d2(d1);

	std::cout << std::endl;
	(d1--).Show();
	d1.Show();
	(d1++).Show();
	d1.Show();
	(--d2).Show();
	d2.Show();
	(++d2).Show();
	d2.Show();
}

void Test_Date_03()
{
	Date d1(2000, 1, 1);
	Date d2(2000, 12, 31);

	std::cout << std::endl;
	std::cout << "d1 - d2 = " << d1 - d2 << std::endl;
	std::cout << "d2 - d1 = " << d2 - d1 << std::endl;
}

void Test_Date_04()
{
	Date d1, d2;
	std::cout << "请输入现在的日期：";
	std::cin >> d1;
	std::cout << "请输入出生的日期：";
	std::cin >> d2;
	std::cout << "你已经活了" << d1 - d2 << "天" << std::endl;
}

int main()
{
	Test_Date_01();
	Test_Date_02();
	Test_Date_03();
	Test_Date_04();
	return 0;
}