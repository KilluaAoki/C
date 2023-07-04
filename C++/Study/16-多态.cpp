#include <iostream>
#include <string>
#include <cstdio>

/*
	多态
		1.多态的概念
		2.多态的定义及实现
		3.抽象类
		4.多态的原理
		5.单继承和多继承关系的虚函数表
*/

/**
	多态的概念
		1.多态：同一函数在不同的对象中有不同的实现，从而实现不同对象对同一函数的不同响应。
		2.多态性：其包含编译时多态性(静态)和运行时多态性(动态)两大类。
			a.编译时多态性：通过函数重载或运算符重载实现。
			b.运行时多态性：通过函数重写来实现，也是本章的主要讨论内容。
*/

/**
	多态的定义及实现
		1.虚函数：在基类中用"virtual"关键词声明的非静态成员函数为虚函数，并支持动态调用派发。
			a.虚函数只能在非静态成员函数的首个声明(即当它在类定义中声明时)的声明说明符序列处出现。
			b.虚函数是一种成员函数，其行为可以在派生类中被覆盖。
			c.与非虚函数相反，即使没有关于该类实际类型的编译时信息，覆盖行为仍然被保留。
			d.当使用基类的指针或引用来处理派生类时，对被覆盖的虚函数的调用，将会调用在派生类中定义的行为，这种函数调用被称为虚函数调用或虚调用。
			e.虚函数调用在使用有限定名字查找(即函数名出现在作用域解析运算符的右侧)时被抑制。
		2.虚函数的覆盖(重写)
			a.若某个成员函数直接或间接从基类继承而来，且基类拥有此成员函数的声明，且该声明的名称、形参列表、"cv"限定符、引用限定符与继承自的基类的成员函数完全相同，则该成员函数在派生类也是虚函数，并且将这种情况称之为覆盖(重写)。
				a'.无论其声明中是否使用关键词"virtual"，只要满足上述条件，该成员函数就是虚函数。
				b'.无论其声明中是否使用标识符"override"(C++11)，只要满足上述条件，派生类的虚函数都将覆盖基类的虚函数。
				c'.要覆盖的基类虚函数不需要可访问或可见(代表其能声明为私有或者派生类私有继承基类)，并且派生类继承自基类的任何同名成员不妨碍覆盖确定，即使在名字查找时它们会隐藏基类的虚函数。
				d'.每个虚函数都有最终覆盖函数，它是进行虚函数调用时所执行的函数，而基类的虚成员函数是最终覆盖函数，除非派生类声明或通过多重继承继承了覆盖基类虚成员函数的另一个函数。
				e'.如果一个函数拥有多于一个最终覆盖函数，那么程序非良构。
				f'.名字相同但形参列表不同的函数并不覆盖同名的基类函数，但会构成隐藏(重定义)。
				g'.非成员函数和静态成员函数不能是虚函数。
				h'.函数模板不能被声明为"virtual"，但类模板的常规成员函数可以被声明为虚函数。
				i'.在编译时替换虚函数的默认实参。
			b.虚函数扩充了隐藏(重定义)的限制条件，称之为覆盖(重写)，即派生类的虚函数覆盖了基类的虚函数，从而使其具有了不同的行为。
			c.在覆盖基类的虚函数时，派生类的虚函数的"virtual"关键词是可选的，因派生类的虚函数继承自基类的虚函数。
			e.协变返回类型：如果派生类的成员函数覆盖基类的成员函数，那么它的返回类型必须要么相同，要么为协变。
				a'.协变的要求
					a''.两个返回类型都是到类的指针或引用(左值或右值)。
					b''.基类的成员函数的返回类型中被引用或指向的类，必须是派生类成员函数的返回类型中被引用或指向的类的无歧义且可访问的直接或间接基类。
					c''.派生类的成员函数的返回类型的"cv"限定符必须与基类成员函数的返回类型的"cv"限定符相同或比其更少。
		3.多态的构成条件
			a.具有继承关系。
			b.通过基类的指针或引用调用虚函数。
			c.被调用的函数需要必须是虚函数，并且派生类对基类的虚函数进行了覆盖。
		4.虚析构函数
			a.析构函数不会继承，但是如果基类将其析构函数声明为"virtual"，那么派生的析构函数始终覆盖它，这样就可以通过指向基类的指针"delete"动态分配的多态类型对象。
			b.如果基类的析构函数非虚，则通过指向该基类的指针删除派生类对象是未定义行为，无论不调用派生的析构函数时是否会导致内存泄漏(除非选择的解分配函数是销毁的"operator delete"(C++20起))。
			c.建议凡是当涉及"delete"表达式，任何基类的析构函数必须为公开且虚或受保护且非虚。
		5."override"说明符(C++11起)和"final"说明符(C++11起)
			a.说明符是拥有特殊含义的标识符，它们可以用作对象或函数的名字，但在特定语境拥有特殊含义。
				a'.在函数的声明符之后，带有可选的虚说明符序列和可选的纯说明符。
				b'.如果存在虚说明符序列，那么它必须是"override"、"final"、"final override"或"override final"之一。
			b."override"说明符：指定一个虚函数覆盖另一个虚函数，其紧随成员函数声明或类定义内的成员函数定义语法中的声明符之后出现。
				a'.在成员函数声明中，"override"可以在紧随声明符之后并在纯说明符(若有)之前的虚说明符序列中出现。
				b'.在类定义内成员函数定义中，"override"可以在紧随声明符之后并紧接函数体之前的虚说明符序列中出现。
				c'.在成员函数的声明或定义中，"override"说明符确保该函数为虚函数并覆盖某个基类中的虚函数，否则程序程序编译报错。
				d'."override"是在成员函数声明符之后使用时拥有特殊含义的标识符：其他情况下它不是保留的关键词。
			c."final"说明符：指定某个虚函数不能在派生类中被覆盖，或者某个类不能被派生。
				a'.当应用到成员函数时，标识符"final"在类定义中的成员函数声明或成员函数定义的语法中，紧随声明符之后出现。
					a''.在成员函数声明中，"final"可以在紧跟声明符之后的虚说明符序列中出现，如果有使用纯说明符(若有)那么就会在它之前。
					b''.在类定义内的成员函数定义中，"final"可以在紧跟声明符之后并紧接函数体之前的虚说明符序列中出现。
					c''.当在虚函数声明或定义中使用时，"final"说明符确保函数为虚并指定它不能被派生类覆盖，否则程序程序编译报错。
				b'.当应用到类时，标识符"final"在类定义的开头，紧跟类名之后出现。
					a''.在类定义中，"final"可以在紧跟类名之后，紧接基类子句(若有)起头的冒号之前，作为类虚说明符出现。
					b''.如果有使用类虚说明符则只允许"final"。
					c''.当在类定义中使用时，"final"指定此类不能在另一类的定义中的基类说明符中出现(即不能派生它)，否则程序程序编译报错。
				c'."final"是在成员函数声明或类头部中使用时有特殊含义的标识符，其他语境中它未被保留，而且可用于命名对象或函数。
*/

////多态的定义及实现示例一：多态的使用。(尝试破坏多态的条件以观察整个程序的运行结果)
//class Person
//{
//public:
//	//虚函数
//	virtual void BuyTicket()
//	{
//		std::cout << "Person-全价" << std::endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	//"Student::BuyTicket()"覆盖"Person::BuyTicket()"
//	virtual void BuyTicket()//此处的"virtual"关键词是可选的。
//	{
//		std::cout << "Student-半价" << std::endl;
//	}
//};
//
//class Soldier : public Person
//{
//public:
//	//"Soldier::BuyTicket()"覆盖"Person::BuyTicket()"
//	virtual void BuyTicket()
//	{
//		std::cout << "Soldier-优先" << std::endl;
//	}
//};
//
//void BuyTicket(Person& person)
//{
//	person.BuyTicket();
//}
//
//int main()
//{
//	Person person;
//	Student student;
//	Soldier soldier;
//
//	//通过基类的指针调用虚函数
//	Person* p1 = &person;
//	Person* p2 = &student;//切片行为，基类的指针只可见基类的成员，而不可见派生类的成员，即只可见派生类对象中继承自基类的成员实例的那一部分。
//	Person* p3 = &soldier;//切片行为。
//	p1->BuyTicket();//打印：全价。
//	p2->BuyTicket();//打印：半价。
//	p3->BuyTicket();//打印：优先购票。
//
//	std::cout << std::endl;
//
//	//通过基类的引用调用虚函数
//	Person& r1 = person;
//	Person& r2 = student;//切片行为。
//	Person& r3 = soldier;//切片行为。
//	r1.BuyTicket();//打印：全价。
//	r2.BuyTicket();//打印：半价。
//	r3.BuyTicket();//打印：优先购票。
//
//	std::cout << std::endl;
//
//	//普通调用，与调用的对象类型有关。
//	person.BuyTicket();//打印：全价。
//	student.BuyTicket();//打印：半价。
//	soldier.BuyTicket();//打印：优先购票。
//
//	std::cout << std::endl;
//
//	//多态调用，与指针或引用指代的对象有关。
//	BuyTicket(person);//打印：全价。
//	BuyTicket(student);//打印：半价。
//	BuyTicket(soldier);//打印：优先购票。
//
//	std::cout << std::endl;
//
//	return 0;
//}

////多态的定义及实现示例二：覆盖不可见的虚函数。
//class B
//{
//	virtual void do_f()
//	{
//		std::cout << "B::do_f()" << std::endl;
//	}
//
//public:
//	void f()
//	{
//		do_f();
//	}
//};
//
//struct D : public B
//{
//	//覆盖"B::do_f()"
//	virtual void do_f()
//	{
//		std::cout << "D::do_f()" << std::endl;
//	}
//};
//
//int main()
//{
//	D d;
//	B* bp = &d;
//
//	bp->f();//内部调用"D::do_f()"，即要覆盖的"B::do_f()"不需要可访问或可见。
//
//	return 0;
//}

////多态的定义及实现示例三：最终覆盖函数。
//struct A
//{
//	//虚函数
//	virtual void f()
//	{
//		std::cout << "A::f()" << std::endl;
//	}
//};
//
//struct B : A
//{
//	//"B"中的"f()"覆盖"A"中的"f()"
//	void f()
//	{
//		std::cout << "B::f()" << std::endl;
//	}
//};
//
//struct C : virtual B//虚继承。
//{
//	//"C"中的"f()"覆盖"A"中的"f()"
//	void f()
//	{
//		std::cout << "C::f()" << std::endl;
//	}
//};
//
//struct D : virtual B//虚继承。
//{
//	//"D"不引入覆盖函数，最终覆盖函数是"B::f()"。
//};
//
//struct E : C, D//"E"不引入覆盖函数，最终覆盖函数是"C::f()"。
//{
//	using A::f;//引入"A::f()"，使得"A::f()"在"E"中可见。
//};
//
//int main()
//{
//	E e;
//	e.f();//虚调用"e"中的最终覆盖函数"C::f()"。
//	e.E::f();//非虚调用调用在"E"中可见的"A::f()"。
//	return 0;
//}

////多态的定义及实现示例四：多个最终覆盖函数。
//struct A
//{
//	virtual void f();
//};
//
//struct VB1 : virtual A
//{
//	void f();//覆盖"A::f()"。
//};
//
//struct VB2 : virtual A
//{
//	void f();//覆盖"A::f()"。
//};
//
////struct Error : VB1, VB2
////{
////	//错误："A::f()"在"Error"中拥有两个最终覆盖函数。
////};
//
//struct Okay : VB1, VB2
//{
//	void f();//"A::f()"的最终覆盖函数。
//};
//
////不声明覆盖函数
//struct VB1a : virtual A
//{
//};
//
////在"Da"中，"A::f()"的最终覆盖函数是"VB1a::f()"。
//struct Da : VB1a, VB2
//{
//};

////多态的定义及实现示例五：协变。
//class Person
//{
//public:
//	virtual Person* f()
//	{
//		std::cout << "Person::f()" << std::endl;
//		std::cout << "Person* = " << this << std::endl;
//		return this;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual Student* f()
//	{
//		std::cout << "Student::f()" << std::endl;
//		std::cout << "Student* = " << this << std::endl;
//		return this;
//	}
//};
//
//int main()
//{
//	Student student;
//	Person* person = &student;
//
//	auto p = person->f();//协变，返回"Student*"。
//	std::cout << "p = " << p << std::endl;
//
//	return 0;
//}

////多态的定义及实现示例六：虚析构函数。
//class Person
//{
//public:
//	~Person()
//	{
//		std::cout << "Person delete:" << _p << std::endl;
//		delete[] _p;
//	}
//
//protected:
//	int* _p = new int[10];
//};
//
//class Student : public Person
//{
//public:
//	~Student()
//	{
//		std::cout << "Student delete:" << _s << std::endl;
//		delete[] _s;
//	}
//
//protected:
//	int* _s = new int[20];
//};
//
//int main()
//{
//	//场景一：虚析构。
//	Person* ptr1 = new Person;
//	Person* ptr2 = new Student;
//	delete ptr1;
//	delete ptr2;//若"Person"类的析构函数非虚，则"delete ptr2"时，只会调用基类的析构函数(普通调用)，而不会调用派生类的析构函数，导致派生类的资源无法释放，造成内存泄漏。
//
//	std::cout << std::endl;
//
//	//场景二：正常析构。
//	Person person;
//	Student student;
//
//	return 0;
//}

////多态的定义及实现示例七：说明符"override"的使用。
//struct A
//{
//	virtual void foo();
//
//	void bar();
//};
//
//struct B : A
//{
//	//void foo() const override;//错误，"cv"限定符不匹配，即签名不匹配，"B::foo()"不覆盖"A::foo()"。
//	void foo() override;//正确，"B::foo()"覆盖"A::foo()"。
//	//void bar() override;//错误，"A::bar()"不是虚函数，只有虚成员函数可以标记为"override"。
//};

////多态的定义及实现示例八：说明符"final"的使用。
//struct Base
//{
//	virtual void foo();
//};
//
//struct A : Base
//{
//	void foo() final;//"Base::foo()"被覆盖而"A::foo()"是最终覆盖函数。
//	//void bar() final;//错误："bar"不是虚拟成员函数。
//};
//
//struct B final : A//"B"是"final"类，不能被继承。
//{
//	//void foo() override;//错误，"foo"不能被覆盖，因为它在"A"中是"final"的。
//};
//
////struct C : B{};//错误："B"是"final"类，不能被继承。

/**
	抽象类
		1.纯说明符：即序列"=0"，紧跟虚函数的声明符之后出现，若有可选的虚说明符("override"说明符以及"final"说明符)，则在虚说明符之后出现。
			a.当带有了纯说明符，则说明这个虚函数为纯虚函数，而包含纯虚函数的类叫做抽象类(又称接口类)，抽象类定义不能被实例化，但可以用作基类的抽象类型。
			b.派生类继承抽象类后也不能实例化出对象，只有覆盖纯虚函数，派生类才能实例化出对象，并且不能声明抽象类类型的非静态数据成员。
			c.纯说明符不能在成员函数定义(即在类体中不能与函数体同时出现)或友元声明中出现，因此纯虚函数的定义需在类体外，并且如果纯虚函数是析构函数则必须提供。
			d.抽象类是定义或继承了至少一个最终覆盖函数是纯虚函数的类。
			e.抽象类型不能用作形参类型，函数返回类型，或显式转换的类型。(在函数定义点和函数调用点检查，在函数声明点其形参和返回类型可以是不完整类型)
			f.可以声明到抽象类的指针或引用。
			g.派生类的成员函数可以自由地用有限定的函数标识调用抽象基类的纯虚函数，但从抽象类的构造函数或析构函数中进行纯虚函数的虚调用是未定义行为。
		2.接口继承和实现继承
			a.普通函数的继承是一种实现继承，派生类继承了基类函数，可以使用函数，继承的是函数的实现。
			b.虚函数的继承是一种接口继承，派生类继承的是基类虚函数的接口，目的是为了覆盖，从而达成多态，继承的是接口。
*/

////抽象类示例：纯虚函数。
//class Animal
//{
//public:
//	virtual void eat() = 0;//纯虚函数。
//	virtual void sleep() = 0;//纯虚函数。
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void eat()
//	{
//		std::cout << "Cat eat" << std::endl;
//	}
//
//	virtual void sleep()
//	{
//		std::cout << "Cat sleep" << std::endl;
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	virtual void eat()
//	{
//		std::cout << "Dog eat" << std::endl;
//	}
//
//	virtual void sleep()
//	{
//		std::cout << "Dog sleep" << std::endl;
//	}
//};

/**
	多态的原理
		1.虚函数表
			a.虚函数表是用于存放虚函数地址的一张表，又称为虚表，实际上由函数指针数组实现，当类中声明了虚函数时，虚函数的地址就会被放入虚函数表中。
			b.一个含有虚函数的类中，都至少有一个虚函数表指针，这个指针指向虚函数表，即指向函数指针数组的指针。
			c.当派生类继承了基类的虚函数，那么派生类中同样会有虚函数表指针。
			d.派生类的虚表的生成是先将基类的虚表拷贝过来，如果派生类中覆盖了基类的某个虚函数，那么就将派生类中对应的虚函数地址替换掉原有基类中的虚函数地址。
			e.虚函数表的地址存放在对象的内存空间中，即对象的内存空间中存放了虚函数表指针，虚函数表指针指向虚函数表，虚函数表中存放了虚函数的地址。
			f.当使用基类的指针或引用调用虚函数时，存在基类和派生类对象赋值转换行为，若基类指针或引用指向派生类对象，那么将通过派生类对象的虚函数表指针找到派生类的虚函数表，从而调用属于派生类的虚函数，完成多态行为。
		2.动态绑定与静态绑定
			a.静态绑定：在编译阶段就能确定调用的函数地址，即在编译阶段就能确定调用的函数地址，即在编译阶段就能确定调用的是哪个函数，也就是编译时多态性。
			b.动态绑定：在运行阶段才能确定调用的函数地址，即在运行阶段才能确定调用的是哪个函数，是在程序运行期间，根据具体拿到的类型确定程序的具体行为，调用具体的函数，也就是运行时多态性。
*/

////多态的原理示例一：观察虚函数表。(结合调试观察对象的内存空间)
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Base::Func1()" << std::endl;
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "Base::Func2()" << std::endl;
//	}
//
//	void Func3()
//	{
//		std::cout << "Base::Func3()" << std::endl;
//	}
//
//private:
//	int m_Value{};
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Derive::Func1()" << std::endl;
//	}
//
//private:
//	int m_Value{};
//};
//
//int main()
//{
//	Base base;
//	Derive derive;
//
//	//普通调用
//	Base* ptr = &base;
//	ptr->Func3();
//	ptr = &derive;
//	ptr->Func3();
//
//	//多态调用
//	ptr = &base;
//	ptr->Func1();
//	ptr = &derive;
//	ptr->Func1();
//
//	return 0;
//}

////多态的原理示例二：虚函数表与内存。(可能在不同操作系统或编译器(链接器)中有所不同)
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Base::Func1()" << std::endl;
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "Base::Func2()" << std::endl;
//	}
//
//	void Func3()
//	{
//		std::cout << "Base::Func3()" << std::endl;
//	}
//
//public:
//	int m_Value{};
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Derive::Func1()" << std::endl;
//	}
//
//public:
//	int m_Value{};
//};
//
//void Test()
//{
//	std::cout << "Test()" << std::endl;
//}
//
//int main()
//{
//	Base base;
//	Derive derive;
//
//	//以零初始化的局部变量：存储于栈中。
//	int val = 0;
//	std::cout << "栈：" << &val << std::endl;
//
//	//由"new"关键词申请的空间：存储于堆中。
//	int* ptr = new int;
//	std::cout << "堆：" << ptr << std::endl;
//	delete ptr;
//
//	//以零初始化的局部静态变量：存储于未初始化的数据段中。
//	static int sp1 = 0;
//	std::cout << "未初始化的数据段：" << &sp1 << std::endl;
//
//	//已初始化的局部静态变量：存储于已初始化的数据段中的初始化读写区中。
//	static int sp2 = 100;
//	std::cout << "已初始化的数据段(初始化读写区)：" << &sp2 << std::endl;
//
//	//字符串字面量：存储于已初始化的数据段中的初始化只读区中。
//	const char* str1 = "hello";
//	std::cout << "已初始化的数据段(初始化只读区)：" << (void*)str1 << std::endl;
//
//	//函数：存储于代码段中。
//	std::cout << "代码段：" << (void*)Test << std::endl;
//
//	//对象中的数据成员：存储于对象的内存空间中。
//	std::cout << "对象中的数据成员：" << &(base.m_Value) << std::endl;
//
//	//虚表指针：存储于对象的内存空间中。
//	std::cout << "虚表指针：" << (void*)(&base) << std::endl;
//
//	//虚函数表：存储于已初始化的数据段中的初始化只读区中。
//	std::cout << "虚函数表：" << (void*)(*(void**)(&base)) << std::endl;
//
//	//虚函数：存储于代码段中。
//	std::cout << "虚函数：" << *(void**)(*(void**)(&base)) << std::endl;
//
//	return 0;
//}

/**
	单继承和多继承关系的虚函数表
		1.单继承关系的虚函数表
			a.通过虚表指针可以找到虚函数表，并且打印虚函数表中的虚函数地址，而虚表指针通常存储于对象内存中的最开始的位置。
			b.基类的虚函数表指针和派生类的虚函数表指针不指向同一个虚函数表，它们指向的虚函数表是不同的。
			c.由同一个类创建的不同对象，它们的虚表指针指向同一个虚函数表。
			d.单继承关系下的虚函数表，对于派生类而言，若派生类中没有覆盖基类的虚函数，则派生类的虚函数表中的对应的虚函数地址与基类的虚函数表中对应的虚函数地址相同，否则不同。
			e.派生类自身的虚函数也会被添加到派生类的虚函数表中，当只有一张虚函数表时，它们会被添加到同一张表中。
		2.多继承关系的虚函数表
			a.当一个类继承多个基类时，若这些基类都有虚函数，则每个基类都会有自己的虚函数表，则派生类就会有同样数量的虚表指针，每个虚表指针指向不同的虚函数表。
			b.当派生类对继承自基类的虚函数进行覆盖时，若有不同基类有同一个虚函数，则派生类对此虚函数的覆盖会涉及到所有相关的虚函数表，并且最终都会被覆盖成派生类对应的虚函数。(拓展：涉及虚拟"thunk"和非虚拟"thunk")
			c.派生类自身的虚函数会被添加到首张虚函数表中。
			d.多继承的最终派生类若不覆盖原有的虚函数，并且在调用分别继承自多个直接基类的同一个虚函数时，编译器将无法确定调用哪个函数，此时编译器会报错。
			e.根据继承的顺序，对象模型可能会发生改变。
		3.菱形继承及菱形虚拟继承下的虚函数表(拓展)
			a.菱形继承行为大致与多继承相同，而菱形虚拟继承行为也同样大致相同，但对象模型视平台和编译器可能会有所不同。
			b.菱形虚拟继承时，可能会出现多个最终覆盖函数，导致编译器会报错，故需要覆盖原有虚函数成为唯一的最终覆盖函数。
*/

////单继承和多继承关系的虚函数表示例一：单继承关系的虚函数表。
//typedef void(* VFPtr)();
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Base::Func1()";
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "Base::Func2()";
//	}
//
//private:
//	int m_Value{};
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Derive::Func1()";
//	}
//
//	virtual void Func3()
//	{
//		std::cout << "Derive::Func3()";
//	}
//
//	void Func4()
//	{
//		std::cout << "Derive::Func4()";
//	}
//
//private:
//	int m_Value{};
//};
//
//void Print_VFTable(const std::string& class_name, void* subobject_ptr, size_t size)
//{
//	auto vftable = (VFPtr*)(*(void**)subobject_ptr);//通过强制类型转换再解引用，可以得到虚函数表的地址，即虚表指针的值。
//	std::printf("vtavle for '%s' @ 0x%.p (subobject @ 0x%.p):\n", class_name.c_str(), vftable, subobject_ptr);
//	for (size_t i = 0; i < size; ++i)
//	{
//		std::cout << "[" << i << "]: " << (void*)vftable[i] << " <";
//		vftable[i]();
//		std::cout << ">\n";
//	}
//	std::cout << std::endl;
//}
//
//int main()
//{
//	Base base;
//	Derive derive1;
//	Derive derive2;
//
//	//打印虚函数表
//	Print_VFTable("Base", &base, 2);
//	Print_VFTable("Derive1", &derive1, 3);
//	Print_VFTable("Derive2", &derive2, 3);
//
//	return 0;
//}

////单继承和多继承关系的虚函数表示例二：多继承关系的虚函数表。
//typedef void(* VFPtr)();
//
//class Base1
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Base1::Func1()";
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "Base1::Func2()";
//	}
//
//private:
//	int b1;
//};
//
//class Base2
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Base2::Func1()";
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "Base2::Func2()";
//	}
//
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "Derive::Func1()";
//	}
//
//	virtual void Func3()
//	{
//		std::cout << "Derive::Func3()";
//	}
//
//private:
//	int d1;
//};
//
//void Print_VFTable(const std::string& class_name, void* subobject_ptr, size_t size)
//{
//	auto vftable = (VFPtr*)(*(void**)subobject_ptr);
//	std::printf("vtavle for '%s' @ 0x%.p (subobject @ 0x%.p):\n", class_name.c_str(), vftable, subobject_ptr);
//	for (size_t i = 0; i < size; ++i)
//	{
//		std::cout << "[" << i << "]: " << (void*)vftable[i] << " <";
//		vftable[i]();
//		std::cout << ">\n";
//	}
//	std::cout << std::endl;
//}
//
//int main()
//{
//	Base1 base1;
//	Base2 base2;
//
//	Print_VFTable("Base1", &base1, 2);
//	Print_VFTable("Base2", &base2, 2);
//
//	Derive derive;
//
//	Print_VFTable("Derive as Base1", &derive, 3);//第一张虚函数表，可以发现"Derive::Func3()"也在其中。
//
//	Base2* ptr = &derive;
//
//	Print_VFTable("Derive as Base2", ptr, 2);//第二张虚函数表。
//
//	return 0;
//}

////单继承和多继承关系的虚函数表示例三：菱形继承关系的虚函数表。(结合GDB的"info vtbl"命令观察)
//class A
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "A::Func1()";
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "B::Func1()";
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "B::Func2()";
//	}
//};
//
//class C : public A
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "C::Func1()";
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "C::Func2()";
//	}
//};
//
//class D : public B, public C
//{
//public:
//	virtual void Func1()
//	{
//		std::cout << "D::Func1()";
//	}
//
//	virtual void Func3()
//	{
//		std::cout << "D::Func3()";
//	}
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	d.Func1();//若将"D"类中的"Func1"函数注释，则会出现二义性错误。
//	return 0;
//}

////单继承和多继承关系的虚函数表示例四：菱形虚拟继承关系的虚函数表。(结合GDB的"info vtbl"命令观察)
//class A
//{
//	virtual void Func1()
//	{
//		std::cout << "A::Func1()";
//	}
//};
//
//class B : virtual public A
//{
//	virtual void Func1()
//	{
//		std::cout << "B::Func1()";
//	}
//
//	virtual void Func2()
//	{
//		std::cout << "B::Func2()";
//	}
//};
//
//class C : virtual public A
//{
//	virtual void Func1()
//	{
//		std::cout << "C::Func1()";
//	}
//
//	virtual void Func3()
//	{
//		std::cout << "C::Func3()";
//	}
//};
//
//class D : public B, public C
//{
//	virtual void Func1()//若将"D"类中的"Func1"函数注释，则会出现多个最终覆盖函数，导致程序非良构。
//	{
//		std::cout << "D::Func1()";
//	}
//
//	virtual void Func4()
//	{
//		std::cout << "D::Func4()";
//	}
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	return 0;
//}