#pragma once

#include <iostream>
#include <cstring>          //使用"strlen"函数。
#include <cassert>          //以断言宏检查错误(替代异常)。

namespace Aoki
{
	class String
	{
	public:
		//配套类型
		typedef char& reference;
		typedef const char& const_reference;
		typedef char* iterator;
		typedef const char* const_iterator;
		typedef size_t size_type;

	public:
		//构造函数和析构函数
		String();

		String(size_type count, char ch);

		String(const String& other, size_type pos, size_type count = npos);

		String(const char* s, size_type count);

		String(const char* s);

		String(const String& other);

		~String();

		//拷贝赋值运算符
		String& operator=(const String& str);

		String& operator=(const char* s);

		String& operator=(char ch);

		//赋值操作

		String& assign(size_type count, char ch);

		String& assign(const String& str);

		String& assign(const String& str, size_type pos, size_type count = npos);

		String& assign(const char* s, size_type count);

		String& assign(const char* s);

		//元素访问
		reference operator[](size_type pos);

		const_reference operator[](size_type pos) const;

		reference at(size_type pos);

		const_reference at(size_type pos) const;

		char& front();

		const char& front() const;

		char& back();

		const char& back() const;

		const char* data() const;

		const char* c_str() const;

		//迭代器
		iterator begin();

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;

		//容量
		bool empty() const;

		size_type size() const;

		size_type length() const;

		size_type max_size() const;

		void reserve(size_type new_cap = 0);

		size_type capacity() const;

		void shrink_to_fit();

		//操作
		void clear();

		String& insert(size_type index, size_type count, char ch);

		String& insert(size_type index, const char* s);

		String& insert(size_type index, const char* s, size_type count);

		String& insert(size_type index, const String& str);

		String& insert(size_type index, const String& str, size_type index_str, size_type count = npos);

		iterator insert(const_iterator pos, char ch);

		iterator insert(const_iterator pos, size_type count, char ch);

		String& erase(size_type index = 0, size_type count = npos);

		iterator erase(const_iterator position);

		iterator erase(const_iterator first, const_iterator last);

		void push_back(char ch);

		void pop_back();

		String& append(size_type count, char ch);

		String& append(const String& str);

		String& append(const String& str, size_type pos, size_type count = npos);

		String& append(const char* s, size_type count);

		String& append(const char* s);

		String& operator+=(const String& str);

		String& operator+=(char ch);

		String& operator+=(const char* s);

		int compare(const String& str) const;

		int compare(size_type pos1, size_type count1, const String& str) const;

		int compare(size_type pos1, size_type count1, const String& str, size_type pos2, size_type count2 = npos) const;

		int compare(const char* s) const;

		int compare(size_type pos1, size_type count1, const char* s) const;

		int compare(size_type pos1, size_type count1, const char* s, size_type count2) const;

		String& replace(size_type pos, size_type count, const String& str);

		String& replace(const_iterator first, const_iterator last, const String& str);

		String& replace(size_type pos, size_type count, const String& str, size_type pos2, size_type count2 = npos);

		String& replace(size_type pos, size_type count, const char* cstr, size_type count2);

		String& replace(const_iterator first, const_iterator last, const char* cstr, size_type count2);

		String& replace(size_type pos, size_type count, const char* cstr);

		String& replace(const_iterator first, const_iterator last, const char* cstr);

		String& replace(size_type pos, size_type count, size_type count2, char ch);

		String& replace(const_iterator first, const_iterator last, size_type count2, char ch);

		String substr(size_type pos = 0, size_type count = npos) const;

		size_type copy(char* dest, size_type count, size_type pos = 0) const;

		void resize(size_type count);

		void resize(size_type count, char ch);

		void swap(String& other);

		//查找
		size_type find(const String& str, size_type pos = 0) const;

		size_type find(const char* s, size_type pos, size_type count) const;

		size_type find(const char* s, size_type pos = 0) const;

		size_type find(char ch, size_type pos = 0) const;

		size_type rfind(const String& str, size_type pos = npos) const;

		size_type rfind(const char* s, size_type pos, size_type count) const;

		size_type rfind(const char* s, size_type pos = npos) const;

		size_type rfind(char ch, size_type pos = npos) const;

	private:
		//成员变量
		char* str_;
		size_type size_;
		size_type capacity_;
		static const size_type npos = (size_type)-1;
	};

	//非成员函数
	String& operator+(const String& lhs, const String& rhs);

	String& operator+(const String& lhs, const char* rhs);

	String& operator+(const String& lhs, char rhs);

	String& operator+(const char* lhs, const String& rhs);

	String& operator+(char lhs, const String& rhs);

	bool operator==(const String& lhs, const String& rhs);

	bool operator==(const String& lhs, const char* rhs);

	bool operator==(const char* lhs, const String& rhs);

	bool operator!=(const String& lhs, const String& rhs);

	bool operator!=(const String& lhs, const char* rhs);

	bool operator!=(const char* lhs, const String& rhs);

	bool operator<(const String& lhs, const String& rhs);

	bool operator<(const String& lhs, const char* rhs);

	bool operator<(const char* lhs, const String& rhs);

	bool operator>(const String& lhs, const String& rhs);

	bool operator>(const String& lhs, const char* rhs);

	bool operator>(const char* lhs, const String& rhs);

	bool operator<=(const String& lhs, const String& rhs);

	bool operator<=(const String& lhs, const char* rhs);

	bool operator<=(const char* lhs, const String& rhs);

	bool operator>=(const String& lhs, const String& rhs);

	bool operator>=(const String& lhs, const char* rhs);

	bool operator>=(const char* lhs, const String& rhs);

	void swap(String& lhs, String& rhs);

	std::istream& operator>>(std::istream& is, const String& str);

	std::ostream& operator<<(std::ostream& os, const String& str);

	std::istream& getline(std::istream& input, String& str, char delim);

	std::istream& getline(std::istream& input, String& str);
}