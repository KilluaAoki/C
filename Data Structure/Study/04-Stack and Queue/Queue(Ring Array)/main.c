#include "Queue.h"

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
	Queue queue;
	Init_Queue(&queue);

	Push_Queue(&queue, 1);
	Push_Queue(&queue, 2);
	Push_Queue(&queue, 3);
	Push_Queue(&queue, 4);
	Push_Queue(&queue, 5);
	printf("%d ", Front_Queue(&queue));
	printf("%d\n", Back_Queue(&queue));
	printf("%d ", Pop_Queue(&queue));
	Push_Queue(&queue, 6);
	printf("%d ", Front_Queue(&queue));
	printf("%d\n", Back_Queue(&queue));
	printf("%zu ", queue.pop_index);
	printf("%zu\n", queue.push_index);
	printf("%d ", Pop_Queue(&queue));
	printf("%d ", Pop_Queue(&queue));
	printf("%d ", Pop_Queue(&queue));
	printf("%d\n", Pop_Queue(&queue));
	printf("%zu ", queue.pop_index);
	printf("%zu\n", queue.push_index);
	Push_Queue(&queue, 1);
	Push_Queue(&queue, 2);
	Push_Queue(&queue, 3);
	Push_Queue(&queue, 4);
	printf("%d ", Front_Queue(&queue));
	printf("%d\n", Back_Queue(&queue));
	printf("%d ", Pop_Queue(&queue));
	printf("%d\n", Pop_Queue(&queue));
	Push_Queue(&queue, 1);
	Push_Queue(&queue, 2);
	printf("%zu ", queue.pop_index);
	printf("%zu\n", queue.push_index);
	printf("\nSize_Queue = %zu.\n", Size_Queue(&queue));

	Destroy_Queue(&queue);
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