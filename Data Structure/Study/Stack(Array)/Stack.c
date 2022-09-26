#include "Stack.h"

//初始化栈
void Init_Stack(Stack* ptr)
{
	assert(ptr);
	ptr->array_ptr = NULL;
	ptr->top = ptr->capacity = 0;
}

//将一个元素压入栈中
void Push_Stack(Stack* ptr, ElemType data)
{
	assert(ptr);
	if (ptr->top == ptr->capacity)
	{
		size_t newCapacity = ptr->capacity == 0 ? 4 : ptr->capacity * 2;
		ElemType* tmp = (ElemType*)realloc(ptr->array_ptr, sizeof(ElemType) * newCapacity);
		if (tmp == NULL)
		{
			perror("Push_Stack");
			exit(EXIT_FAILURE);
		}
		ptr->array_ptr = tmp;
		ptr->capacity = newCapacity;
	}
	ptr->array_ptr[ptr->top] = data;
	++ptr->top;
}

//将一个元素从栈中弹出
void Pop_Stack(Stack* ptr)
{
	assert(ptr);
	assert(!Empty_Stack(ptr));
	--ptr->top;
}

//获取栈的栈顶元素数据
ElemType Top_Stack(Stack* ptr)
{
	assert(ptr);
	assert(!Empty_Stack(ptr));
	return ptr->array_ptr[ptr->top - 1];
}

//判断栈是否为空栈
bool Empty_Stack(Stack* ptr)
{
	assert(ptr);
	return ptr->top == 0;
}

//获取栈中的元素个数
size_t Size_Stack(Stack* ptr)
{
	assert(ptr);
	return ptr->top;
}

//销毁栈
void Destroy_Stack(Stack* ptr)
{
	assert(ptr);
	free(ptr->array_ptr);
	ptr->top = ptr->capacity = 0;
}