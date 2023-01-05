#include "Queue.h"
#include "iostream"
#include "cassert"

using std::printf;

void Test_Stack_01()
{
	printf("******************************01******************************\n");

	Aoki::Queue<int> q1;

	for (int i = 1; i <= 3; ++i)
		q1.push(i);

	Aoki::Queue<int> q2(q1);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "q1.front() = " << q1.front() << std::endl;
		std::cout << "q1.back() = " << q1.back() << std::endl;
		std::cout << "q1.pop()" << std::endl;
		q1.pop();
	}
	std::cout << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "q2.front() = " << q2.front() << std::endl;
		std::cout << "q2.back() = " << q2.back() << std::endl;
		std::cout << "q2.pop()" << std::endl;
		q2.pop();
	}
	std::cout << std::endl;

	q2 = q1;

	assert(q2.empty());

	for (int i = 0; i < 3; ++i)
		q1.push(i);

	q2 = q1;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "q2.front() = " << q2.front() << std::endl;
		std::cout << "q2.back() = " << q2.back() << std::endl;
		std::cout << "q2.pop()" << std::endl;
		q2.pop();
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Stack_02()
{
	printf("******************************02******************************\n");

	Aoki::Queue<int> q;

	for (int i = 1; i <= 3; ++i)
		q.push(i);

	std::cout << "q.empty() = " << q.empty() << std::endl;
	std::cout << "q.size() = " << q.size() << std::endl;
	std::cout << std::endl;

	q.pop();

	std::cout << "q.empty() = " << q.empty() << std::endl;
	std::cout << "q.size() = " << q.size() << std::endl;
	std::cout << std::endl;

	q.pop();

	std::cout << "q.empty() = " << q.empty() << std::endl;
	std::cout << "q.size() = " << q.size() << std::endl;
	std::cout << std::endl;

	q.pop();

	std::cout << "q.empty() = " << q.empty() << std::endl;
	std::cout << "q.size() = " << q.size() << std::endl;
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Stack_01();
	Test_Stack_02();
	return 0;
}