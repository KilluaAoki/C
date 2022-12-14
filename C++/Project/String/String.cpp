#include "String.h"

//构造函数和析构函数
Aoki::String::String() : str_(new char[1]{ '\0' }), size_(0), capacity_(0)
{
}

Aoki::String::String(size_type count, char ch)
{
	assert(count <= max_size());
	str_ = new char[count + 1];
	str_[count] = '\0';
	size_ = capacity_ = count;
	while (count--)
	{
		*(str_ + count) = ch;
	}
}

Aoki::String::String(const String& other, size_type pos, size_type count)
{
	assert(pos <= other.size());
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

Aoki::String::String(const char* s, size_type count)
{
	assert(count <= max_size());
	str_ = new char[count + 1];
	str_[count] = '\0';
	size_ = capacity_ = count;
	while (count--)
	{
		*(str_ + count) = *(s + count);
	}
}

Aoki::String::String(const char* s)
{
	capacity_ = size_ = (size_type)std::strlen(s);
	str_ = new char[capacity_ + 1];
	auto p = str_;
	while ((*p++ = *s++) != '\0');
}

Aoki::String::String(const String& other)
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

Aoki::String::~String()
{
	delete[] str_;
	str_ = nullptr;
	size_ = capacity_ = 0;
}

//拷贝赋值运算符
Aoki::String& Aoki::String::operator=(const String& str)
{
	if (this != &str)
	{
		delete[] str_;
		size_ = str.size_;
		capacity_ = str.capacity_;
		str_ = new char[capacity_ + 1];
		while (size_--)
		{
			*(str_ + size_) = *(str.str_ + size_);
		}
		size_ = str.size_;
		str_[size_] = '\0';
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
	delete[] str_;
	str_ = new char[2]{ ch, '\0' };
	size_ = capacity_ = 1;
	return *this;
}

//赋值操作
Aoki::String& Aoki::String::assign(size_type count, char ch)
{
	assert(count <= max_size());
	delete[] str_;
	str_ = new char[count + 1];
	str_[count] = '\0';
	size_ = capacity_ = count;
	while (count--)
	{
		*(str_ + count) = ch;
	}
	return *this;
}

Aoki::String& Aoki::String::assign(const String& str)
{
	delete[] str_;
	size_ = str.size_;
	capacity_ = str.capacity_;
	str_ = new char[capacity_ + 1];
	while (size_--)
	{
		*(str_ + size_) = *(str.str_ + size_);
	}
	size_ = str.size_;
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::assign(const String& str, size_type pos, size_type count)
{
	assert(pos <= str.size());
	if (count == npos || pos + count > str.size_)
	{
		count = str.size_ - pos;
	}
	delete[] str_;
	str_ = new char[count + 1];
	capacity_ = size_ = count;
	while (count--)
	{
		*(str_ + count) = *(str.str_ + pos + count);
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::assign(const char* s, size_type count)
{
	assert(count <= max_size());
	delete[] str_;
	capacity_ = size_ = count;
	str_ = new char[capacity_ + 1];
	while (count--)
	{
		*(str_ + count) = *(s + count);
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::assign(const char* s)
{
	delete[] str_;
	capacity_ = size_ = (size_type)std::strlen(s);
	str_ = new char[capacity_ + 1];
	auto p = str_;
	while ((*p++ = *s++) != '\0');
	return *this;
}

//元素访问
Aoki::String::reference Aoki::String::operator[](size_type pos)
{
	return *(str_ + pos);
}

Aoki::String::const_reference Aoki::String::operator[](size_type pos) const
{
	return *(str_ + pos);
}

Aoki::String::reference Aoki::String::at(String::size_type pos)
{
	assert(pos < size_);
	return *(str_ + pos);
}

Aoki::String::const_reference Aoki::String::at(String::size_type pos) const
{
	assert(pos < size_);
	return *(str_ + pos);
}

char& Aoki::String::front()
{
	return *str_;
}

const char& Aoki::String::front() const
{
	return *str_;
}

char& Aoki::String::back()
{
	return *(str_ + size_ - 1);
}

const char& Aoki::String::back() const
{
	return *(str_ + size_ - 1);
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
	return ((size_type)-1 - 1) / 2;
}

void Aoki::String::reserve(size_type new_cap)
{
	assert(new_cap <= max_size());
	if (new_cap > capacity_)
	{
		auto tmp = new char[new_cap + 1];
		for (size_type i = 0; i < size_; ++i)
		{
			tmp[i] = str_[i];
		}
		delete[] str_;
		str_ = tmp;
		str_[size_] = '\0';
		capacity_ = new_cap;
	}
}

Aoki::String::size_type Aoki::String::capacity() const
{
	return capacity_;
}

void Aoki::String::shrink_to_fit()
{
	if (size_ < capacity_)
	{
		auto tmp = new char[size_ + 1];
		for (size_type i = 0; i < size_; ++i)
		{
			tmp[i] = str_[i];
		}
		delete[] str_;
		str_ = tmp;
		str_[size_] = '\0';
		capacity_ = size_;
	}
}

//操作
void Aoki::String::clear()
{
	size_ = 0;
	str_[size_] = '\0';
}

Aoki::String& Aoki::String::insert(size_type index, size_type count, char ch)
{
	assert(index <= size_);
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	for (size_type i = size_; i > index; --i)
	{
		str_[i + count - 1] = str_[i - 1];
	}
	size_ += count;
	while (count--)
	{
		str_[index + count] = ch;
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::insert(size_type index, const char* s)
{
	assert(index <= size_);
	auto count = (size_type)std::strlen(s);
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	for (size_type i = size_; i > index; --i)
	{
		str_[i + count - 1] = str_[i - 1];
	}
	size_ += count;
	while (count--)
	{
		str_[index + count] = *(s + count);
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::insert(size_type index, const char* s, size_type count)
{
	assert(index <= size_);
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	for (size_type i = size_; i > index; --i)
	{
		str_[i + count - 1] = str_[i - 1];
	}
	size_ += count;
	while (count--)
	{
		str_[index + count] = *(s + count);
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::insert(size_type index, const String& str)
{
	assert(index <= size_);
	auto count = str.size();
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	for (size_type i = size_; i > index; --i)
	{
		str_[i + count - 1] = str_[i - 1];
	}
	size_ += count;
	while (count--)
	{
		str_[index + count] = str[count];
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::insert(size_type index, const String& str, size_type index_str, size_type count)
{
	assert(index <= size_);
	assert(index_str <= str.size());
	auto subStr = str.substr(index_str, count);
	auto count_ = subStr.size();
	assert(size_ + count_ <= max_size());
	if (size_ + count_ > capacity_)
	{
		reserve(size_ + count_);
	}
	for (size_type i = size_; i > index; --i)
	{
		str_[i + count_ - 1] = str_[i - 1];
	}
	size_ += count_;
	while (count_--)
	{
		str_[index + count_] = subStr[count_];
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String::iterator Aoki::String::insert(const_iterator pos, char ch)
{
	size_type index = pos - begin();
	insert(index, 1, ch);
	return begin() + index;
}

Aoki::String::iterator Aoki::String::insert(const_iterator pos, size_type count, char ch)
{
	size_type index = pos - begin();
	insert(index, count, ch);
	return begin() + index;
}

Aoki::String& Aoki::String::erase(size_type index, size_type count)
{
	assert(index <= size_);
	count = count > size_ - index ? size_ - index : count;
	for (size_type i = index; i < size_ - count; ++i)
	{
		str_[i] = str_[i + count];
	}
	size_ -= count;
	str_[size_] = '\0';
	return *this;
}

Aoki::String::iterator Aoki::String::erase(const_iterator position)
{
	auto index = position - begin();
	erase(index, 1);
	return begin() + index;
}

Aoki::String::iterator Aoki::String::erase(const_iterator first, const_iterator last)
{
	auto index = first - begin();
	auto count = last - first;
	erase(index, count);
	return begin() + index;
}

void Aoki::String::push_back(char ch)
{
	assert(size_ + 1 <= max_size());
	if (size_ == capacity_)
	{
		size_type newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
		auto tmp = new char[newCapacity + 1];
		for (size_type i = 0; i < size_; ++i)
		{
			tmp[i] = str_[i];
		}
		delete[] str_;
		str_ = tmp;
		capacity_ = newCapacity;
	}
	str_[size_] = ch;
	str_[++size_] = '\0';
}

void Aoki::String::pop_back()
{
	str_[--size_] = '\0';
}

Aoki::String& Aoki::String::append(size_type count, char ch)
{
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	while (count--)
	{
		str_[size_++] = ch;
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::append(const String& str)
{
	assert(size_ + str.size_ <= max_size());
	if (size_ + str.size_ > capacity_)
	{
		reserve(size_ + str.size_);
	}
	for (size_type i = 0; i < str.size_; ++i)
	{
		str_[size_++] = str[i];
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::append(const String& str, size_type pos, size_type count)
{
	assert(pos <= str.size_);
	if (count == npos || pos + count > str.size_)
	{
		count = str.size_;
	}
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	while (count--)
	{
		str_[size_++] = str[pos++];
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::append(const char* s, size_type count)
{
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	while (count--)
	{
		str_[size_++] = *s++;
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::append(const char* s)
{
	auto count = (size_type)std::strlen(s);
	assert(size_ + count <= max_size());
	if (size_ + count > capacity_)
	{
		reserve(size_ + count);
	}
	while (count--)
	{
		str_[size_++] = *s++;
	}
	str_[size_] = '\0';
	return *this;
}

Aoki::String& Aoki::String::operator+=(const String& str)
{
	return append(str);
}

Aoki::String& Aoki::String::operator+=(char ch)
{
	return append(1, ch);
}

Aoki::String& Aoki::String::operator+=(const char* s)
{
	return append(s);
}

int Aoki::String::compare(const String& str) const
{
	auto count = size_ < str.size_ ? size_ : str.size_;
	for (size_type i = 0; i < count; ++i)
	{
		if (str_[i] < str.str_[i])
		{
			return -1;
		}
		else if (str_[i] > str.str_[i])
		{
			return 1;
		}
	}
	if (size_ < str.size_)
	{
		return -1;
	}
	else if (size_ > str.size_)
	{
		return 1;
	}
	return 0;
}

int Aoki::String::compare(size_type pos1, size_type count1, const String& str) const
{
	if (count1 > size_ - pos1)
	{
		count1 = size_ - pos1;
	}
	auto count = count1 < str.size_ ? count1 : str.size_;
	for (size_type i = 0; i < count; ++i)
	{
		if (str_[pos1 + i] < str.str_[i])
		{
			return -1;
		}
		else if (str_[pos1 + i] > str.str_[i])
		{
			return 1;
		}
	}
	if (count1 < str.size_)
	{
		return -1;
	}
	else if (count1 > str.size_)
	{
		return 1;
	}
	return 0;
}

int Aoki::String::compare(size_type pos1, size_type count1, const String& str, size_type pos2, size_type count2) const
{
	if (count1 > size_ - pos1)
	{
		count1 = size_ - pos1;
	}
	if (count2 > str.size_ - pos2)
	{
		count2 = str.size_ - pos2;
	}
	auto count = count1 < count2 ? count1 : count2;
	for (size_type i = 0; i < count; ++i)
	{
		if (str_[pos1 + i] < str.str_[pos2 + i])
		{
			return -1;
		}
		else if (str_[pos1 + i] > str.str_[pos2 + i])
		{
			return 1;
		}
	}
	if (count1 < count2)
	{
		return -1;
	}
	else if (count1 > count2)
	{
		return 1;
	}
	return 0;
}

int Aoki::String::compare(const char* s) const
{
	auto sLen = (size_type)std::strlen(s);
	auto count = size_ < sLen ? size_ : sLen;
	for (size_type i = 0; i < count; ++i)
	{
		if (str_[i] < s[i])
		{
			return -1;
		}
		else if (str_[i] > s[i])
		{
			return 1;
		}
	}
	if (size_ < sLen)
	{
		return -1;
	}
	else if (size_ > sLen)
	{
		return 1;
	}
	return 0;
}

int Aoki::String::compare(size_type pos1, size_type count1, const char* s) const
{
	if (count1 > size_ - pos1)
	{
		count1 = size_ - pos1;
	}
	auto sLen = (size_type)std::strlen(s);
	auto count = count1 < sLen ? count1 : sLen;
	for (size_type i = 0; i < count; ++i)
	{
		if (str_[pos1 + i] < s[i])
		{
			return -1;
		}
		else if (str_[pos1 + i] > s[i])
		{
			return 1;
		}
	}
	if (count1 < sLen)
	{
		return -1;
	}
	else if (count1 > sLen)
	{
		return 1;
	}
	return 0;
}

int Aoki::String::compare(size_type pos1, size_type count1, const char* s, size_type count2) const
{
	if (count1 > size_ - pos1)
	{
		count1 = size_ - pos1;
	}
	auto count = count1 < count2 ? count1 : count2;
	for (size_type i = 0; i < count; ++i)
	{
		if (str_[pos1 + i] < s[i])
		{
			return -1;
		}
		else if (str_[pos1 + i] > s[i])
		{
			return 1;
		}
	}
	if (count1 < count2)
	{
		return -1;
	}
	else if (count1 > count2)
	{
		return 1;
	}
	return 0;
}

Aoki::String& Aoki::String::replace(size_type pos, size_type count, const String& str)
{
}

Aoki::String& Aoki::String::replace(const_iterator first, const_iterator last, const String& str)
{
}

Aoki::String& Aoki::String::replace(size_type pos, size_type count, const String& str, size_type pos2, size_type count2)
{
}

Aoki::String& Aoki::String::replace(size_type pos, size_type count, const char* cstr, size_type count2)
{
}

Aoki::String& Aoki::String::replace(const_iterator first, const_iterator last, const char* cstr, size_type count2)
{
}

Aoki::String& Aoki::String::replace(Aoki::String::size_type pos, Aoki::String::size_type count, const char* cstr)
{
}

Aoki::String& Aoki::String::replace(const_iterator first, const_iterator last, const char* cstr)
{
}

Aoki::String& Aoki::String::replace(size_type pos, size_type count, size_type count2, char ch)
{
}

Aoki::String& Aoki::String::replace(const_iterator first, const_iterator last, size_type count2, char ch)
{
}

Aoki::String Aoki::String::substr(size_type pos, size_type count) const
{
	assert(pos <= size_);
	return Aoki::String{ *this, pos, count };
}

Aoki::String::size_type Aoki::String::copy(char* dest, size_type count, size_type pos) const
{
	assert(pos <= size_);
	if (count == npos || pos + count > size_)
	{
		count = size_ - pos;
	}
	for (size_type i = 0; i < count; ++i)
	{
		dest[i] = str_[pos + i];
	}
	return count;
}

void Aoki::String::resize(size_type count)
{
	assert(count <= max_size());
	if (size_ < count)
	{
		auto tmp = new char[count + 1];
		for (size_type i = 0; i < size_; ++i)
		{
			tmp[i] = str_[i];
		}
		delete[] str_;
		str_ = tmp;
		for (size_type i = size_; i <= count; ++i)
		{
			str_[i] = '\0';
		}
		size_ = capacity_ = count;
	}
	else if (size_ > count)
	{
		size_ = count;
		str_[size_] = '\0';
	}
}

void Aoki::String::resize(size_type count, char ch)
{
	assert(count <= max_size());
	if (size_ < count)
	{
		auto tmp = new char[count + 1];
		for (size_type i = 0; i < size_; ++i)
		{
			tmp[i] = str_[i];
		}
		delete[] str_;
		str_ = tmp;
		for (size_type i = size_; i < count; ++i)
		{
			str_[i] = ch;
		}
		str_[count] = '\0';
		size_ = capacity_ = count;
	}
	else if (size_ > count)
	{
		size_ = count;
		str_[size_] = '\0';
	}
}

void Aoki::String::swap(String& other)
{
	auto tmp1 = str_;
	str_ = other.str_;
	other.str_ = tmp1;
	auto tmp2 = size_;
	size_ = other.size_;
	other.size_ = tmp2;
	auto tmp3 = capacity_;
	capacity_ = other.capacity_;
	other.capacity_ = tmp3;
}

//非成员函数
std::ostream& Aoki::operator<<(std::ostream& os, const String& str)
{
	for (Aoki::String::size_type i = 0; i < str.size(); ++i)
	{
		os << str[i];
	}
	return os;
}