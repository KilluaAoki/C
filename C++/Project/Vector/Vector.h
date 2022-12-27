#pragma once

#include <iostream>
#include <cassert>

namespace Aoki
{
	template<typename T>
	class Vector
	{
		typedef Vector<T> this_type;

	public:
		//配套类型
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef std::size_t size_type;

	public:
		//构造函数和析构函数
		Vector();

		Vector(int count, const value_type& value);

		Vector(size_type count, const value_type& value);

		Vector(const this_type& other);

		template<typename InputIterator>
		Vector(InputIterator first, InputIterator last);

		~Vector();

		//重载赋值运算符
		this_type& operator=(const this_type& other);

		//赋值操作
		void assign(size_type count, const value_type& value);

		template<typename InputIterator>
		void assign(InputIterator first, InputIterator last);

		//元素访问
		reference operator[](size_type pos);

		const_reference operator[](size_type pos) const;

		reference at(size_type pos);

		const_reference at(size_type pos) const;

		reference front();

		const_reference front() const;

		reference back();

		const_reference back() const;

		pointer data();

		const_pointer data() const;

		//迭代器
		iterator begin();

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;

		//容量
		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		void reserve(size_type new_cap);

		size_type capacity() const;

		void shrink_to_fit();

		//修改器
		void clear();

		iterator insert(const_iterator pos, const value_type& value);

		iterator insert(const_iterator pos, int count, const value_type& value);

		iterator insert(const_iterator pos, size_type count, const value_type& value);

		template<typename InputIterator>
		iterator insert(const_iterator pos, InputIterator first, InputIterator last);

		iterator erase(const_iterator pos);

		iterator erase(const_iterator first, const_iterator last);

		void push_back(const value_type& value);

		void pop_back();

		void resize(size_type count, const value_type& value);

		void swap(this_type& other);

	private:
		//帮手函数
		/**
		 * @brief destruct
		 * @tparam ForwardIterator: 迭代器类型。
		 * @details 对一系列对象调用析构函数，即释放 [first, last) 区间内的对象。
		 * @param first: 迭代器，指向第一个元素。
		 * @param last: 迭代器，指向最后一个元素的下一个位置。
		 * @return void: 无返回值。
		 */
		template<typename ForwardIterator>
		void destruct(ForwardIterator first, ForwardIterator last);

	private:
		//成员变量
		T* pBegin_;
		T* pEnd_;
		T* pCapacity_;
	};

	//构造函数和析构函数
	template<typename T>
	Vector<T>::Vector() : pBegin_(nullptr), pEnd_(nullptr), pCapacity_(nullptr)
	{
	}

	template<typename T>
	Vector<T>::Vector(int count, const value_type& value)
	{
		pBegin_ = new T[count];
		pCapacity_ = pEnd_ = pBegin_ + count;
		for (size_type i = 0; i < count; ++i)
		{
			pBegin_[i] = value;
		}
	}

	template<typename T>
	Vector<T>::Vector(size_type count, const value_type& value)
	{
		pBegin_ = new T[count];
		pCapacity_ = pEnd_ = pBegin_ + count;
		for (size_type i = 0; i < count; ++i)
		{
			pBegin_[i] = value;
		}
	}

	template<typename T>
	Vector<T>::Vector(const this_type& other) : pBegin_(nullptr), pEnd_(nullptr), pCapacity_(nullptr)
	{
		this_type temp(other.begin(), other.end());
		swap(temp);
	}

	template<typename T>
	template<typename InputIterator>
	Vector<T>::Vector(InputIterator first, InputIterator last)
	{
		auto count = (size_type)(last - first);
		pBegin_ = new T[count];
		pCapacity_ = pEnd_ = pBegin_ + count;
		for (size_type i = 0; i < count; ++i)
		{
			pBegin_[i] = *first++;
		}
	}

	template<typename T>
	Vector<T>::~Vector()
	{
		destruct(pBegin_, pEnd_);
		delete[] pBegin_;
		pBegin_ = pEnd_ = pCapacity_ = nullptr;
	}

	//重载赋值运算符
	template<typename T>
	typename Vector<T>::this_type& Vector<T>::operator=(const this_type& other)
	{
		if (this != &other)
		{
			this_type temp(other.pBegin_, other.pEnd_);
			swap(temp);
		}
		return *this;
	}

	//赋值操作
	template<typename T>
	void Vector<T>::assign(size_type count, const value_type& value)
	{
		this_type temp(count, value);
		swap(temp);
	}

	template<typename T>
	template<typename InputIterator>
	void Vector<T>::assign(InputIterator first, InputIterator last)
	{
		this_type temp(first, last);
		swap(temp);
	}

	//元素访问
	template<typename T>
	typename Vector<T>::reference Vector<T>::operator[](size_type pos)
	{
		return *(pBegin_ + pos);
	}

	template<typename T>
	typename Vector<T>::const_reference Vector<T>::operator[](size_type pos) const
	{
		return *(pBegin_ + pos);
	}

	template<typename T>
	typename Vector<T>::reference Vector<T>::at(size_type pos)
	{
		assert(pos < (size_type)(pEnd_ - pBegin_));
		return *(pBegin_ + pos);
	}

	template<typename T>
	typename Vector<T>::const_reference Vector<T>::at(size_type pos) const
	{
		assert(pos < (size_type)(pEnd_ - pBegin_));
		return *(pBegin_ + pos);
	}

	template<typename T>
	typename Vector<T>::reference Vector<T>::front()
	{
		return *pBegin_;
	}

	template<typename T>
	typename Vector<T>::const_reference Vector<T>::front() const
	{
		return *pBegin_;
	}

	template<typename T>
	typename Vector<T>::reference Vector<T>::back()
	{
		return *(pEnd_ - 1);
	}

	template<typename T>
	typename Vector<T>::const_reference Vector<T>::back() const
	{
		return *(pEnd_ - 1);
	}

	template<typename T>
	typename Vector<T>::pointer Vector<T>::data()
	{
		return pBegin_;
	}

	template<typename T>
	typename Vector<T>::const_pointer Vector<T>::data() const
	{
		return pBegin_;
	}

	//迭代器
	template<typename T>
	typename Vector<T>::iterator Vector<T>::begin()
	{
		return pBegin_;
	}

	template<typename T>
	typename Vector<T>::const_iterator Vector<T>::begin() const
	{
		return pBegin_;
	}

	template<typename T>
	typename Vector<T>::iterator Vector<T>::end()
	{
		return pEnd_;
	}

	template<typename T>
	typename Vector<T>::const_iterator Vector<T>::end() const
	{
		return pEnd_;
	}

	//容量
	template<typename T>
	bool Vector<T>::empty() const
	{
		return (pBegin_ == pEnd_);
	}

	template<typename T>
	typename Vector<T>::size_type Vector<T>::size() const
	{
		return (size_type)(pEnd_ - pBegin_);
	}

	template<typename T>
	typename Vector<T>::size_type Vector<T>::max_size() const
	{
		return ((size_type)(-1) / sizeof(value_type) / (size_type)(2));
	}

	template<typename T>
	void Vector<T>::reserve(size_type new_cap)
	{
		if (new_cap > (size_type)(pCapacity_ - pBegin_))
		{
			auto pNewBegin = new T[new_cap];
			auto count = (size_type)(pEnd_ - pBegin_);
			for (size_type i = 0; i < count; ++i)
			{
				pNewBegin[i] = pBegin_[i];
			}
			destruct(pBegin_, pEnd_);
			delete[] pBegin_;
			pBegin_ = pNewBegin;
			pEnd_ = pBegin_ + count;
			pCapacity_ = pBegin_ + new_cap;
		}
	}

	template<typename T>
	typename Vector<T>::size_type Vector<T>::capacity() const
	{
		return (size_type)(pCapacity_ - pBegin_);
	}

	template<typename T>
	void Vector<T>::shrink_to_fit()
	{
		this_type temp(begin(), end());
		swap(temp);
	}

	//修改器
	template<typename T>
	void Vector<T>::clear()
	{
		destruct(pBegin_, pEnd_);
		pEnd_ = pBegin_;
	}

	template<typename T>
	typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, const value_type& value)
	{
		assert(pos >= pBegin_ && pos <= pEnd_);
		auto destPosition = const_cast<value_type*>(pos);
		const ptrdiff_t n = destPosition - pBegin_;
		if (pEnd_ == pCapacity_)
		{
			size_type newCapacity = capacity() == 0 ? 4 : capacity() * 2;
			reserve(newCapacity);
			destPosition = pBegin_ + n;
		}
		for (auto p = pEnd_; p != destPosition; --p)
		{
			*p = *(p - 1);
		}
		*destPosition = value;
		++pEnd_;
		return pBegin_ + n;
	}

	template<typename T>
	typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, int count, const value_type& value)
	{
		assert(pos >= pBegin_ && pos <= pEnd_);
		auto destPosition = const_cast<value_type*>(pos);
		const ptrdiff_t n = destPosition - pBegin_;
		if (size() + count > capacity())
		{
			size_type newCapacity = capacity() == 0 ? 4 : capacity() * 2;
			while (newCapacity < (size_type)(pEnd_ - pBegin_) + count)
			{
				newCapacity *= 2;
			}
			reserve(newCapacity);
			destPosition = pBegin_ + n;
		}
		if (count > 0)
		{
			for (auto p = pEnd_; p != destPosition; --p)
			{
				*(p + count - 1) = *(p - 1);
			}
			for (auto p = destPosition; p != destPosition + count; ++p)
			{
				*p = value;
			}
			pEnd_ += count;
		}
		return pBegin_ + n;
	}

	template<typename T>
	typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, size_type count, const value_type& value)
	{
		assert(pos >= pBegin_ && pos <= pEnd_);
		auto destPosition = const_cast<value_type*>(pos);
		const ptrdiff_t n = destPosition - pBegin_;
		if (size() + count > capacity())
		{
			size_type newCapacity = capacity() == 0 ? 4 : capacity() * 2;
			while (newCapacity < (size_type)(pEnd_ - pBegin_) + count)
			{
				newCapacity *= 2;
			}
			reserve(newCapacity);
			destPosition = pBegin_ + n;
		}
		if (count > 0)
		{
			for (auto p = pEnd_; p != destPosition; --p)
			{
				*(p + count - 1) = *(p - 1);
			}
			for (auto p = destPosition; p != destPosition + count; ++p)
			{
				*p = value;
			}
			pEnd_ += count;
		}
		return pBegin_ + n;
	}

	template<typename T>
	template<typename InputIterator>
	typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, InputIterator first, InputIterator last)
	{
		auto destPosition = const_cast<value_type*>(pos);
		const ptrdiff_t n = destPosition - pBegin_;
		if (first != last)
		{
			const auto count = (size_type)(last - first);
			if (size() + count > capacity())
			{
				size_type newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				while (newCapacity < (size_type)(pEnd_ - pBegin_) + count)
				{
					newCapacity *= 2;
				}
				reserve(newCapacity);
				destPosition = pBegin_ + n;
			}
			for (auto p = pEnd_; p != destPosition; --p)
			{
				*(p + count - 1) = *(p - 1);
			}
			for (auto p = destPosition; p != destPosition + count; ++p)
			{
				*p = *first++;
			}
			pEnd_ += count;
		}
		return pBegin_ + n;
	}

	template<typename T>
	typename Vector<T>::iterator Vector<T>::erase(const_iterator pos)
	{
		assert(pos >= pBegin_ && pos < pEnd_);
		auto destPosition = const_cast<value_type*>(pos);
		if (destPosition + 1 < pEnd_)
		{
			for (auto p = destPosition; p != pEnd_ - 1; ++p)
			{
				*p = *(p + 1);
			}
		}
		--pEnd_;
		pEnd_->~value_type();
		return destPosition;
	}

	template<typename T>
	typename Vector<T>::iterator Vector<T>::erase(const_iterator first, const_iterator last)
	{
		assert(first >= pBegin_ && first <= pEnd_ && last >= pBegin_ && last <= pEnd_ && first <= last);
		auto destPosition = const_cast<value_type*>(first);
		if (destPosition != last)
		{
			auto n = (size_type)(last - destPosition);
			for (auto p = destPosition; p != pEnd_ - n; ++p)
			{
				*p = *(p + n);
			}
			destruct(pEnd_ - n, pEnd_);
			pEnd_ -= n;
		}
		return destPosition;
	}

	template<typename T>
	void Vector<T>::push_back(const value_type& value)
	{
		insert(pEnd_, value);
	}

	template<typename T>
	void Vector<T>::pop_back()
	{
		assert(pEnd_ > pBegin_);
		--pEnd_;
		pEnd_->~value_type();
	}

	template<typename T>
	void Vector<T>::resize(size_type count, const value_type& value)
	{
		if (count > (size_type)(pEnd_ - pBegin_))
		{
			insert(pEnd_, count - (size_type)(pEnd_ - pBegin_), value);
		}
		else
		{
			destruct(pBegin_ + count, pEnd_);
			pEnd_ = pBegin_ + count;
		}
	}

	template<typename T>
	void Vector<T>::swap(this_type& other)
	{
		std::swap(pBegin_, other.pBegin_);
		std::swap(pEnd_, other.pEnd_);
		std::swap(pCapacity_, other.pCapacity_);
	}

	//帮手函数
	template<typename T>
	template<typename ForwardIterator>
	void Vector<T>::destruct(ForwardIterator first, ForwardIterator last)
	{
		for (; first != last; ++first)
		{
			(*first).~value_type();
		}
	}

	//非成员函数
	/**
	 * @brief equal
	 * @tparam InputIterator1: 迭代器类型。
	 * @tparam InputIterator2: 迭代器类型。
	 * @details 判断两个迭代器范围内的元素是否相等，即 [first1, last1) 与 [first2, first2 + (last1 - first1)) 是否相等。
	 * @details 如果对于范围 [first1, last1) 中的每个迭代器 i 都满足以下相应条件，则为真，否则为假：
	 * @details *i == *(first2 + (i - first1))。
	 * @return
	 */
	template<typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		{
			for (; first1 != last1; ++first1, ++first2)
			{
				if (*first1 != *first2)
					return false;
			}
			return true;
		}
	}

	template<typename T>
	bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return ((lhs.size() == rhs.size()) && equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<typename T>
	bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return ((lhs.size() != rhs.size()) || !equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<typename T>
	bool operator<(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		auto first1 = lhs.begin();
		auto last1 = lhs.end();
		auto first2 = rhs.begin();
		auto last2 = rhs.end();
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (*first1 < *first2)
			{
				return true;
			}
			if (*first2 < *first1)
			{
				return false;
			}
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<typename T>
	bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename T>
	bool operator>(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return rhs < lhs;
	}

	template<typename T>
	bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename T>
	void swap(Vector<T>& lhs, Vector<T>& rhs)
	{
		lhs.swap(rhs);
	}
}