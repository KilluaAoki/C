#include "Deque.h"
#include <time.h>

void Test_Deque_01()
{
	printf("******************************01******************************\n");
	Deque deque;
	Init_Deque(&deque);

	Push_Front_Deque(&deque, 9);
	Push_Front_Deque(&deque, 8);
	Push_Front_Deque(&deque, 7);
	Push_Front_Deque(&deque, 6);
	Push_Front_Deque(&deque, 5);
	Push_Front_Deque(&deque, 4);
	Push_Front_Deque(&deque, 3);
	Push_Front_Deque(&deque, 2);
	Push_Front_Deque(&deque, 1);
	Push_Front_Deque(&deque, 0);
	printf("Size_Queue = %zu.\n", Size_Deque(&deque));
	while (!Empty_Deque(&deque))
	{
		printf("%d ", Front_Deque(&deque));
		Pop_Front_Deque(&deque);
	}
	printf("\nSize_Queue = %zu.\n", Size_Deque(&deque));

	Destroy_Queue(&deque);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Deque_02()
{
	printf("******************************02******************************\n");
	Deque deque;
	Init_Deque(&deque);

	Push_Back_Deque(&deque, 0);
	Push_Back_Deque(&deque, 1);
	Push_Back_Deque(&deque, 2);
	Push_Back_Deque(&deque, 3);
	Push_Back_Deque(&deque, 4);
	Push_Back_Deque(&deque, 5);
	Push_Back_Deque(&deque, 6);
	Push_Back_Deque(&deque, 7);
	Push_Back_Deque(&deque, 8);
	Push_Back_Deque(&deque, 9);
	printf("Size_Queue = %zu.\n", Size_Deque(&deque));
	while (!Empty_Deque(&deque))
	{
		printf("%d ", Back_Deque(&deque));
		Pop_Back_Deque(&deque);
	}
	printf("\nSize_Queue = %zu.\n", Size_Deque(&deque));

	Destroy_Queue(&deque);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Deque_03()
{
	printf("******************************03******************************\n");
	Deque deque;
	Init_Deque(&deque);

	Push_Back_Deque(&deque, 0);
	Push_Back_Deque(&deque, 1);
	Push_Back_Deque(&deque, 2);
	printf("%d ", Front_Deque(&deque));
	printf("%d ", Back_Deque(&deque));
	Push_Back_Deque(&deque, 3);
	printf("%d ", Back_Deque(&deque));
	Pop_Front_Deque(&deque);
	printf("%d ", Front_Deque(&deque));
	Pop_Back_Deque(&deque);
	printf("%d ", Back_Deque(&deque));
	printf("\nSize_Queue = %zu.\n", Size_Deque(&deque));
	while (!Empty_Deque(&deque))
	{
		printf("%d ", Back_Deque(&deque));
		Pop_Back_Deque(&deque);
	}
	printf("\nSize_Queue = %zu.\n", Size_Deque(&deque));

	Destroy_Queue(&deque);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Deque_04()
{
	printf("******************************04******************************\n");
	Deque deque01;
	Deque deque02;
	Init_Deque(&deque01);
	Init_Deque(&deque02);

	srand((unsigned int)time(NULL));
	int testTime = 5000000;
	int maxValue = 200000000;
	for (int i = 0; i < testTime; ++i)
	{
		if (Empty_Deque(&deque01) != Empty_Deque(&deque02))
		{
			printf("Oops!\n");
			return;
		}
		if (Size_Deque(&deque01) != Size_Deque(&deque02))
		{
			printf("Oops!\n");
			return;
		}
		double decide = (double)(rand() % 100) / 100.0;
		if (decide < 0.33)
		{
			int num = (int)(((double)(rand() % 100) / 100.0) * maxValue);
			if (rand() % 2 == 0)
			{
				Push_Front_Deque(&deque01, num);
				Push_Front_Deque(&deque02, num);
			}
			else
			{
				Push_Back_Deque(&deque01, num);
				Push_Back_Deque(&deque02, num);
			}
		}
		else if (decide < 0.66)
		{
			if (!Empty_Deque(&deque01))
			{
				DequeType num1, num2;
				if (rand() % 2 == 0)
				{
					num1 = Pop_Front_Deque(&deque01);
					num2 = Pop_Front_Deque(&deque02);
				}
				else
				{
					num1 = Pop_Back_Deque(&deque01);
					num2 = Pop_Back_Deque(&deque02);
				}
				if (num1 != num2)
				{
					printf("Oops!\n");
					return;
				}
			}
		}
		else
		{
			if (!Empty_Deque(&deque01))
			{
				DequeType num1, num2;
				if (rand() % 2 == 0)
				{
					num1 = Front_Deque(&deque01);
					num2 = Front_Deque(&deque02);
				}
				else
				{
					num1 = Back_Deque(&deque01);
					num2 = Back_Deque(&deque02);
				}
				if (num1 != num2)
				{
					printf("Oops!\n");
					return;
				}
			}
		}
	}
	if (Size_Deque(&deque01) != Size_Deque(&deque02))
	{
		printf("Oops!\n");
		return;
	}
	while (!Empty_Deque(&deque01))
	{
		DequeType num1, num2;
		num1 = Pop_Front_Deque(&deque01);
		num2 = Pop_Front_Deque(&deque02);
		if (num1 != num2)
		{
			printf("Oops!\n");
			return;
		}
	}
	printf("Good Luck!\n");

	Destroy_Queue(&deque01);
	Destroy_Queue(&deque02);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Deque_05()
{
	printf("******************************05******************************\n");
	Deque deque01;
	Deque deque02;
	Init_Deque(&deque01);
	Init_Deque(&deque02);

	srand((unsigned int)time(NULL));
	int testTime = 5000000;
	int maxValue = 200000000;
	for (int i = 0; i < testTime; ++i)
	{
		if (Empty_Deque(&deque01) != Empty_Deque(&deque02))
		{
			printf("Oops!\n");
			return;
		}
		if (Size_Deque(&deque01) != Size_Deque(&deque02))
		{
			printf("Oops!\n");
			return;
		}
		double decide = (double)(rand() % 100) / 100.0;
		if (decide < 0.33)
		{
			int num = (int)(((double)(rand() % 100) / 100.0) * maxValue);
			if (rand() % 2 == 0)
			{
				Push_Front_Deque(&deque01, num);
				Push_Front_Deque(&deque02, num);
			}
			else
			{
				Push_Back_Deque(&deque01, num);
				Push_Back_Deque(&deque02, num);
			}
		}
		else if (decide < 0.66)
		{
			if (!Empty_Deque(&deque01))
			{
				DequeType num1, num2;
				if (rand() % 2 == 0)
				{
					num1 = Pop_Front_Deque(&deque01);
					num2 = Pop_Front_Deque(&deque02);
				}
				else
				{
					num1 = Pop_Back_Deque(&deque01);
					num2 = Pop_Back_Deque(&deque02);
				}
				if (num1 != num2)
				{
					printf("Oops!\n");
					return;
				}
			}
		}
		else
		{
			if (!Empty_Deque(&deque01))
			{
				DequeType num1, num2;
				if (rand() % 2 == 0)
				{
					num1 = Front_Deque(&deque01);
					num2 = Front_Deque(&deque02);
				}
				else
				{
					num1 = Back_Deque(&deque01);
					num2 = Back_Deque(&deque02);
				}
				if (num1 != num2)
				{
					printf("Oops!\n");
					return;
				}
			}
		}
	}
	if (Size_Deque(&deque01) != Size_Deque(&deque02))
	{
		printf("Oops!\n");
		return;
	}
	while (!Empty_Deque(&deque01))
	{
		DequeType num1, num2;
		num1 = Pop_Front_Deque(&deque01);
		num2 = Pop_Front_Deque(&deque02);
		if (num1 != num2)
		{
			printf("Oops!\n");
			return;
		}
	}
	printf("Good Luck!\n");

	Destroy_Queue(&deque01);
	Destroy_Queue(&deque02);
	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Deque_01();
	Test_Deque_02();
	Test_Deque_03();
	//Test_Deque_04();
	Test_Deque_05();
	return 0;
}