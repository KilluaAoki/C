#include "Stack.h"

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
	printf("%zu\n", Size_Stack(&stack));

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
	printf("%zu\n", Size_Stack(&stack));

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
	printf("\n");

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
	printf("\n");

	Destroy_Stack(&stack);
	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Stack_01();
	Test_Stack_02();
	Test_Stack_03();
	Test_Stack_04();
	return 0;
}