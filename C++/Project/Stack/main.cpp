#include "Stack.h"
#include "iostream"
#include "cassert"

using std::printf;

void Test_Stack_01()
{
	printf("******************************01******************************\n");

	Aoki::Stack<int> c1;

	for (int i = 1; i <= 3; ++i)
		c1.push(i);

	Aoki::Stack<int> c2(c1);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "c1.top() = " << c1.top() << std::endl;
		std::cout << "c1.pop()" << std::endl;
		c1.pop();
	}
	std::cout << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "c2.top() = " << c2.top() << std::endl;
		std::cout << "c2.pop()" << std::endl;
		c2.pop();
	}
	std::cout << std::endl;

	c2 = c1;

	assert(c2.empty());

	for (int i = 0; i < 3; ++i)
		c1.push(i);

	c2 = c1;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "c2.top() = " << c2.top() << std::endl;
		std::cout << "c2.pop()" << std::endl;
		c2.pop();
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Stack_02()
{
	printf("******************************02******************************\n");

	{
		Aoki::Stack<int> s;

		s.push(2);
		s.push(6);
		s.push(51);

		std::cout << s.size() << " elements on stack\n";
		std::cout << "Top element: " << s.top() << "\n";
		std::cout << s.size() << " elements on stack\n";

		s.pop();
		std::cout << "s.pop()" << '\n';

		std::cout << s.size() << " elements on stack\n";
		std::cout << "Top element: " << s.top() << "\n";
	}

	std::cout << '\n';

	{
		Aoki::Stack<int> s;

		std::cout << "Initially, s.empty(): " << s.empty() << '\n';

		s.push(1);
		s.push(2);
		s.push(3);

		std::cout << "After pushing, s.empty(): " << s.empty() << '\n';
		std::cout << "s.size(): " << s.size() << '\n';

		s.pop();
		s.pop();
		s.pop();

		std::cout << "After popping, s.empty(): " << s.empty() << '\n';
	}

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Stack_01();
	Test_Stack_02();
	return 0;
}