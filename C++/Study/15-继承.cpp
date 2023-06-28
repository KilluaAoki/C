#include <iostream>
#include <string>

/*
	继承
		1.继承的概念及定义
		2.基类和派生类对象赋值转换
		3.继承中的作用域
		4.派生类的默认成员函数
		5.继承与友元
		6.继承与静态成员
		7.菱形继承及菱形虚拟继承
*/

/**
	继承的概念及定义
		1.继承的概念
			a.在面向对象编程中，继承是将已有类的所有属性和行为引入到新的类中，并且可以扩展新类中的属性和行为，属于类层次的代码重用机制。
			b.在继承中，被继承的类称为父类或基类，新创建的类称为子类或派生类，它们体现了继承层级结构。
		2.继承的定义：C++中，任何类类型(无论是以类关键词"class"还是"struct"声明)均可被声明为派生于一个或多个基类，各基类也可以派生自其自身的基类，组成继承层级结构。
			a.定义具名类的语法格式为：类关键词 属性(可选) 类头名 final(可选) 基类子句(可选) { 成员说明 }。
				a'.类关键词："class"、"struct"和"union"之一，除了默认成员访问和默认基类访问之外，关键词"class"和"struct"是等同的，关键词"union"表示声明引入一个联合体类型(联合体不能有基类且不能用作基类)。
				b'.属性(可选)：为类型、对象、代码等引入由实现定义的属性，属于C++11起支持的新特性。
				c'.类头名：所定义的类的名字，可以有限定(即带上作用域解析运算符)。
				d'."final"(可选)：出现时则表示该类不能被继承，属于C++11起支持的新特性。
				e'.基类子句(可选)：一个或多个基类以及各自所用的继承模型的列表。
				f'.成员说明：访问说明符、成员对象及成员函数的声明和定义的列表。
			b.定义无名类的语法格式为：类关键词 属性(可选) 基类子句 { 成员说明 }。
			c.基类的列表在类声明语法的基类子句中提供，而"基类子句"是由字符":"后随一或多个"基类说明符"的逗号分隔列表组成。
			d.常见的"基类说明符"的语法格式为：属性(可选) 访问说明符 类。(此处的语法代表指定非虚且具有给定成员访问性的继承关系)
				a'.访问说明符："public"、"protected"或"private"之一，会影响派生类对基类成员的访问权限，可以省略，省略时代表对以类关键词"struct"声明的类默认为"public"或者对以类关键词"class"声明的类为"private"(即具有默认成员访问性的继承关系)。
				b'.类：即指定基类的名字，在此处列出的所指代的类是直接基类，而直接基类的基类则是间接基类，同一类不能被多次指定为直接基类(即一个类不能在同一个继承类中作为直接基类出现多次)，但同一类可以既是直接又是间接基类。
			e.公开继承、受保护继承和私有继承
				a'.公开继承：当类使用"public"成员访问说明符从基类派生时，基类的所有公开成员可作为派生类的公开成员访问，基类的所有受保护成员可作为派生类的受保护成员访问(基类的私有成员始终不可访问(被隐藏)，除非设为友元)。
				b'.受保护继承：当类使用"protected"成员访问说明符从基类派生时，基类的所有公开和受保护成员可作为派生类的受保护成员访问(基类的私有成员始终不可访问(被隐藏)，除非设为友元)。
				c'.私有继承：当类使用"private"成员访问说明符从基类派生时，基类的所有公开和受保护成员可作为派生类的私有成员访问(基类的私有成员始终不可访问(被隐藏)，除非设为友元)。
*/

////继承的概念及定义示例一：继承的定义基本语法。
//class Person
//{
//public:
//	Person() : m_name("Default"), m_age(0)
//	{
//	}
//
//	Person(const std::string& name, size_t age) : m_name(name), m_age(age)
//	{
//	}
//
//	void Show() const
//	{
//		std::cout << "Person::Show()：" << std::endl;
//		std::cout << "	m_name = " << m_name << std::endl;
//		std::cout << "	m_age = " << m_age << std::endl;
//	}
//
//protected:
//	std::string m_name;
//	size_t m_age;
//};
//
//class Student : public Person//基类子句，指定"Student"类的直接基类为"Person"类，即"Student"类为"Person"基类的派生类。
//{
//public:
//	Student() : m_score(0)
//	{
//	}
//
//	Student(const std::string& name, size_t age, size_t score) : Person(name, age), m_score(score)
//	{
//	}
//
//private:
//	size_t m_score;
//};
//
//int main()
//{
//	Person p1("Aoki", 20);
//	p1.Show();
//
//	Student s1;//此处的"Student"类继承了"Person"类的所有成员。
//	s1.Show();//可使用"Student"类的成员函数"Show"函数，其继承自"Person"类。
//
//	Student s2("Aoki", 20, 100);
//	s2.Show();
//
//	return 0;
//}

////继承的概念及定义示例二：公有继承。
//class Person
//{
//public:
//	Person() : m_name("Default"), m_age(0), m_id(0)
//	{
//	}
//
//	Person(const std::string& name, size_t age, size_t id) : m_name(name), m_age(age), m_id(id)
//	{
//	}
//
//	void Show() const
//	{
//		std::cout << "Person::Show()：" << std::endl;
//		std::cout << "	m_name = " << m_name << std::endl;
//		std::cout << "	m_age = " << m_age << std::endl;
//		std::cout << "	m_id = " << m_id << std::endl;
//	}
//
//public:
//	std::string m_name;
//
//protected:
//	size_t m_age;
//
//private:
//	size_t m_id;
//};
//
//class Student : public Person//公有继承，基类的所有公开成员可作为派生类的公开成员访问，基类的所有受保护成员可作为派生类的受保护成员访问，基类的所有私有成员始终不可访问(除非设为友元)。
//{
//public:
//	Student() : m_score(0)
//	{
//	}
//
//	Student(const std::string& name, size_t age, size_t id, size_t score) : Person(name, age, id), m_score(score)
//	{
//	}
//
//	void Print() const
//	{
//		std::cout << "Student::Print()：" << std::endl;
//		std::cout << "	m_name = " << m_name << std::endl;//可以访问基类的公有成员。
//		std::cout << "	m_age = " << m_age << std::endl;//可以访问基类的受保护成员。
//		//std::cout << "	m_id = " << m_id << std::endl;//错误："m_id"是"Person"的私有成员，"Student"类不能访问。
//		std::cout << "	m_score = " << m_score << std::endl;
//	}
//
//private:
//	size_t m_score;
//};
//
//int main()
//{
//	Person p1("Aoki", 20, 1);
//	p1.Show();
//
//	Student s1;
//	s1.Show();
//	s1.Print();
//
//	Student s2("Aoki", 20, 1, 100);
//	s2.Show();
//	s2.Print();
//
//	return 0;
//}

////继承的概念及定义示例三：受保护继承。
//class Person
//{
//public:
//	Person() : m_name("Default"), m_age(0), m_id(0)
//	{
//	}
//
//	Person(const std::string& name, size_t age, size_t id) : m_name(name), m_age(age), m_id(id)
//	{
//	}
//
//	void Show() const
//	{
//		std::cout << "Person::Show()：" << std::endl;
//		std::cout << "	m_name = " << m_name << std::endl;
//		std::cout << "	m_age = " << m_age << std::endl;
//		std::cout << "	m_id = " << m_id << std::endl;
//	}
//
//public:
//	std::string m_name;
//
//protected:
//	size_t m_age;
//
//private:
//	size_t m_id;
//};
//
//class Student : protected Person//保护继承，基类的所有公开和受保护成员可作为派生类的受保护成员访问，基类的所有私有成员始终不可访问(除非设为友元)。
//{
//public:
//	Student() : m_score(0)
//	{
//	}
//
//	Student(const std::string& name, size_t age, size_t id, size_t score) : Person(name, age, id), m_score(score)
//	{
//	}
//
//	void Print() const
//	{
//		std::cout << "Student::Print()：" << std::endl;
//		std::cout << "	m_name = " << m_name << std::endl;//可以访问基类的公有成员。
//		std::cout << "	m_age = " << m_age << std::endl;//可以访问基类的受保护成员。
//		//std::cout << "	m_id = " << m_id << std::endl;//错误："m_id"是"Person"的私有成员，"Student"类不能访问。
//		std::cout << "	m_score = " << m_score << std::endl;
//	}
//
//private:
//	size_t m_score;
//};
//
//int main()
//{
//	Person p1("Aoki", 20, 1);
//	p1.Show();//此处可正常访问"Person"类的公有成员"Show"函数。
//
//	Student s1;
//	//s1.Show();//"Person"类的公有成员"Show"函数在"Student"类中是受保护的，不能在类外被访问。
//	s1.Print();
//
//	return 0;
//}

////继承的概念及定义示例四：私有继承。
//class Base
//{
//public:
//	void foo()
//	{
//		std::cout << "Base::foo()" << std::endl;
//	}
//};
//
//class Derived : private Base
//{
//public:
//	void bar()
//	{
//		foo();//合法，"Derived"类可以访问"Base"类的"public"成员。
//		std::cout << "Derived::bar()" << std::endl;
//	}
//};
//
//int main()
//{
//	Derived d;
//	d.bar(); //合法，输出"Base::foo()"和"Derived::bar()"。
//	//d.foo();//不合法，"Base"类的"public"成员"foo"在"Derived"类中是私有的，不能在类外被访问。
//	return 0;
//}

/**
	基类和派生类对象赋值转换
		1.派生类对象可以赋值给基类对象、基类引用和基类指针。
		2.基类对象不能赋值给派生类对象，但基类的指针或者引用可以通过强制类型转换赋值给派生类的指针或者引用(需要确保基类指针或者引用指代的是派生类对象，否则不安全)。
		3.基类和派生类对象的赋值行为也可形象的称之为切割或是切片。
			a.当派生类对象赋值给基类对象时，会将派生类对象中继承自基类的成员实例赋值给基类对象(调用基类的拷贝构造函数或拷贝赋值运算符)，而属于派生类对象自身的成员不受到影响。
			b.当派生类对象赋值给基类引用或是基类指针时，代表着让基类的引用或是基类的指针指代派生类对象，但只可见派生类对象中继承自基类的成员实例的那一部分。
*/

////基类和派生类对象赋值转换示例一：派生类对象赋值给基类对象。
//class Base
//{
//public:
//	int x = 0;
//};
//
//class Derived : public Base
//{
//public:
//	int y = 100;
//};
//
//int main()
//{
//	Base b;
//	Derived d;
//
//	b.x = 1;//修改"b"的成员"x"的值。
//
//	std::cout << "b.x = " << b.x << std::endl;//输出：b.x = 1。
//
//	b = d;//合法，将"Derived"类对象赋值给"Base"类对象，"Derived"类的成员"y"会被忽略。
//
//	std::cout << "b.x = " << b.x << std::endl;//输出：b.x = 0。
//	//std::cout << "b.y = " << b.y << std::endl;//错误，"Base"类没有名为"y"的成员。
//
//	std::cout << "d.x = " << d.x << std::endl;//输出：d.x = 0。
//	std::cout << "d.y = " << d.y << std::endl;//输出：d.y = 100。
//
//	return 0;
//}

////基类和派生类对象赋值转换示例二：多种赋值。
//class Person
//{
//protected :
//	std::string m_name;
//	std::string m_sex;
//	int m_age;
//};
//
//class Student : public Person
//{
//public :
//	int m_No;
//};
//
//int main()
//{
//	Student sobj;
//
//	//派生类对象可以赋值给基类对象、基类引用和基类指针：
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//基类对象不能赋值给派生类对象：
//	//sobj = pobj;
//
//	//基类的指针可以通过强制类型转换赋值给派生类的指针：
//	pp = &sobj;
//	Student* ps1 = (Student*)pp;//这种情况转换是可以的。
//	ps1->m_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp;//这种情况转换时，虽然可以，但是会存在越界访问的问题。
//	ps2->m_No = 10;
//
//	return 0;
//}

/**
	继承中的作用域
		1.在继承体系中基类和派生类都有独立的作用域。
		2.基类和派生类中有同名成员，派生类成员将屏蔽对基类成员的直接访问，这种情况称之为隐藏，也叫重定义。
			a.根据就近原则，若访问同名成员，将优先访问派生类中的同名成员，也可使用作用域解析运算符访问基类中的同名成员。
			b.对于成员函数来说，若派生类中定义了与基类同名的成员函数，则基类中的所有同名成员函数都会被隐藏，即使参数列表不同。
*/

////继承中的作用域示例一：基类和派生类中有同名成员。
//class Base
//{
//public:
//	int m_x = 0;
//};
//
//class Derived : public Base
//{
//public:
//	int m_x = 100;
//};
//
//int main()
//{
//	Derived d;
//
//	std::cout << "d.m_x = " << d.m_x << std::endl;//访问的是派生类中的成员"m_x"，输出：d.m_x = 100。
//
//	d.m_x = 200;//访问的是派生类中的成员"m_x"。
//
//	std::cout << "d.m_x = " << d.m_x << std::endl;//访问的是派生类中的成员"m_x"，输出：d.m_x = 200。
//
//	d.Base::m_x = 300;//合法，访问基类中的成员"m_x"。
//
//	std::cout << "d.m_x = " << d.m_x << std::endl;//访问的是派生类中的成员"m_x"，输出：d.m_x = 200。
//
//	std::cout << "d.Base::m_x = " << d.Base::m_x << std::endl;//访问的是基类中的成员"m_x"，输出：d.Base::m_x = 300。
//
//	return 0;
//}

////继承中的作用域示例二：基类和派生类中有同名成员函数。
//class Base
//{
//public:
//	void Func()
//	{
//		std::cout << "Base::Func()" << std::endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	void Func(int)//不与基类中的同名成员函数构成重载，因其不在同一个作用域中。
//	{
//		std::cout << "Derived::Func()" << std::endl;
//	}
//};
//
//int main()
//{
//	Derived d;
//
//	d.Func(0);//两同名函数构成隐藏，输出：Derived::Func()。
//
//	//d.Func();//因构成了隐藏，导致不能直接访问到"Base::Func"函数，故编译器报错，因函数调用的参数太少。
//
//	d.Base::Func();//输出：Base::Func()。
//
//	return 0;
//}

/**
	派生类的默认成员函数
		1.类的六个默认成员函数分别为：默认构造函数、默认拷贝构造函数、默认移动构造函数(C++11)、默认拷贝赋值运算符、默认移动赋值运算符(C++11)、默认析构函数。
			a.派生类与曾学过的类的默认成员函数的特性类似，但是除派生类自身的内置类型和自定义类型成员外，还包含了继承自基类的成员，故需要研究派生类的默认成员函数对继承自基类成员的特性。
			b.对于派生类继承自基类的成员，它会调用基类的对应成员函数完成对基类成员的初始化、拷贝、赋值、销毁等操作。
		2.继承自基类的派生类，由编译器隐式生成的派生类的默认构造函数将会调用基类的默认构造函数，若基类没有默认构造函数，则需要在派生类的构造函数初始化列表中显式调用基类的构造函数。
			a.派生类对象初始化会先调用基类构造再调用派生类构造。
		3.继承自基类的派生类，派生类的拷贝构造函数需显式调用基类的拷贝构造完成基类的拷贝初始化，若不显示调用则可能会调用基类的默认构造函数，这可能会导致基类的成员变量被复制错误或未被复制。
		4.继承自基类的派生类，派生类的拷贝赋值运算符必须要调用基类的拷贝赋值运算符，以完成对基类成员的赋值。
			a.需要注意基类的拷贝赋值运算符成员函数和派生类的拷贝赋值运算符成员函数构成隐藏，故显式调用基类的拷贝赋值运算符成员函数时，需要加上基类的作用域，否则可能导致栈溢出。
			b.由编译器隐式生成的派生类的拷贝赋值运算符将会调用基类的拷贝赋值运算符，但需要注意深浅拷贝的问题。
		5.派生类的析构函数会在自身被调用完成后，再自动调用基类的析构函数清理基类成员，以确保派生类对象先清理派生类成员再清理基类成员的顺序。
			a.派生类对象析构清理会先调用派生类析构再调用基类析构。
			b.派生类的析构函数和基类的析构函数构成隐藏(由于多态关系需求，所有析构函数都会特殊处理成"destructor"函数名)。
			c.不需要显式调用基类的析构函数，因为派生类的析构函数析构完成后会自动调用基类的析构函数。
*/

////派生类的默认成员函数示例一：派生类的默认构造函数。
//class Base
//{
//public:
//	int x;
//
//	Base()
//	{
//		x = 0;
//		std::cout << "Base default constructor called" << std::endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	int y;
//
//	Derived()//派生类的默认构造函数将会调用基类的默认构造函数，即使派生类的默认构造函数没有显式调用基类的构造函数。
//	{
//		y = 0;
//		std::cout << "Derived default constructor called" << std::endl;
//	}
//};
//
//int main()
//{
//	Derived d;
//	std::cout << "d.x = " << d.x << std::endl;
//	std::cout << "d.y = " << d.y << std::endl;
//	return 0;
//}

////派生类的默认成员函数示例二：显式调用基类的构造函数。
//class Base
//{
//public:
//	Base(int x)
//	{
//		std::cout << "Base constructor called with argument " << x << std::endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	Derived(int x, int y) : Base(x)//由于基类没有默认构造函数，故需要在派生类的构造函数初始化列表中显式调用基类的构造函数，否则编译器报错。
//	{
//		std::cout << "Derived constructor called with arguments " << x << " and " << y << std::endl;
//	}
//};
//
//int main()
//{
//	Derived d(1, 2);//调用派生类的构造函数。
//	return 0;
//}

////派生类的默认成员函数示例三：派生类的拷贝构造函数。
//class Person
//{
//public:
//	Person()//基类的默认构造函数，若派生类的拷贝构造函数没有显式调用基类的拷贝构造函数，则会调用基类的默认构造函数。
//	{
//		std::cout << "Person()" << std::endl;
//	}
//
//	Person(const char* name) : _name(name)
//	{
//		std::cout << "Person(const char* name)" << std::endl;
//	}
//
//	Person(const Person& p) : _name(p._name)
//	{
//		std::cout << "Person(const Person& p)" << std::endl;
//	}
//
//protected:
//	std::string _name;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num) : Person(name), _num(num)
//	{
//		std::cout << "Student(const char* name, int num)" << std::endl;
//	}
//
//	Student(const Student& s) : Person(s), _num(s._num)//注意此处的"Person(s)"，其中蕴含了基类和派生类对象赋值转换的过程，若将其去除，则会调用基类的默认构造函数。
//	{
//		std::cout << "Student(const Student& s)" << std::endl;
//	}
//
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s1("Aoki", 43);
//
//	Student s2(s1);
//
//	Student s3 = s1;
//
//	return 0;
//}

////派生类的默认成员函数示例四：派生类的拷贝赋值运算符。
//class Person
//{
//public:
//	Person(const char* name) : _name(name)
//	{
//		std::cout << "Person(const char* name)" << std::endl;
//	}
//
//	Person(const Person& p) : _name(p._name)
//	{
//		std::cout << "Person(const Person& p)" << std::endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		std::cout << "Person& operator=(const Person& p)" << std::endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//protected:
//	std::string _name;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num) : Person(name), _num(num)
//	{
//		std::cout << "Student(const char* name, int num)" << std::endl;
//	}
//
//	Student(const Student& s) : Person(s), _num(s._num)
//	{
//		std::cout << "Student(const Student& s)" << std::endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		std::cout << "Student& operator=(const Student& s)" << std::endl;
//		if (this != &s)
//		{
//			Person::operator=(s);//显式调用基类的拷贝赋值运算符成员函数。
//			_num = s._num;
//		}
//		return *this;
//	}
//
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s1("A—Boy", 1);
//
//	Student s2("B—Boy", 2);
//
//	s2 = s1;//调用派生类的拷贝赋值运算符成员函数。
//
//	return 0;
//}

////派生类的默认成员函数示例五：派生类的析构函数。
//class Person
//{
//public:
//	Person(const char* name) : _name(name)
//	{
//		std::cout << "Person(const char* name)" << std::endl;
//	}
//
//	~Person()
//	{
//		std::cout << "~Person()" << std::endl;
//		delete[] p;
//	}
//
//protected:
//	std::string _name;
//	int* p = new int[10];
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num) : Person(name), _num(num)
//	{
//		std::cout << "Student(const char* name, int num)" << std::endl;
//	}
//
//	~Student()
//	{
//		std::cout << "~Student()" << std::endl;
//		//Person::~Person();//显式调用基类的析构函数的方式，但派生类析构后会自动调用基类的析构函数，故此处不需要显式调用基类的析构函数，若显式调用，则会调用两次基类的析构函数，可能导致程序崩溃(多次释放)。
//	}
//
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s1("A—Boy", 1);
//
//	std::cout << "-------------------" << std::endl;
//
//	Student s2("B—Boy", 2);
//
//	std::cout << "-------------------" << std::endl;
//
//	return 0;
//}

/**
	继承与友元：友元关系不继承(你朋友的孩子不是你的朋友)。
*/

////继承与友元示例：友元关系不继承。
//class Student;
//
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//
//protected:
//	std::string _name;
//};
//
//class Student : public Person
//{
//protected:
//	int _stuNum;
//};
//
//void Display(const Person& p, const Student& s)
//{
//	std::cout << p._name << std::endl;
//	//std::cout << s._stuNum << std::endl;//错误，友元关系不继承。
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}

/**
	继承与静态成员
		1.若基类定义了"static"静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少类，都只有一个"static"成员实例。
		2.静态数据成员无法通过派生类初始化。
*/

////继承与静态成员示例：唯一的静态成员。
//class Person
//{
//public:
//	static int _count;
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//public:
//	int _stuNum = 0;
//};
//
//int main()
//{
//	Student s1;
//	s1._count = 20;
//
//	Student s2;
//	s2._count = 40;
//
//	std::cout << s1._count << std::endl;
//	std::cout << s2._count << std::endl;
//	std::cout << &s1._count << std::endl;
//	std::cout << &s2._count << std::endl;
//
//	return 0;
//}

/**
	菱形继承及菱形虚拟继承
		1.单继承：一个子类只有一个直接父类时称这个继承关系为单继承。
		2.多继承：一个子类有两个及以上直接父类时称这个继承关系为多继承。
		3.菱形继承：多继承的一种特殊情况，即一个子类有两个直接父类，而这两个直接父类又有一个共同的直接父类。
			a.菱形继承会导致二义性问题以及资源浪费问题。
			b.解决二义性问题的方法：明确指定作用域或者虚继承。
		4.菱形虚拟继承：特殊的继承方式，用于解决多重继承中的二义性问题和重复继承同一个基类时出现的重复成员变量的问题。
			a.虚基类：对于每个指定为"virtual"的不同基类，最终派生对象中仅含有该类型的一个基类子对象，即使该类在继承层级中出现多次也是如此(只要它每次都以"virtual"继承)。
			b.虚拟继承的对象模型
				a'.若当前派生类虚拟继承了虚基类，那么将会改变它的对象模型。
				b'.派生类对象中将包含一个虚基类指针，其指代距离虚基类成员的偏移量(即虚基表)，用于找到虚基类成员。
*/

////菱形继承及菱形虚拟继承示例一：菱形继承的相关问题。
//class Person
//{
//public:
//	std::string name;
//	int age;
//};
//
//class Student : public Person//"Student"类继承了"Person"类。
//{
//public:
//	int studentId;
//};
//
//class Teacher : public Person//"Teacher"类继承了"Person"类。
//{
//public:
//	int teacherId;
//};
//
//class Intern
//		: public Student,
//		  public Teacher//"Intern"类继承了"Student"类和"Teacher"类，而"Student"类和"Teacher"类又继承了"Person"类，故"Intern"类有两份"Person"类的成员。
//{
//public:
//	int internId;
//};
//
//int main()
//{
//	Intern x;
//
//	x.studentId = 101;
//	x.teacherId = 501;
//	x.internId = 999;
//
//	////二义性问题：在"Intern"类中有两份"Person"类的成员，无法明确知道访问的是哪一个。
//	//x.name = "Aoki";//错误：在类型为"Person"的多个基类子对象中找到非静态成员"name"。
//	//x.age = 20;//错误：在类型为"Person"的多个基类子对象中找到非静态成员"age"。
//
//	//解决二义性问题：在"Intern"类中明确指定访问的是哪一个"Person"类的成员，但不能解决资源浪费问题。
//	x.Student::name = "Aoki";
//	x.Teacher::name = "Aoki";
//	x.Student::age = 20;
//	x.Teacher::age = 20;
//
//	return 0;
//}

////菱形继承及菱形虚拟继承示例二：菱形虚拟继承。
//class A
//{
//public:
//	int a = 0;
//};
//
//class B : public virtual A//虚继承，使用关键词"virtual"指明"A"为虚基类。
//{
//};
//
//class C : public virtual A//虚继承，使用关键词"virtual"指明"A"为虚基类。
//{
//};
//
//class D : public B, public C//只会继承一份"A"类的成员。
//{
//};
//
//int main()
//{
//	D object;
//
//	std::cout << object.a << std::endl;//输出：0。
//
//	return 0;
//}

//菱形继承及菱形虚拟继承示例三：探究菱形虚拟继承的对象模型。(结合内存窗口观察(视平台而定))
//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//
//	d._b = 1;
//	d._c = 2;
//	d._d = 3;
//
//	d.B::_a = 4;
//	d.C::_a = 5;
//
//	d._a = 6;
//
//	return 0;
//}