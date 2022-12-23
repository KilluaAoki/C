#include "Vector.h"
#include <string>
#include <vector>

using std::printf;

void Test_Vector_01()
{
	printf("******************************01******************************\n");

	Aoki::Vector<int> v1;
	assert(v1.empty() && (v1.size() == 0));
	std::cout << std::endl;

	Aoki::Vector<int> v2(10, 1);
	for (auto& i: v2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Aoki::Vector<int> v3(v2);
	for (auto& i: v3)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Aoki::Vector<int> v4(v3.begin(), v3.end());
	for (auto& i: v4)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Aoki::Vector<std::string> v5;
	assert(v5.empty() && (v5.size() == 0));

	Aoki::Vector<std::string> v6(10, "hello");
	for (const auto& i: v6)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Aoki::Vector<std::string> v7(v6);
	for (const auto& i: v7)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Aoki::Vector<std::string> v8(v7.begin(), v7.end());
	for (const auto& i: v8)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Vector_02()
{
	printf("******************************02******************************\n");

	{
		Aoki::Vector<int> v1(5, 1);
		Aoki::Vector<int> v2(10, 2);
		Aoki::Vector<int> v3(15, 3);

		v1 = v2 = v3;

		std::cout << v1.size() << std::endl;
		for (auto& i: v1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << v2.size() << std::endl;
		for (auto& i: v2)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::cout << v3.size() << std::endl;
		for (auto& i: v3)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::Vector<char> characters;
		for (auto& i: characters)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		characters.assign(5, 'a');
		for (auto& i: characters)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		Aoki::Vector<char> tmp(5, 'b');
		characters.assign(tmp.begin(), tmp.end());
		for (auto& i: characters)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Vector_03()
{
	printf("******************************03******************************\n");

	Aoki::Vector<int> v1(10, 1);

	for (auto i = 0; i < v1.size(); ++i)
	{
		v1[i] = i * 2;
	}

	for (auto& i: v1)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "v1.front() = " << v1.front() << std::endl;
	std::cout << "v1.back() = " << v1.back() << std::endl;
	std::cout << "v1.data() = " << v1.data() << std::endl;
	std::cout << "*(v1.data()) = " << *(v1.data()) << std::endl;

	Aoki::Vector<int> v2(10, 1);

	for (auto i = 0; i < v2.size(); ++i)
	{
		v2.at(i) = i * 2;
	}

	for (auto& i: v2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "v2.front() = " << v2.front() << std::endl;
	std::cout << "v2.back() = " << v2.back() << std::endl;
	std::cout << "v2.data() = " << v2.data() << std::endl;
	std::cout << "*(v2.data()) = " << *(v2.data()) << std::endl;

	Aoki::Vector<int> v3(10, 1);

	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Vector_04()
{
	printf("******************************04******************************\n");

	{
		Aoki::Vector<int> numbers;
		std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

		numbers.push_back(6);
		std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

		Aoki::Vector<int> nums;

		std::cout << "nums.max_size(): " << nums.max_size() << '\n';

		std::cout << "Initially, nums.size(): " << nums.size() << '\n';

		nums.push_back(6);

		std::cout << "After adding elements, nums.size(): " << nums.size() << '\n';
	}

	std::cout << std::endl;

	{
		Aoki::Vector<int> v;

		std::cout << "v.size() = " << v.size() << "\n";
		std::cout << "v.capacity() = " << v.capacity() << "\n";

		v.reserve(100);
		std::cout << "s.reserve(100)" << "\n";
		std::cout << "s.size() = " << v.size() << "\n";
		std::cout << "s.capacity() = " << v.capacity() << "\n";

		v.reserve(10);
		std::cout << "s.reserve(10)" << "\n";
		std::cout << "s.size() = " << v.size() << "\n";
		std::cout << "s.capacity() = " << v.capacity() << "\n";

		v.reserve(1000);
		std::cout << "s.reserve(1000)" << "\n";
		std::cout << "s.size() = " << v.size() << "\n";
		std::cout << "s.capacity() = " << v.capacity() << "\n";
	}

	std::cout << std::endl;

	{
		std::vector<int> data1;
		size_t capacity1 = data1.capacity();
		std::cout << "making data1 grow:\n";
		for (int i = 0; i < 2000; ++i)
		{
			data1.push_back(i);
			if (capacity1 != data1.capacity())
			{
				capacity1 = data1.capacity();
				std::cout << "\tcapacity1 changed: " << capacity1 << '\n';
			}
		}

		Aoki::Vector<int> data2;
		size_t capacity2 = data2.capacity();
		std::cout << "making data2 grow:\n";
		for (int i = 0; i < 2000; ++i)
		{
			data2.push_back(i);
			if (capacity2 != data2.capacity())
			{
				capacity2 = data2.capacity();
				std::cout << "\tcapacity2 changed: " << capacity2 << '\n';
			}
		}

		Aoki::Vector<int> data3;
		data3.reserve(1000);
		std::cout << "data3.capacity() = " << data3.capacity() << "\n";
		data3.shrink_to_fit();
		std::cout << "data3.shrink_to_fit()\n";
		std::cout << "data3.capacity() = " << data3.capacity() << "\n";
	}

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Vector_05()
{
	printf("******************************05******************************\n");

	{
		Aoki::Vector<int> v(10, 100);

		std::cout << "size of v: " << v.size() << std::endl;
		std::cout << "capacity of v: " << v.capacity() << std::endl;

		v.clear();

		std::cout << "size of v: " << v.size() << std::endl;
		std::cout << "capacity of v: " << v.capacity() << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::Vector<int> v1(5, 100);
		Aoki::Vector<int> v2(5, 200);
		Aoki::Vector<int> v3(5, 300);

		v1.insert(v1.begin(), 50);

		for (auto& i: v1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		v2.insert(v2.begin(), 5, 50);

		for (auto& i: v2)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		v3.insert(v3.begin(), v2.begin(), v2.end());

		for (auto& i: v3)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Aoki::Vector<int> c;

		for (int i = 0; i < 10; ++i)
		{
			c.push_back(i);
		}

		for (int i: c)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";

		c.erase(c.begin());
		for (int i: c)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";

		c.erase(c.begin() + 2, c.begin() + 5);
		for (int i: c)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";

		for (auto it = c.begin(); it != c.end();)
		{
			if (*it % 2 == 0)
			{
				it = c.erase(it);
			}
			else
			{
				++it;
			}
		}
		for (int i: c)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";
	}

	std::cout << std::endl;

	{
		Aoki::Vector<int> c(3, 0);
		std::cout << "vector 持有：";
		for (const auto& el: c) std::cout << el << ' ';
		std::cout << '\n';

		c.resize(5, 0);
		std::cout << "在增加大小到 5 之后（初始化器 = 0）：";
		for (const auto& el: c) std::cout << el << ' ';
		std::cout << '\n';

		c.resize(2, 0);
		std::cout << "在减少大小到 2 之后（初始化器 = 0）：";
		for (const auto& el: c) std::cout << el << ' ';
		std::cout << '\n';

		c.resize(6, 4);
		std::cout << "在增加大小到 6 之后（初始化器 = 4）：";
		for (const auto& el: c) std::cout << el << ' ';
		std::cout << '\n';
	}

	std::cout << std::endl;

	{
		Aoki::Vector<int> v1(5, 10);
		Aoki::Vector<int> v2(10, 5);

		std::cout << "v1: ";
		for (const auto& el: v1) std::cout << el << ' ';

		std::cout << "\nv2: ";
		for (const auto& el: v2) std::cout << el << ' ';

		std::cout << '\n';

		v1.swap(v2);

		std::cout << "v1: ";
		for (const auto& el: v1) std::cout << el << ' ';

		std::cout << "\nv2: ";
		for (const auto& el: v2) std::cout << el << ' ';

		std::cout << '\n';
	}

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Vector_06()
{
	printf("******************************06******************************\n");

	{
		Aoki::Vector<int> alice(3, 1);
		Aoki::Vector<int> bob(4, 2);
		Aoki::Vector<int> eve(3, 1);

		std::cout << "alice == bob returns " << (alice == bob) << '\n';
		std::cout << "alice != bob returns " << (alice != bob) << '\n';
		std::cout << "alice <  bob returns " << (alice < bob) << '\n';
		std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
		std::cout << "alice >  bob returns " << (alice > bob) << '\n';
		std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
		std::cout << '\n';

		std::cout << "alice == eve returns " << (alice == eve) << '\n';
		std::cout << "alice != eve returns " << (alice != eve) << '\n';
		std::cout << "alice <  eve returns " << (alice < eve) << '\n';
		std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
		std::cout << "alice >  eve returns " << (alice > eve) << '\n';
		std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
		std::cout << '\n';
	}

	std::cout << std::endl;

	{
		Aoki::Vector<int> v1(5, 10);
		Aoki::Vector<int> v2(10, 5);

		std::cout << "v1: ";
		for (const auto& el: v1) std::cout << el << ' ';

		std::cout << "\nv2: ";
		for (const auto& el: v2) std::cout << el << ' ';

		std::cout << '\n';

		swap(v1, v2);

		std::cout << "v1: ";
		for (const auto& el: v1) std::cout << el << ' ';

		std::cout << "\nv2: ";
		for (const auto& el: v2) std::cout << el << ' ';

		std::cout << '\n';
	}

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Vector_01();
	Test_Vector_02();
	Test_Vector_03();
	Test_Vector_04();
	Test_Vector_05();
	Test_Vector_06();
	return 0;
}