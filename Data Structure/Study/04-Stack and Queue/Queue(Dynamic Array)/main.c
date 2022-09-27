#include "Queue.h"
#include <time.h>

void Test_Queue_01()
{
	printf("******************************01******************************\n");
	Queue queue;
	Init_Queue(&queue);

	Push_Queue(&queue, 0);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 1);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 2);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 3);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 4);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 5);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 0);
	printf("\nSize_Queue = %zu.\n", Size_Queue(&queue));

	Destroy_Queue(&queue);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Queue_02()
{
	printf("******************************02******************************\n");
	Queue queue;
	Init_Queue(&queue);

	Push_Queue(&queue, 0);
	printf("%d ", Back_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 1);
	printf("%d ", Back_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 2);
	printf("%d ", Back_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 3);
	printf("%d ", Back_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 4);
	printf("%d ", Back_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 5);
	printf("%d ", Back_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 0);
	printf("\nSize_Queue = %zu.\n", Size_Queue(&queue));

	Destroy_Queue(&queue);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Queue_03()
{
	printf("******************************03******************************\n");
	Queue queue;
	Init_Queue(&queue);

	Push_Queue(&queue, 1);
	Push_Queue(&queue, 2);
	Push_Queue(&queue, 3);
	printf("%d ", Front_Queue(&queue));
	printf("%d ", Back_Queue(&queue));
	Push_Queue(&queue, 4);
	printf("%d ", Back_Queue(&queue));
	Pop_Queue(&queue);
	printf("%d ", Front_Queue(&queue));
	while (!Empty_Queue(&queue))
	{
		printf("%d ", Front_Queue(&queue));
		Pop_Queue(&queue);
	}
	printf("\nSize_Queue = %zu.\n", Size_Queue(&queue));

	Destroy_Queue(&queue);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Queue_04()
{
	printf("******************************04******************************\n");
	Queue queue;
	Init_Queue(&queue);

	Push_Queue(&queue, 1);
	Push_Queue(&queue, 2);
	Push_Queue(&queue, 3);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	printf("%d ", Front_Queue(&queue));
	Pop_Queue(&queue);
	Push_Queue(&queue, 4);
	Push_Queue(&queue, 4);
	Push_Queue(&queue, 4);
	while (!Empty_Queue(&queue))
	{
		printf("%d ", Front_Queue(&queue));
		Pop_Queue(&queue);
	}
	printf("\nSize_Queue = %zu.\n", Size_Queue(&queue));

	Destroy_Queue(&queue);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Queue_05()
{
	printf("******************************05******************************\n");

	srand((unsigned int)time(NULL));
	int oneTestDataNum = 1000;
	int value = 10000;
	int testTimes = 100000;
	for (int i = 0; i < testTimes; ++i)
	{
		Queue queue_01;
		Queue queue_02;
		Init_Queue(&queue_01);
		Init_Queue(&queue_02);
		for (int j = 0; j < oneTestDataNum; ++j)
		{
			int num = rand() * value;
			if (Empty_Queue(&queue_01))
			{
				Push_Queue(&queue_01, num);
				Push_Queue(&queue_02, num);
			}
			else
			{
				if (rand() < RAND_MAX / 2)
				{
					Push_Queue(&queue_01, num);
					Push_Queue(&queue_02, num);
				}
				else
				{
					if (queue_01.array_ptr == NULL && queue_02.array_ptr == NULL)
					{
						continue;
					}
					if ((queue_01.array_ptr != NULL && queue_02.array_ptr == NULL) ||
						(queue_01.array_ptr == NULL && queue_02.array_ptr != NULL) ||
						(Pop_Queue(&queue_01) != Pop_Queue(&queue_02)))
					{
						printf("Oops!\n*****************************EXIT*****************************\n\n");
						Destroy_Queue(&queue_01);
						Destroy_Queue(&queue_02);
						return;
					}
				}
			}
		}
		Destroy_Queue(&queue_01);
		Destroy_Queue(&queue_02);
	}
	printf("Good Luck!\n");

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Queue_01();
	Test_Queue_02();
	Test_Queue_03();
	Test_Queue_04();
	Test_Queue_05();
	return 0;
}