#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	动态内存管理
		1.动态内存分配
		2.动态内存函数
		3.常见的动态内存错误
		4.笔试题
		5.C与C++程序的内存开辟
		6.柔性数组
*/

/**
	动态内存分配：在程序执行的过程中动态地分配或者回收存储空间的分配内存的方法。
		1.动态内存分配不像数组等静态内存分配方法那样需要预先分配存储空间，而是由系统根据程序的需要即时分配，且分配的大小就是程序要求的大小。
		2.动态内存开辟于堆上。
		3.C与C++程序并没有垃圾自动回收机制，不同于Java等具有垃圾自动回收的语言，故需要注意内存泄露问题，但这样的好处是带来了性能的提升。
*/

/**
	动态内存函数
		1."malloc"函数：分配内存块。
			1.头文件："stdlib.h"。
			2.函数声明：void* malloc(size_t size);。
				a.函数头"void*"表示此函数的返回值是无类型指针，可返回任意类型的指针变量；在此函数中意为返回一个指向内存块开头的指针或空指针。
				b.函数参数"size_t size"：将无符号整型类型作为参数；在此函数中意为要分配的内存块的字节数。
			3.函数说明
				a.分配"size"字节的未初始化内存。
				b.若"size"为零，则"malloc"函数的行为是取决于特定的库实现的，可返回空指针亦可返回不可用于访问存储的非空指针，但不应当解引用这种指针，而且应将它传递给"free"函数以避免内存泄漏。
			4."malloc"函数的返回值设计
				a.分配成功时，返回指向新分配内存的指针；为避免内存泄漏，必须用"free"函数或"realloc"函数释放返回的指针。
				b.分配失败时，返回一个空指针。
				c.此指针的类型始终为"void*"，可以将其转换为所需的数据指针类型，以便可取消引用。
		2."calloc"函数：为"num"个元素的数组分配一块内存，每个元素的大小为"size"字节，并初始化所有分配存储中的字节为零。
			1.头文件："stdlib.h"。
			2.函数声明：void* calloc(size_t num, size_t size);。
				a.函数头"void*"表示此函数的返回值是无类型指针，可返回任意类型的指针变量；在此函数中意为返回一个指向内存块开头的指针或空指针。
				b.函数参数"size_t num"：将无符号整型类型作为参数；在此函数中意为要分配的元素个数。
				c.函数参数"size_t size"：将无符号整型类型作为参数；在此函数中意为要分配的每个元素的大小。
			3.函数说明
				a.有效的结果是分配一个零初始化的"num*size"字节内存块，但由于对齐要求，分配的字节数不一定等于"num*size"。
				b.初始化所有位为零不保证浮点数或指针被初始化为"0.0"或空指针，尽管这在所有常见平台上为真。
				c.若"size"为零，则"calloc"函数的行为是取决于特定的库实现的，可返回空指针亦可返回不可用于访问存储的非空指针，但不应当解引用这种指针，而且应将它传递给"free"函数以避免内存泄漏。
			4."calloc"函数的返回值设计
				a.分配成功时，返回指向分配内存块最低位(首位)字节的指针，它为任何类型适当地对齐；为避免内存泄漏，必须用"free"函数或"realloc"函数释放返回的指针。
				b.分配失败时，返回一个空指针。
				c.此指针的类型始终为"void*"，可以将其转换为所需的数据指针类型，以便可取消引用。
		3."realloc"函数：重新分配内存块。
			1.头文件："stdlib.h"。
			2.函数声明：void* realloc(void* ptr, size_t size);。
				a.函数头"void*"表示此函数的返回值是无类型指针，可返回任意类型的指针变量；在此函数中意为指向重新分配的内存块的指针或空指针。
				b.函数参数"void* ptr"：将无类型指针作为参数；在此函数中意为指向需要重新分配的内存区域的指针或空指针。
				c.函数参数"size_t size"：将无符号整型类型作为参数；在此函数中意为要分配的内存块的新大小(以字节为单位)。
			3.函数说明：更改"ptr"指向的内存块的大小，并且该函数还可以将内存块移动到新位置(其地址由函数返回)。
				a.若"ptr"是指向重新分配的内存块的指针，当原空间大小足够时，则扩张或收缩"ptr"所指向的已存在内存，内容在新旧大小中的较小者范围内保持不变，若扩张范围，则数组新增部分的内容是未定义的。
				b.若"ptr"是指向重新分配的内存块的指针，当原空间大小不够时，则重新分配一个大小为"size"字节的新内存块，并复制大小等于新旧大小中较小者的内存区域，然后释放旧内存块。
				c.若"ptr"是空指针，则函数的行为类似于"malloc"，分配一个新的大小字节块并返回一个指向其开头的指针。
				d.若无足够内存，则不释放旧内存块，并返回空指针，"ptr"指向的内存块没有被修改与释放。
				e.直至C23标准(自C17标准起被弃用)，如果"size"为零，则可能会返回空指针(可能会或可能不会释放旧的内存块)或者可能会返回一些可能不用于访问存储的非空指针。
			4."realloc"函数的返回值设计
				a.当分配成功时，返回指向新分配内存的指针；为避免内存泄漏，必须用"free"函数或"realloc"函数释放返回的指针。
				b.当分配失败时，返回一个空指针，原指针"ptr"保持有效，并需要通过"free"函数或"realloc"函数释放。
			5.未定义行为
				a.重新分配的内存区域必须是之前为"malloc"函数、"calloc"函数、"realloc"函数所分配，并且仍未被"free"函数或"realloc"函数的调用所释放，否则结果未定义。
				b.当分配成功时，若原指针"ptr"被非法化，任何通过它的访问都是未定义行为(即使重分配是就地的)。
				c.自C23标准起，如果"size"为零，则行为未定义。
		4."free"函数：释放内存块。
			1.头文件："stdlib.h"。
			2.函数声明：void free(void* ptr);。
				a.函数头"void"表示此函数无返回值。
				b.函数参数"void* ptr"：将无类型指针作为参数；在此函数中意为指向要释放的内存块的指针。
			3.函数说明
				a.释放之前由"malloc"函数、"calloc"函数、"realloc"函数、"aligned_alloc"函数(C11起)分配的内存块空间。
				b.此函数接收空指针(并对其不处理)以减少特例的数量。不管分配成功与否，分配函数返回的指针都能传递给"free"函数。
				c.如果"ptr"是一个空指针，该函数什么也不做。
				d.此函数不会更改"ptr"本身的值，因此它仍然指向相同(无效)的位置，故可能需要将"ptr"置成空指针。
			4.未定义行为
				a.若"ptr"的值不等于之前从"malloc"函数、"calloc"函数、"realloc"函数、"aligned_alloc"函数(C11起)返回的值，则行为未定义。
				b.若"ptr"所指代的内存区域已经被释放，则行为未定义。
				c.若在"free"函数返回后通过指针"ptr"访问内存，则行为未定义(除非另一个分配函数恰好返回等于"ptr"的值)。
*/

////动态内存函数使用示例
//void Free(int** ptr)
//{
//	//"free"函数使用示例
//	free(*ptr);
//	*ptr = NULL;
//}
//
//void If_Error(int* ptr)
//{
//	if (ptr == NULL)
//	{
//		perror("ptr");//打印错误信息。
//		exit(1);
//	}
//}
//
//void Init_For_Zero(int num, int* ptr)
//{
//	for (int i = 0; i < num; i++)
//	{
//		*(ptr + i) = 0;
//	}
//}
//
//void Init_For_One(int num, int* ptr)
//{
//	for (int i = 0; i < num; i++)
//	{
//		*(ptr + i) = 1;
//	}
//}
//
//void Point(int num, int* ptr)
//{
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d ", ptr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int* ptr = NULL;
//	int num = 10;
//
//	//"malloc"函数使用示例
//	ptr = (int*)malloc(num * sizeof(int));
//	If_Error(ptr);
//	Init_For_Zero(num, ptr);
//	Point(num, ptr);
//	Free(&ptr);
//	
//	//"calloc"函数使用示例
//	ptr = (int*)calloc(num, sizeof(int));//"calloc"函数会默认初始化所有分配存储中的字节为零。
//	If_Error(ptr);
//	Point(num, ptr);
//	Free(&ptr);
//
//	//"realloc"函数使用示例
//	ptr = (int*)calloc(num, sizeof(int));//先使用"calloc"函数分配内存块并初始化为零。
//	If_Error(ptr);
//	Point(num, ptr);
//	num = 20;
//	int *ptmp = (int*)realloc(ptr, num * sizeof(int));//使用"realloc"函数调整内存空间为"num"个"int"的大小；使用临时指针接收"realloc"函数的返回值，防止错误。
//	If_Error(ptmp);
//	ptr = ptmp;
//	Init_For_One(num, ptr);
//	Point(num, ptr);
//	Free(&ptr);
//	
//	return 0;
//}

/**
	常见的动态内存错误
		1.对空指针的解引用操作：在使用内存函数时，若需要开辟的内存块空间过大可能会开辟失败，当分配失败时会返回一个空指针，对空指针进行解引用赋值操作会导致写入访问权限冲突，故每次开辟后需要进行指针有效性检查。
		2.对动态开辟空间的越界访问：即超出了合法空间进行访问，导致程序崩溃
		3.对非动态开辟内存使用"free"函数释放
		4.使用"free"函数释放一块动态开辟内存的一部分
		5.对同一块动态内存多次释放
		6.动态开辟内存忘记释放(内存泄漏)
*/

////常见的动态内存错误示例一：对空指针的解引用操作。(以下为错误程序)
//int main()
//{
//	int* p = (int*)malloc(40);
//	*p = 20;
//	free(p);
//	return 0;
//}

////常见的动态内存错误示例一：对空指针的解引用操作。(以下为正确程序)
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	*p = 20;
//	free(p);
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例二：对动态开辟空间的越界访问。(以下为错误程序)
//int main()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		perror("malloc");
//		return 1;
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当"i"是"10"的时候导致越界访问，程序崩溃。
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例二：对动态开辟空间的越界访问。(以下为正确程序)
//int main()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		perror("malloc");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例三：对非动态开辟内存使用"free"函数释放。(以下为错误程序)
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//未定义行为：若"p"的值不等于之前从"malloc"函数、"calloc"函数、"realloc"函数、"aligned_alloc"函数(C11起)返回的值，则行为未定义。
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例三：对非动态开辟内存使用"free"函数释放。(以下为正确程序)
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	free(p);
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例四：使用"free"函数释放一块动态开辟内存的一部分。(以下为错误程序)
//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;//改变了"p"指针所指向的动态内存的起始位置。
//	free(p);//只释放了一块动态开辟内存的一部分。
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例四：使用"free"函数释放一块动态开辟内存的一部分。(以下为正确程序)
//int main()
//{
//	int* p = (int*)malloc(100);
//	int* tmp = p + 1;
//	free(p);//释放完整的一块动态开辟内存。
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例五：对同一块动态内存多次释放。(以下为错误程序)
//int main()
//{
//	int* p = (int*)malloc(40);
//	free(p);
//	p = NULL;
//	free(p);//未定义行为：若"p"所指代的内存区域已经被释放，则行为未定义。
//	return 0;
//}

////常见的动态内存错误示例五：对同一块动态内存多次释放。(以下为正确程序)
//int main()
//{
//	int* p = (int*)malloc(40);
//	free(p);
//	p = NULL;
//	return 0;
//}

////常见的动态内存错误示例六：动态开辟内存忘记释放(内存泄漏)。(以下为错误程序)
//void Test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//	perror("malloc");
//	return;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////常见的动态内存错误示例六：动态开辟内存忘记释放(内存泄漏)。(以下为正确程序)
//void Test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//		free(p);
//	}
//	perror("malloc");
//	return;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/**
	笔试题：以下笔试题例题皆在"VS2022"及"x64"环境下运行。
*/

/***
	笔试题例一
		解答：无任何显示，"GetMemory(str);"为传值调用函数，是将"str"指针变量的值"NULL"传参给函数"GetMemory"中的形参"p"("p"相当于"str"的一份临时拷贝)，"p"被赋值成"NULL"。
			"GetMemory"函数中开辟的内存块由"p"指针指向，无关"str"，离开"GetMemory"函数后"p"的生命周期结束被回收，故开辟的内存块无指针指向，并且没有释放，造成内存泄漏。
			"strcpy_s(str, 100, "hello world");"语句将"str"的值"NULL"更改为"hello world"，属于对野指针的访问操作，会导致程序崩溃报错。
		改进方法
			1.将"GetMemory"函数设计成返回"malloc"函数的返回值，并且使用完毕后释放内存块以及将指向内存块的指针置成空指针。
			2.将传值调用改成传址调用，并且"GetMemory"函数的接收参数改成二级指针，通过解引用二级指针找到一级指针并赋值成"malloc"函数的返回值，并且使用完毕后释放内存块以及将指向内存块的指针置成空指针。
*/

////笔试题例一(原题)：请问运行"Test"函数会有什么样的结果？
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy_s(str, 100, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////笔试题例一(改进版一)
//char* GetMemory()
//{
//	return (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	strcpy_s(str, 100, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////笔试题例一(改进版二)
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy_s(str, 100, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/***
	笔试题例二：请问运行"Test"函数会有什么样的结果？
		解答："GetMemory"函数内部创建的数组是在栈区上创建的，返回"p"相当于返回数组首元素的地址，但数组是局部变量，离开"GetMemory"函数后的生命周期结束被回收，
			返回的地址便没有了实际意义，"str"被赋值成"GetMemory"函数的返回值，故为野指针，如果通过返回的地址去访问内存就是非法访问内存。
		改进方法
			1.声明数组前加上"static"关键字。
			2.直接返回文字常量区的地址。
*/

////笔试题例二(原题)
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////笔试题例二(改进版一)
//char* GetMemory(void)
//{
//	static char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////笔试题例二(改进版二)
//char* GetMemory(void)
//{
//	return "hello world";
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/***
	笔试题例三：请问运行"Test"函数会有什么样的结果？
		解答：内存泄露。
		改进方法：使用完毕后释放内存块以及将指向内存块的指针置成空指针。
*/

////笔试题例三(原题)
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy_s(str, 100, "hello");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////笔试题例三(改进版)
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy_s(str, 100, "hello");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/***
	笔试题例四：请问运行"Test"函数会有什么样的结果？
		解答：非法访问内存。
		改进方法：使用完毕后释放内存块以及将指向内存块的指针置成空指针。

*/

////笔试题例四(原题)
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

////笔试题例四(改进版)
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/**
	C与C++程序的内存开辟
		1. 栈区(stack)
			a.在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放。
			b.栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。
			c.栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。
			d.由下增长。
		2. 堆区(heap)
			a.一般由程序员分配释放，若程序员不释放，程序结束时可能由系统回收。
			b.分配方式类似于链表。
			c.由上增长。
		3. 数据段(静态区)：存放全局变量、静态数据("static"关键字修饰的变量)；程序结束后由系统释放。
		4. 代码段：存放函数体(类成员函数和全局函数)的二进制代码、可执行代码、只读常量等。
*/

////C与C++程序的内存开辟示例
//int globalVal;//全局变量，存放于内存中的数据段(静态区)，此处"globalVal"变量的值为：0。
//static int staticGlobalVal = 0;//静态数据("static"关键字修饰的变量)，存放于内存中的数据段(静态区)。
//int main()
//{
//	static int staticVar = 0;//静态数据("static"关键字修饰的变量)，存放于内存中的数据段(静态区)。
//	int localVar = 0;//局部变量，存放于内存中的栈区。
//	int arr[10] = { 0 };//局部变量，存放于内存中的栈区。
//	char str[] = "KilluaAoki";//局部变量，存放于内存中的栈区；""KilluaAoki""存放于文字常量区(代码段)。
//	char* ptr1 = "KilluaAoki";//局部变量，存放于内存中的栈区；""KilluaAoki""存放于文字常量区(代码段)。
//	int* ptr2 = (int*)malloc(sizeof(int) * 10);//局部变量，存放于内存中的栈区；"malloc"函数是在堆区开辟的内存块。
//	int* ptr3 = (int*)calloc(10, sizeof(int));//局部变量，存放于内存中的栈区；"calloc"函数是在堆区开辟的内存块。
//	int* ptr4 = (int*)realloc(ptr3, sizeof(int) * 20);//局部变量，存放于内存中的栈区；"realloc"函数是在堆区开辟的内存块。
//
//	free(ptr2);
//	free(ptr4);
//	ptr2 = NULL, ptr3 = NULL, ptr4 = NULL;
//
//	return 0;
//}

/**
	柔性数组：C99标准中，结构体中的最后一个元素允许是未知大小的数组，这就叫做"柔性数组"成员。
		1.柔性数组的特点
			a.结构体中的柔性数组成员前面必须至少有一个其他成员。
			b."sizeof"关键字计算这种结构体的大小不包括柔性数组的内存。
			c.包含柔性数组成员的结构体用"malloc"函数进行内存的动态分配时，分配的内存应该大于结构的大小，以适应柔性数组的预期大小。
		2.柔性数组的使用
		3.柔性数组的优势
			a.方便内存释放：如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。
				用户调用"free"函数可以释放结构体，但是用户并不知道这个结构体内的成员也需要"free"函数，所以你不能指望用户来发现这个事。
				所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体指针，用户做一次内存释放就可以把所有的内存也给释放掉。
			b.有利于访问速度：连续的内存有益于提高访问速度，也有益于减少内存碎片。
		4.博客拓展：https://coolshell.cn/articles/11377.html。
*/

////柔性数组的使用示例
//struct S1
//{
//	int n;
//	int arr[];//声明柔性数组的第一种方式；此柔性数组的大小未知。
//};
//
//struct S2
//{
//	int n;
//	int arr[0];//声明柔性数组的第二种方式；此柔性数组的大小未知。
//};
//
//int main()
//{
//	//初始化
//	struct S1* ps1 = (struct S1*)malloc(sizeof(struct S1) + 20 * sizeof(int));
//	if (ps1 == NULL)
//	{
//		perror("main");
//		return 1;
//	}
//	ps1->n = 20;
//	for (int i = 0; i < ps1->n; i++)
//	{
//		ps1->arr[i] = i;
//	}
//
//	//调整内存块
//	struct S1* ptr = (struct S1*)realloc(ps1, sizeof(struct S1) + 10 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps1 = ptr;
//		ptr = NULL;
//	}
//	ps1->n = 10;
//
//	//使用
//	for (int i = 0; i < ps1->n; i++)
//	{
//		printf("%d ", ps1->arr[i]);
//	}
//	
//	//释放
//	free(ps1);
//	ps1 = NULL;
//
//	return 0;
//}