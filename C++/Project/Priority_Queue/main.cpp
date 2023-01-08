#include <iostream>
#include <vector>
#include "Priority_Queue.h"

void Test_PriorityQueue_01()
{
	printf("******************************01******************************\n");

	std::vector<int> v{ 3, 1, 4, 1, 5, 9 };

	Aoki::Make_Heap(v.begin(), v.end());

	std::cout << "v: ";
	for (auto i: v) std::cout << i << ' ';
	std::cout << '\n';

	v.push_back(6);

	std::cout << "before Push_Heap: ";
	for (auto i: v) std::cout << i << ' ';
	std::cout << '\n';

	Aoki::Push_Heap(v.begin(), v.end());

	std::cout << "after Push_Heap: ";
	for (auto i: v) std::cout << i << ' ';
	std::cout << '\n';

	Aoki::Pop_Heap(v.begin(), v.end());

	std::cout << "after Pop_Heap: ";
	for (auto i: v) std::cout << i << ' ';
	std::cout << '\n';

	int largest = v.back();
	v.pop_back();
	std::cout << "largest element: " << largest << '\n';

	std::cout << "heap without largest: ";
	for (auto i: v) std::cout << i << ' ';
	std::cout << '\n';

	Aoki::Sort_Heap(v.begin(), v.end());
	std::cout << "after Sort_Heap: ";
	for (auto i: v) std::cout << i << ' ';
	std::cout << '\n';

	printf("*****************************EXIT*****************************\n\n");
}

void Test_PriorityQueue_02()
{
	printf("******************************02******************************\n");

	std::vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };

	Aoki::Priority_Queue<int> q1;

	for (auto& e: v)
	{
		q1.push(e);
	}

	std::cout << "q1: ";
	while (!q1.empty())
	{
		std::cout << q1.top() << " ";
		q1.pop();
	}
	std::cout << std::endl;

	Aoki::Priority_Queue<int, std::vector<int>, std::greater<>> q2(v.begin(), v.end());

	std::cout << "q2: ";
	while (!q2.empty())
	{
		std::cout << q2.top() << " ";
		q2.pop();
	}
	std::cout << std::endl;

	Aoki::Priority_Queue<int, std::vector<int>, std::greater<>> q3(v.begin(), v.end(), std::greater<>(),
			std::vector<int>(v.size(), 10));

	std::cout << "q3: ";
	while (!q3.empty())
	{
		std::cout << q3.top() << " ";
		q3.pop();
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_PriorityQueue_01();
	Test_PriorityQueue_02();
	return 0;
}