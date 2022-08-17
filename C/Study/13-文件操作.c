#include <stdio.h>
#include <string.h>
#include <Windows.h>

/*
	文件操作
		1.文件
		2.文件的打开和关闭
		3.文件的顺序读写相关函数
		4.文件的随机读写相关函数
		5.文本文件和二进制文件
		6.文件读取结束的判定
		7.文件缓冲区
*/

/**
	文件
		1.使用文件的原因：程序的数据可以存放到电脑的外存中(即硬盘)，使数据的持久化。
		2.什么是文件：在程序设计中，文件一般分为程序文件和数据文件，这是从文件功能的角度进行分类的。
			a.程序文件：包含源程序文件、目标文件、可执行程序。
			b.数据文件：文件的内容不一定是程序本身，而是程序运行时需要读取或写入的数据，也就是程序运行时需要从中读取数据的文件或输出内容的文件。
			c.文件名：一个文件需要有一个唯一的文件标识，以便于用户或系统识别以及引用。
				1.此处的文件名(文件标识)包含了文件的存放路径、文件名主干以及文件名的后缀。
				2.在C语言中可用字符串表示文件名，"\"可区分文件夹与文件，但字符串中"\"会表示为转义字符，故需要再添加"\"转义"\"，防止它被解释为一个转义序列符。
				3.文件的路径分为绝对路径和相对路径，绝对路径是一个文件实际存在于硬盘中的路径，而相对路径指的是与自身程序相关的位置。
*/

/**
	文件的打开和关闭
		1.文件指针：缓冲文件系统中，关键的概念是"文件类型指针"，简称"文件指针"。
			a.每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息，这些信息保存在一个结构体变量中，该结构体类型是由系统(编译器)声明的，即"FILE"。
			b.通过一个"FILE"类型的指针变量可以维护这个"FILE"结构类型的变量，并且能够找到与它关联的文件。
			c.不同的C编译器中的"FILE"结构体类型包含的内容并不完全相同，但是大同小异。
			d.每次打开一个文件的时候，系统(编译器)会根据文件的信息自动创建一个"FILE"类型的结构体变量，并填充结构体中的信息。
		2.文件的打开和关闭相关函数："fopen"函数和"fclose"函数。
			a.文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
			b.编写程序时，使用相关函数打开文件会返回一个指向"FILE"结构体类型的指针变量，用于指向该文件的文件信息区，也就相当于建立了指针和文件的关系。
*/

/***
	文件打开与关闭相关函数
		1."fopen"函数：打开文件。
			1.头文件："stdio.h"。
			2.函数声明：FILE* fopen(const char* filename, const char* mode);。
				a.函数头"FILE*"表示此函数的返回值是文件(结构体)指针类型，在此函数中意为返回指向新文件流的指针或空指针。
				b.函数参数"const char* filename"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为将文件流关联到的文件名(字符串)。
				c.函数参数"const char* mode"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为确定文件的访问模式(字符串)。
			3.函数说明
				a.打开"filename"所指示的文件，并返回指向关联到该文件的文件流的指针，"mode"用于确定文件访问模式。
				b.如果成功，则返回指向新文件流的指针；出错时，返回一个空指针，并且"errno"变量也设置为失败时特定于系统的错误代码。
				c."filename"除非涉及交互式设备，否则流是完全缓冲的。
				d."filename"的格式是实现定义的，而且不需要表示一个文件(可以是控制台或另一能通过文件系统"API"访问的设备)；在支持的平台上，"filename"可以包含绝对或相对路径。
				e.文件的访问模式(字符串)：https://zh.cppreference.com/w/c/io/fopen。
			4.未定义情况：如果"mode"是无效的字符串，则行为未定义。
		2."fclose"函数：关闭文件。
			1.头文件："stdio.h"。
			2.函数声明：int fclose(FILE* stream);。
				a.函数头"int"表示此函数的返回值是整型类型，在此函数中意为关闭文件成功时返回"0"，否则为"EOF"。
				b.函数参数"FILE* stream"：将文件(结构体)指针类型作为参数；在此函数中意为需要关闭的文件流。
			3.函数说明
				a.关闭给定的文件流，任何未写入的缓冲数据都会刷新到操作系统，任何未读的缓冲数据都将被丢弃。
				b.无论操作是否成功，流不再与文件关联。
			4.未定义情况：如果关闭文件之后再使用指针"stream"的值，则行为未定义。
*/

////文件打开与关闭相关函数使用示例：于"VS2022"中无法使用"fopen"，若要使用需使用"_CRT_SECURE_NO_WARNINGS"，此处以"fopen_s"进行演示打开文件操作，但其返回值和参数与"fopen"不相同，"fopen_s"具体使用方法请查看文档。
//int main()
//{
//	FILE* pf;//定义"pf"变量是一个指向"FILE"结构体类型数据的指针变量，可以使"pf"指向某个文件的文件信息区(结构体变量)，通过该文件信息区中的信息就能够访问文件，即通过文件指针变量找到与它关联的文件。
//	
//	fopen_s(&pf, "Test.txt", "wx");//"w"：写(创建文件以写入)，若文件已存在则销毁内容，若文件不存在则创建新文件；文件访问模式标志"x"可以附加到"w"或者"w+"后，如果文件存在，此标志会强制函数失败而不是重写它。
//	
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

/**
	文件的顺序读写相关函数
		1."fgetc"函数：从流中获取字符，适用于所有输入流；文档：https://zh.cppreference.com/w/c/io/fgetc。
		2."fputc"函数：将字符写入流，适用于所有输出流；文档：https://zh.cppreference.com/w/c/io/fputc。
		3."fgets"函数：从流中获取字符串，适用于所有输入流；文档：https://zh.cppreference.com/w/c/io/fgets。
		4."fputs"函数：将字符串写入流，适用于所有输出流；文档：https://zh.cppreference.com/w/c/io/fputs。
		5."fscanf"函数：从流中读取格式化数据，适用于所有输入流；文档：https://zh.cppreference.com/w/c/io/fscanf。
		6."fprintf"函数：将格式化的数据写入流，适用于所有输出流；文档：https://zh.cppreference.com/w/c/io/fprintf。
		7."fread"函数：从流中读取数据块，适用于文件；文档：https://zh.cppreference.com/w/c/io/fread。
		8."fwrite"函数：将数据块写入流，适用于文件；文档：https://zh.cppreference.com/w/c/io/fwrite。
		9.拓展函数："sscanf"函数、"sprintf"函数。
*/

////文件顺序读写相关函数使用示例
//struct MyStruct
//{
//	char name[20];
//	int age;
//	float weight;
//};
//
//int main()
//{
//	//打开文件
//	FILE* pf;
//	fopen_s(&pf, "Test.txt", "w+");//"w+"：写扩展(创建文件以读/写)，其余与"w"相同。
//
//	//判空
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	////"fgetc"函数和"fputc"函数使用示例(文件流)
//	//fputc('A', pf);//将字符"A"，写入文件流。
//	//rewind(pf);//让文件指针的位置回到文件的起始位置，若不回到起始位置"fgetc"函数调用时流位于文件末尾，函数会返回"EOF"并设置流的文件结尾指示符。
//	//printf("%c", fgetc(pf));//从文件流中获取字符，再将其返回值作为字符类型进行打印。
//	
//	////"fgetc"函数和"fputc"函数使用示例(标准输入流与标准输出流)
//	//fputc('b', stdout);//将字符"A"，写入标准输出流(屏幕)。
//	//printf("\n");
//	//printf("%c", fgetc(stdin));//从标准输入流(键盘)获取字符，再将其返回值作为字符类型进行打印。
//
//	////"fgets"函数和"fputs"函数使用示例(文件流)
//	//fputs("Aoki", pf);//将包含终止空字符的字符串"Aoki"，写入文件流(不写入终止空字符)。
//	//rewind(pf);
//	//char arr[5];
//	//printf("%s", fgets(arr, 5, pf));//从文件流中获取字符串，并存储在字符数组"arr"中，再将其返回值以字符串的形式进行打印。
//	
//	////"fgets"函数和"fputs"函数使用示例(标准输入流与标准输出流)
//	//fputs("Aoki", stdout);//将包含终止空字符的字符串"Aoki"，写入标准输出流(屏幕)(不写入终止空字符)。
//	//printf("\n");
//	//char arr[5];
//	//printf("%s", fgets(arr, 5, stdin));//从标准输入流(键盘)获取字符串，并存储在字符数组"arr"中，再将其返回值以字符串的形式进行打印。
//	
//	////"fscanf"函数和"fprintf"函数使用示例(文件流)
//	//fprintf(pf, "Killua%s", "Aoki");//将"Killua"以及包含终止空字符的字符串"Aoki"以字符串的形式写入到文件流(不写入终止空字符)。
//	//rewind(pf);
//	//char arr[20];
//	//fscanf_s(pf, "%s", arr, 20);//从文件流中获取字符串并写入数组"arr"；"fscanf_s"函数拓展博客：https://blog.csdn.net/apple_52109766/article/details/118084359。
//	//printf("%s", arr);
//
//	////"fscanf"函数和"fprintf"函数使用示例(标准输入流与标准输出流)
//	//fprintf(stdout, "%s\n", "Aoki");//将包含终止空字符的字符串"Aoki"以字符串的形式写入到标准输出流(屏幕)(不写入终止空字符)，然后再打印出"\n"。
//	//char arr[20];
//	//fscanf_s(stdin, "%s", arr, 20);//从标准输入流(键盘)获取字符串并写入数组"arr"。
//	//printf("%s", arr);
//
//	////"fread"函数和"fwrite"函数使用示例
//	//struct MyStruct X = { "KilluaAoki", 19, 65.5f };
//	//struct MyStruct Y = { 0 };
//	//fwrite(&X, sizeof(struct MyStruct), 1, pf);//将结构体类型变量"X"的二进制数据写入到文件流中。
//	//rewind(pf);
//	//fread(&Y, sizeof(struct MyStruct), 1, pf);//从文件流中读取二进制数据，并将数据写入结构体类型变量"Y"中。
//	//printf("%s %d %f\n", Y.name, Y.age, Y.weight);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	
//	return 0;
//}

/***
	拓展函数
		1."sscanf"函数：从字符串中读取格式化数据；文档：https://zh.cppreference.com/w/c/io/fscanf。
		2."sprintf"函数：将格式化数据写入字符串；文档：https://zh.cppreference.com/w/c/io/fprintf。
*/

////"sscanf"函数和"sprintf"函数使用示例
//struct MyStruct
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	struct MyStruct me = { "KilluaAoki",19 };
//	struct MyStruct tmp = { 0 };
//	char data[30] = { 0 };
//
//	//使用"sprintf"函数，将格式化数据写入字符串；在此使用"sprint_s"函数替换，文档：https://zh.cppreference.com/w/c/io/fprintf。
//	sprintf_s(data,30, "%s %d", me.name, me.age);
//	printf("%s\n", data);
//
//	//使用"sscanf"函数，从字符串中读取格式化数据并还原至"tmp"；在此使用"sscanf_s"函数替换，文档：https://zh.cppreference.com/w/c/io/fscanf。
//	sscanf_s(data, "%s %d", tmp.name, 20, &(tmp.age));
//	printf("%s %d\n", tmp.name, tmp.age);
//
//	return 0;
//}

/**
	文件的随机读写相关函数
		1."fseek"函数：重新定位流位置指示器；文档：https://zh.cppreference.com/w/c/io/fseek。
			a.SEEK_SET：指示从文件首开始寻位的"origin"参数。
			b.SEEK_CUR：指示从文件当前位置开始寻位的"origin"参数。
			c.SEEK_END：指示从文件尾开始寻位的"origin"参数。
		2."ftell"函数：返回流的文件位置指示器；文档：https://zh.cppreference.com/w/c/io/ftell。
		3."rewind"函数：将流的位置设置为开头；文档：https://zh.cppreference.com/w/c/io/rewind。
*/

////文件的随机读写相关函数使用示例
//int main()
//{
//	//打开文件
//	FILE* ptr;
//	fopen_s(&ptr, "Test.txt", "w+");
//	if (ptr == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//将字符串"KilluaAoki"写入到文件中，此时位置指示器应在字符串中的"i"后。
//	fputs("KilluaAoki", ptr);
//
//	//使用"ftell"函数，验证之前的假设是否正确。
//	printf("%ld\n", ftell(ptr));//结果为"10"，说明位置指示器从"K"开始为"0"，到"i"后为"10"。
//
//	//使用"rewind"函数，将流的位置设置为开头，再使用"ftell"函数验证位置指示器从"K"开始是否为"0"。
//	rewind(ptr);
//	printf("%ld\n", ftell(ptr));//结果为"0"，说明位置指示器从"K"开始为"0"。
//
//	//使用"fseek"函数，重新定位流位置指示器，再将空字符写入到"Killua"后。
//	fseek(ptr, 6, SEEK_SET);
//	fputc('\0', ptr);
//	rewind(ptr);
//	char arr[20] = { 0 };
//	printf("%s\n", fgets(arr, 20, ptr));//结果为："Killua"。
//
//	//关闭文件
//	fclose(ptr);
//	ptr = NULL;
//
//	return 0;
//}

/**
	文本文件和二进制文件
		1.根据数据的组织形式，可以数据文件分为文本类型的文件和二进制类型的文件。
		2.数据在内存中用二进制的形式存储，如果不加以转换输出到外存(硬盘)中，就是二进制文件。
		3.若是要求数据在文件中要以文本的形式进行存储，则需要在存储时加以转换。
		4.数据在文件中的存储
			a.C语言通过使用字母的数值编码存储字符("ASCII"编码)，而数值型数据既可以用数值编码的形式存储，也可以使用二进制的形式存储。
			b.以数值编码的形式存储和以二进制的形式存储，其在磁盘中占用的大小是不相同的。
			c.比如整数"10000"，若以数值编码的形式存储则在磁盘中占用五个字节，而以二进制的形式存储则在磁盘中占用四个字节。(不同环境不相同)
		5.通常以什么文件的访问模式打开文件，就以什么形式的读写函数从文件中读取数据或写入数据到文件，否则在某些地方可能会导致意想不到的结果。
*/

/**
	文件结束的判定
		1.文本文件的读取结束判断
			a.使用"fgetc"函数，判断其返回值是否为"EOF"，若为"EOF"则表示文本文件的读取已结束。
			b.使用"fgets"函数，判断其返回值是否为"NULL"，若为"NULL"则表示文本文件的读取已结束。
		2.二进制文件的读取结束判断
			a.使用"fread"函数，判断其返回值是否小于实际要读取的对象数，但其返回值小于实际要读取的对象数可能是出现了错误或二进制文件的读取实际结束。
		3.当文件的读取结束后，需要使用"feof"函数和"ferror"函数检查是否是遇到了错误导致结束还是已抵达给定的文件流的结尾导致结束。
			a.若是在文件的读取过程中产生错误导致结束，则可用"ferror"函数检查给定文件流的错误。
			b.若是在文件的读取过程中抵达给定的文件流的结尾导致结束，则可用"feof"函数检查是否已抵达给定的文件流的结尾。
		4.文件结束的判定相关函数
			a."feof"函数：检查是否已抵达给定的文件流的结尾；文档：https://zh.cppreference.com/w/c/io/feof。
			b."ferror"函数：检查给定文件流的错误；文档：https://zh.cppreference.com/w/c/io/ferror。
*/

////文本文件结束的判定示例：将"Test.txt"文本文件中的数据复制到"Test.txt.old"文本文件中。
//int main()
//{
//	FILE* ptr1;
//	fopen_s(&ptr1, "Test.txt", "w+");
//	if (ptr1 == NULL)
//	{
//		perror("fopen for Test.txt");
//		return 1;
//	}
//	
//	fputs("KilluaAoki", ptr1);//写入数据到"Test.txt"中。
//	rewind(ptr1);
//
//	FILE* ptr2;
//	fopen_s(&ptr2, "Test.txt.old", "w+");
//	if (ptr2 == NULL)
//	{
//		perror("fopen for Test.txt.old");
//		fclose(ptr1);
//		ptr1 = NULL;
//		return 1;
//	}
//
//	int ch = 0;
//	while ((ch = fgetc(ptr1)) != EOF)//文件读取结束的判定。
//	{
//		fputc(ch, ptr2);
//	}
//
//	if (ferror(ptr1))
//		puts("读取时出现I/O错误！");
//	else if (feof(ptr1))
//		puts("成功到达文件末尾！");
//	
//	fclose(ptr1);
//	fclose(ptr2);
//	ptr1 = NULL;
//	ptr2 = NULL;
//
//	return 0;
//}

////二进制文件结束的判定示例：将"Test.bin"二进制文件中的数据复制到"Test.bin.old"二进制文件中。
//int main()
//{
//	double a[5] = { 1., 2., 3., 4., 5. };
//	
//	FILE* fp;
//	fopen_s(&fp, "Test.bin", "wb");
//	fwrite(a, sizeof(*a), 5, fp);
//	fclose(fp);
//
//	double b[5];
//	fopen_s(&fp, "Test.bin", "rb");
//	size_t ret_code = fread(b, sizeof(*b), 5, fp);
//
//	if (ret_code == 5)
//	{
//		printf("Array read successfully, contents:");
//		for (int n = 0; n < 5; ++n)
//		{
//			printf("%lf ", b[n]);
//		}
//		printf("\n");
//	}
//	else
//	{
//		if (feof(fp))
//			printf("读取Test.bin时出错：文件意外结束。\n");
//		else if (ferror(fp))
//		{
//			perror("读取Test.bin时出现I/O错误");
//		}
//	}
//
//	fclose(fp);
//
//	return 0;
//}

/**
	文件缓冲区：文件缓冲区是用以暂时存放读写期间的文件数据而在内存区预留的一定空间。
		1.缓和"CPU"与"I/O"设备速度不匹配的矛盾，使用文件缓冲区可减少读取硬盘的次数。
		2.如果从内存向磁盘输出数据，会先送到内存中的缓冲区，缓冲区装满后再一起输送到磁盘上。
		3.如果从磁盘向计算机读取数据，则从磁盘文件中读取数据输入到内存缓冲区(充满缓冲区)，然后再从缓冲区逐个地将数据送到程序数据区(程序变量等)。
		4.缓冲区的大小由编译系统决定。
		5.因为有缓冲区的存在，C语言在操作文件的时候，需要刷新缓冲区或者在文件操作结束时关闭文件，否则可能导致读写文件出现问题。
		6.使用"fflush"函数可刷新缓冲区，文档：https://zh.cppreference.com/w/c/io/fflush。
*/

////文件缓冲区示例：运行以下程序并根据提示操作(可能因为占用进程而无法打开文件)。
//int main()
//{
//	FILE* pf;
//	fopen_s(&pf, "Test.txt", "w+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("KilluaAoki", pf);//将代码放在输出缓冲区。
//	
//	printf("睡眠一段时间，此时打开\"Test.txt\"文件，会发现文件没有内容。\n");
//	Sleep(10000);
//	
//	printf("刷新缓冲区\n");
//
//	fflush(pf);//"fflush"函数：强迫将缓冲区内的数据写回参数"stream"指定的文件中，若刷新成功返回"0"，如果发生错误则返回"EOF"，并且设置错误标识符；刷新缓冲区时，才将输出缓冲区的数据写入到文件(磁盘)。
//
//	printf("再睡眠一段时间，此时再次打开\"Test.txt\"文件，会发现文件有内容了。\n");
//	Sleep(10000);
//
//	fclose(pf);//"fclose"函数在关闭文件时，也会刷新缓冲区。
//	pf = NULL;
//
//	return 0;
//}