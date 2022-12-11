#include "String.h"

//构造函数和析构函数
Aoki::String::String() : str_(new char[1]{ '\0' }), size_(0), capacity_(0)
{
}

Aoki::String::String(const char* str)
{
	capacity_ = size_ = (size_type)std::strlen(str);
	str_ = new char[capacity_ + 1];
	auto p = str_;
	while ((*p++ = *str++) != '\0');
}

Aoki::String::String(const char* str, size_type count)
{
	str_ = new char[count + 1];
	str_[count] = '\0';
	size_ = capacity_ = count;
	while (count--)
	{
		*(str_ + count) = *(str + count);
	}
}

Aoki::String::String(size_type count, char ch)
{
	str_ = new char[count + 1];
	str_[count] = '\0';
	size_ = capacity_ = count;
	while (count--)
	{
		*(str_ + count) = ch;
	}
}

Aoki::String::String(const Aoki::String& other)
{
	str_ = new char[other.capacity_ + 1];
	str_[other.size_] = '\0';
	size_ = other.size_;
	while (size_--)
	{
		*(str_ + size_) = *(other.str_ + size_);
	}
	size_ = other.size_;
	capacity_ = other.capacity_;
}

Aoki::String::String(const Aoki::String& other, size_type pos, size_type count)
{
	if (count == npos || pos + count > other.size_)
	{
		count = other.size_ - pos;
	}
	str_ = new char[count + 1];
	str_[count] = '\0';
	capacity_ = size_ = count;
	while (count--)
	{
		*(str_ + count) = *(other.str_ + pos + count);
	}
}

Aoki::String::~String()
{
	delete[] str_;
	str_ = nullptr;
	size_ = capacity_ = 0;
}

//拷贝赋值运算符
Aoki::String& Aoki::String::operator=(const Aoki::String& str)
{
	if (this != &str)
	{
		delete[] str_;
		str_ = new char[capacity_ + 1];
		str_[size_] = '\0';
		size_ = str.size_;
		while (size_--)
		{
			*(str_ + size_) = *(str.str_ + size_);
		}
		size_ = str.size_;
		capacity_ = str.capacity_;
	}
	return *this;
}

Aoki::String& Aoki::String::operator=(const char* s)
{
	delete[] str_;
	capacity_ = size_ = (size_type)std::strlen(s);
	str_ = new char[capacity_ + 1];
	auto p = str_;
	while ((*p++ = *s++) != '\0');
	return *this;
}

Aoki::String& Aoki::String::operator=(char ch)
{
	clear();
	insert(begin(), ch);
	return *this;
}

//赋值操作
Aoki::String& Aoki::String::assign(size_type count, char ch)
{
}

Aoki::String& Aoki::String::assign(const Aoki::String& str)
{
}

Aoki::String& Aoki::String::assign(const char& str, size_type pos, size_type count)
{
}

Aoki::String& Aoki::String::assign(const char* str, size_type count)
{
}

Aoki::String& Aoki::String::assign(const char* str)
{
}

//元素访问
Aoki::String::reference Aoki::String::operator[](size_type pos)
{
	return *(begin() + pos);
}

Aoki::String::const_reference Aoki::String::operator[](size_type pos) const
{
	return *(begin() + pos);
}

Aoki::String::reference Aoki::String::at(Aoki::String::size_type pos)
{
}

Aoki::String::const_reference Aoki::String::at(Aoki::String::size_type pos) const
{
}

char& Aoki::String::front()
{
}

const char& Aoki::String::front() const
{
}

char& Aoki::String::back()
{
}

const char& Aoki::String::back() const
{
}

const char* Aoki::String::data() const
{
	return str_;
}

const char* Aoki::String::c_str() const
{
	return str_;
}

//迭代器
Aoki::String::iterator Aoki::String::begin()
{
	return str_;
}

Aoki::String::const_iterator Aoki::String::begin() const
{
	return str_;
}

Aoki::String::iterator Aoki::String::end()
{
	return str_ + size_;
}

Aoki::String::const_iterator Aoki::String::end() const
{
	return str_ + size_;
}

//容量
bool Aoki::String::empty() const
{
	return size_ == 0;
}

Aoki::String::size_type Aoki::String::size() const
{
	return size_;
}

Aoki::String::size_type Aoki::String::length() const
{
	return size_;
}

Aoki::String::size_type Aoki::String::max_size() const
{
	return ((size_type)-1 - 1);
}

void Aoki::String::reserve(Aoki::String::size_type new_cap)
{
	if (new_cap > capacity_)
	{
		auto tmp = new char[new_cap + 1];
		for (size_type i = 0; i < size_; ++i)
		{
			tmp[i] = str_[i];
		}
		delete[] str_;
		str_ = tmp;
		str_[new_cap] = '\0';
		capacity_ = new_cap;
	}
}

Aoki::String::size_type Aoki::String::capacity() const
{
	return capacity_;
}

//操作
void Aoki::String::clear()
{
	delete[] str_;
	size_ = 0;
	str_ = new char[capacity_ + 1];
	str_[size_] = '\0';
}

//非成员函数
std::ostream& Aoki::operator<<(std::ostream& os, const String& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		os << str[i];
	}
	return os;
}