#include "Stack.h"
#include <time.h>

void Test_Stack_01()
{
	printf("******************************01******************************\n");
	Stack stack;
	Init_Stack(&stack);

	Push_Stack(&stack, 5);
	printf("%d\n", Top_Stack(&stack));
	Push_Stack(&stack, 4);
	printf("%d\n", Top_Stack(&stack));
	Push_Stack(&stack, 3);
	printf("%d\n", Top_Stack(&stack));
	Push_Stack(&stack, 2);
	printf("%d\n", Top_Stack(&stack));
	Push_Stack(&stack, 1);
	printf("%d\n", Top_Stack(&stack));
	printf("Size_Stack = %zu.\n", Size_Stack(&stack));

	Destroy_Stack(&stack);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Stack_02()
{
	printf("******************************02******************************\n");
	Stack stack;
	Init_Stack(&stack);

	Push_Stack(&stack, 6);
	Pop_Stack(&stack);
	Push_Stack(&stack, 5);
	Push_Stack(&stack, 4);
	Push_Stack(&stack, 3);
	Push_Stack(&stack, 2);
	Push_Stack(&stack, 1);
	Push_Stack(&stack, 0);
	Pop_Stack(&stack);
	printf("%d\n", Top_Stack(&stack));
	printf("Size_Stack = %zu.\n", Size_Stack(&stack));

	Destroy_Stack(&stack);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Stack_03()
{
	printf("******************************03******************************\n");
	Stack stack;
	Init_Stack(&stack);

	Push_Stack(&stack, 6);
	Push_Stack(&stack, 5);
	Push_Stack(&stack, 4);
	Push_Stack(&stack, 3);
	Push_Stack(&stack, 2);
	Push_Stack(&stack, 1);
	Push_Stack(&stack, 0);
	while (!Empty_Stack(&stack))
	{
		printf("%d ", Top_Stack(&stack));
		Pop_Stack(&stack);
	}
	printf("\nSize_Stack = %zu.\n", Size_Stack(&stack));

	Destroy_Stack(&stack);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Stack_04()
{
	printf("******************************04******************************\n");
	Stack stack;
	Init_Stack(&stack);

	Push_Stack(&stack, 1);
	Push_Stack(&stack, 2);
	Push_Stack(&stack, 3);
	printf("%d\n", Top_Stack(&stack));
	Pop_Stack(&stack);
	printf("%d\n", Top_Stack(&stack));
	Pop_Stack(&stack);
	Push_Stack(&stack, 4);
	Push_Stack(&stack, 5);
	while (!Empty_Stack(&stack))
	{
		printf("%d ", Top_Stack(&stack));
		Pop_Stack(&stack);
	}
	printf("\nSize_Stack = %zu.\n", Size_Stack(&stack));

	Destroy_Stack(&stack);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Stack_05()
{
	printf("******************************05******************************\n");

	srand((unsigned int)time(NULL));
	int oneTestDataNum = 100;
	int value = 10000;
	int testTimes = 100000;
	for (int i = 0; i < testTimes; ++i)
	{
		Stack stack_01;
		Stack stack_02;
		Init_Stack(&stack_01);
		Init_Stack(&stack_02);
		for (int j = 0; j < oneTestDataNum; ++j)
		{
			int num = rand() * value;
			if (Empty_Stack(&stack_01))
			{
				Push_Stack(&stack_01, num);
				Push_Stack(&stack_02, num);
			}
			else
			{
				if (rand() < RAND_MAX / 2)
				{
					Push_Stack(&stack_01, num);
					Push_Stack(&stack_02, num);
				}
				else
				{
					if (stack_01.array_ptr == NULL && stack_02.array_ptr == NULL)
					{
						continue;
					}
					if ((stack_01.array_ptr != NULL && stack_02.array_ptr == NULL) ||
						(stack_01.array_ptr == NULL && stack_02.array_ptr != NULL) ||
						(Top_Stack(&stack_01) != Top_Stack(&stack_02)))
					{
						printf("Oops!\n*****************************EXIT*****************************\n\n");
						Destroy_Stack(&stack_01);
						Destroy_Stack(&stack_02);
						return;
					}
					Pop_Stack(&stack_01);
					Pop_Stack(&stack_02);
				}
			}
		}
		Destroy_Stack(&stack_01);
		Destroy_Stack(&stack_02);
	}
	printf("Good Luck!\n");

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Stack_01();
	Test_Stack_02();
	Test_Stack_03();
	Test_Stack_04();
	Test_Stack_05();
	return 0;
}