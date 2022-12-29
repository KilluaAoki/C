#include "List.h"
#include <cassert>
#include <list>

using std::printf;

void Test_List_01()
{
	printf("******************************01******************************\n");

	Aoki::List<int> v1;
	assert(v1.empty() && (v1.size() == 0));

	Aoki::List<int> v2(5, 1);
	for (auto i: v2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Aoki::List<int> v3(v2.begin(), v2.end());
	for (auto i: v3)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Aoki::List<int> v4(v3);
	for (auto i: v4)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_List_02()
{
	printf("******************************02******************************\n");

	Aoki::List<int> v1(5, 1);
	Aoki::List<int> v2(3, 2);
	Aoki::List<int> v3(2, 3);
	Aoki::List<int> v4(5, 1);
	Aoki::List<int> v5(3, 2);

	v1 = v2 = v3;
	std::cout << v1.size() << std::endl;
	for (auto i: v1)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << v2.size() << std::endl;
	for (auto i: v2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << v3.size() << std::endl;
	for (auto i: v3)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	v4.assign(3, 4);
	std::cout << v4.size() << std::endl;
	for (auto i: v4)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	v5.assign(v4.begin(), v4.end());
	std::cout << v5.size() << std::endl;
	for (auto i: v5)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_List_03()
{
	printf("******************************03******************************\n");

	{
		Aoki::List<int> v(10, 1);
		std::cout << "v.front() = " << v.front() << std::endl;
		std::cout << "v.back() = " << v.back() << std::endl;

		int i = 0;
		for (auto& e: v)
		{
			e = i * 2;
			++i;
		}

		for (auto it = v.begin(); it != v.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> numbers;
		std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

		numbers.push_back(42);
		numbers.push_back(13317);
		std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
	}

	std::cout << std::endl;

	{
		Aoki::List<int> nums;

		std::cout << "Maximum size of a \"list\" is " << nums.max_size() << "\n";

		for (int i = 0; i < 10; i++)
		{
			nums.push_back(i);
		}

		std::cout << "nums contains " << nums.size() << " elements.\n";
	}

	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_List_04()
{
	printf("******************************04******************************\n");

	{
		Aoki::List<int> v(10, 100);
		std::cout << "size of v: " << v.size() << std::endl;
		v.clear();
		std::cout << "size of v: " << v.size() << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> v1(5, 100);
		Aoki::List<int> v2(5, 200);
		Aoki::List<int> v3(5, 300);

		v1.insert(v1.begin(), 50);
		v2.insert(v2.begin(), 5, 50);
		v3.insert(v3.begin(), v2.begin(), v2.end());

		std::cout << "v1 contains: ";
		for (auto i: v1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << "v2 contains: ";
		for (auto i: v2)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << "v3 contains: ";
		for (auto i: v3)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> c;
		for (int i = 0; i < 10; ++i)
		{
			c.push_back(i);
		}

		c.erase(c.begin());
		for (int i: c)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";

		c.erase(c.begin(), c.end());
		for (int i: c)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";
	}

	std::cout << std::endl;

	{
		Aoki::List<std::string> lc;

		lc.push_back("Hello");
		lc.push_back(" World!");
		lc.push_front("C++ ");
		lc.push_front("Programming ");

		for (auto& s: lc)
		{
			std::cout << s;
		}
		std::cout << '\n';

		lc.pop_back();
		lc.pop_front();

		for (auto& s: lc)
		{
			std::cout << s;
		}
		std::cout << '\n';
	}

	std::cout << std::endl;

	{
		Aoki::List<int> v(10, 100);

		std::cout << "size of v: " << v.size() << std::endl;
		for (auto& s: v)
		{
			std::cout << s << ' ';
		}
		std::cout << '\n';

		v.resize(8, 50);
		std::cout << "size of v: " << v.size() << std::endl;
		for (auto& s: v)
		{
			std::cout << s << ' ';
		}
		std::cout << '\n';

		v.resize(12, 50);
		std::cout << "size of v: " << v.size() << std::endl;
		for (auto& s: v)
		{
			std::cout << s << ' ';
		}
		std::cout << '\n';
	}

	std::cout << std::endl;

	{
		Aoki::List<int> v1(5, 0);
		Aoki::List<int> v2(5, 100);

		for (auto& s: v1)
		{
			std::cout << s << ' ';
		}
		std::cout << '\n';

		v1.swap(v2);

		for (auto& s: v1)
		{
			std::cout << s << ' ';
		}
		std::cout << '\n';
	}

	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_List_05()
{
	printf("******************************05******************************\n");

	{
		Aoki::List<int> list1(5, 10);
		Aoki::List<int> list2(5, 20);

		list1.merge(list2);

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> list1(5, 10);
		Aoki::List<int> list2(5, 20);

		list1.splice(list1.begin(), list2);

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> list1(5, 10);
		Aoki::List<int> list2(5, 20);

		list1.splice(list1.begin(), list2, list2.begin());

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> list1(5, 10);
		Aoki::List<int> list2(5, 20);

		list1.splice(list1.begin(), list2, list2.begin(), list2.end());

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> list1;

		for (int i = 0; i < 10; ++i)
		{
			list1.push_back(i);
		}

		list1.remove(5);

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> list1;

		for (int i = 0; i < 10; ++i)
		{
			list1.push_back(i);
		}

		list1.remove_if([](int i)
		{ return i % 2 == 0; });

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> list1;

		for (int i = 0; i < 10; ++i)
		{
			list1.push_back(i);
		}

		list1.reverse();

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::List<int> list1(5, 10);

		for (int i = 10; i >= 0; --i)
		{
			list1.push_front(i);
		}

		list1.unique();

		for (auto i: list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_List_01();
	Test_List_02();
	Test_List_03();
	Test_List_04();
	Test_List_05();
	return 0;
}