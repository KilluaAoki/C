#include <iostream>
#include <algorithm>//算法库头文件，包含了标准模板库中的算法部分，提供多种用途的函数。

/*
	STL简介
		1.STL：全称Standard Template Library，标准模板库，最初由Alexander Stepanov在C++标准化前编写。
			a.STL提供了一套通用的模板类和函数，用于操作各种数据结构和算法，如：容器、迭代器、算法、仿函数等。
			b.STL设计牢记四个思想：通用编程、不损失效率的抽象性、冯·诺依曼计算模型和值语义。
			c.Alexander Stepanov，俄裔美国计算机科学家，STL的主要设计者和实现者，1992年于HP实验室开发适用于C++的STL，早年间也曾在贝尔实验室工作。
			d.STL主要出现于C++中，但在被引入C++之前该技术就已经存在了很长时间。
		2.STL的历史
			a.1979年，Alexander Stepanov开始研究泛型编程，并探索它们在软件开发领域的革命性潜力，他也是泛型概念的主要推动者，同年间，Bjarne Stroustrup也开始开发C++。
			b.第一个提供泛型概念的语言是Ada，1987年Alexander Stepanov和David Musser已经开发并发布了一个用于列表处理的Ada库，该库体现了他们对泛型编程的大部分研究成果。
			c.1987年，在贝尔实验室工作的Alexander Stepanov注意到了C/C++语言在实现其泛型思想方面所具有的潜在优势(指针)，即使当时C++并没有提供模板。
			d.1988年Alexander Stepanov转至HP公司继续进行开发泛型程序库的工作，分别实验了多种架构和演算法公式。
			e.1992年，Meng Lee也加入其中，成为另一位主要贡献者，项目自建立之后，参与者逐渐减少，最后只剩下Alexander Stepanov和Meng Lee两个人。
			f.同年间(1992年)，Alexander Stepanov和Meng Lee在HP实验室开发出了适用于C++的STL，这便是现在STL的雏形。
			g.1993年，C++标准委员会的项目编辑Andy Koenig到斯坦福大学演讲，Alexander Stepanov便向他介绍标准模板库，随即Andy Koenig便邀请Alexander Stepanov参加1993年11月的C++标准化会议。
			h.1993年11月，Alexander Stepanov向C++标准委员会提交了一个基于泛型编程的库，其介绍了STL的基本概念和设计思想，这便是关于STL的第一次提案，获得了热烈的回应。
			i.1994年1月6日，Andy Koenig寄了封电子邮件给Alexander Stepanov，表示如果Alexander Stepanov愿意将标准模板库的帮助文档撰写齐全，并在1994年1月25日前提交，便可能成为标准C++的一部分。
			j.1994年3月的圣地亚哥会议中，STL在会议中获得了很好的反响，但也有许多反对意见，投票结果压制性的认为应该给STL一个机会，并把决定性投票推迟到下一次会议。
			k.1994年7月滑铁卢市的会议举行，但Alexander Stepanov在会议举行前，对STL做了重大改善并得到Bjarne Stroustrup的支持，在会议中以百分之八十压倒多数，于是STL进入了C++标准化的正式流程。
		3.STL实现的常见版本：由Alexander Stepanov和Meng Lee设计的原始STL属于HP实验室，1994年8月，HP公司决定在互联网上免费提供STL的实现，随着标准化过程，许多编译器和库供应商以此版本为基础开发STL，但其本身不再维护。
			a.SGI STL：即Silicon Graphics公司(美国硅谷公司)开发的STL，此公司后来更名为SGI，此公司开发的STL基于Alexander Stepanov和Meng Lee的原始STL实现，源码易于阅读，但不再维护。
			b.STLPort：基于SGI STL开发，具有效率高、异常安全和线程安全、扩展的数据结构等特点。
			c.Dinkum STL：由PJ Plauger开发，隶属于其本人创建的Dinkumware公司，是标准C库和标准C++库的主要供应商，被微软购买以及采用。
			d.Microsoft STL：Dinkum STL的授权衍生产品，由微软开发，随Visual C++一起提供，源码已在Github上开源。
			e.EASTL：由著名游戏公司Electronic Arts的Paul Pedriana开发。
*/

////STL使用示例：使用"sort"算法对数组进行排序。
//void Print(int a[], int array_size)
//{
//	for (int i = 0; i < array_size; ++i)
//	{
//		std::cout << a[i] << " ";
//	}
//	std::cout << std::endl;
//}
//
//int main()
//{
//	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, size);
//	std::sort(arr, arr + size);//"sort"是标准模板算法库中的一个函数模板。
//	Print(arr, size);
//	return 0;
//}