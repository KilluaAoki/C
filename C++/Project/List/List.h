#pragma once

#include <iostream>
#include <type_traits>

namespace Aoki
{
	/**
	 * @brief ListNode Class
	 * @tparam T: 节点中存放数据的类型。
	 * @details 链表节点类。
	 */
	template<typename T>
	struct ListNode
	{
		typedef ListNode<T> this_type;

	public:
		T data_;
		ListNode<T>* pNext_;
		ListNode<T>* pPrev_;

	public:
		ListNode(const T& data = T());

		/**
		 * @brief insert
		 * @param pNode: 将要要插入的节点。
		 * @details 将当前节点( this )插入到链表中的节点 pNode 之前。
		 */
		void insert(this_type* pNode);

		/**
		 * @brief remove
		 * @details 将当前节点( this )从链表中移除。
		 * @note 此函数不会释放此节点的内存。
		 */
		void remove();

		/**
		 * @brief splice
		 * @param first: 将要要插入的节点的起始位置。
		 * @param last: 将要要插入的节点的结束位置(不包括此节点)。
		 * @details 将源链表范围 [first, last) 中所指代的节点剪切(源链表删除，再拼接至当前链表)到当前节点( this )之前。
		 */
		void splice(this_type* first, this_type* last);
	};

	/**
	 * @brief ListIterator Class
	 * @tparam T: 节点中存放数据的类型。
	 * @tparam Pointer: 指针类型。
	 * @tparam Reference: 引用类型。
	 */
	template<typename T, typename Pointer, typename Reference>
	struct ListIterator
	{
		typedef ListIterator<T, Pointer, Reference> this_type;

	public:
		//配套类型
		typedef ListIterator<T, T*, T&> iterator;
		typedef ListIterator<T, const T*, const T&> const_iterator;
		typedef ListNode<T> node_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef std::size_t size_type;

	public:
		//成员变量
		node_type* pNode_;

	public:
		ListIterator();

		ListIterator(const node_type* pNode);

		ListIterator(const iterator& x);

		this_type next() const;

		this_type prev() const;

		reference operator*() const;

		pointer operator->() const;

		this_type& operator++();

		this_type operator++(int);

		this_type& operator--();

		this_type operator--(int);
	};

	template<typename T>
	class List
	{
		typedef List<T> this_type;

	public:
		//配套类型
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef ListIterator<T, T*, T&> iterator;
		typedef ListIterator<T, const T*, const T&> const_iterator;
		typedef std::size_t size_type;
		typedef ListNode<T> node_type;

	public:
		//构造函数和析构函数
		List();

		List(size_type count, const value_type& value);

		template<class InputIterator>
		List(InputIterator first, InputIterator last);

		List(const this_type& other);

		~List();

		//重载赋值运算符
		List& operator=(const this_type& other);

		//赋值操作
		void assign(size_type count, const value_type& value);

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last);

		//元素访问
		reference front();

		const_reference front() const;

		reference back();

		const_reference back() const;

		//迭代器
		iterator begin();

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;

		//容量
		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		//修改器
		void clear();

		iterator insert(const_iterator pos, const value_type& value);

		iterator insert(const_iterator pos, size_type count, const value_type& value);

		template<class InputIterator>
		iterator insert(const_iterator pos, InputIterator first, InputIterator last);

		iterator erase(const_iterator pos);

		iterator erase(const_iterator first, const_iterator last);

		void push_front(const value_type& value);

		void pop_front();

		void push_back(const value_type& value);

		void pop_back();

		void resize(size_type count, const value_type& value);

		void swap(this_type& other);

		//操作
		void merge(this_type& other);

		template<typename Compare>
		void merge(this_type& other, Compare comp);

		void splice(const_iterator pos, this_type& other);

		void splice(const_iterator pos, this_type& other, const_iterator it);

		void splice(const_iterator pos, this_type& other, const_iterator first, const_iterator last);

		size_type remove(const T& value);

		template<typename UnaryPredicate>
		size_type remove_if(UnaryPredicate p);

		void reverse();

		void unique();

		template<class BinaryPredicate>
		void unique(BinaryPredicate p);

		//void sort();

		//template<class Compare>
		//void sort(Compare comp);

	private:
		//帮手函数
		void DoInit();

		void DoInsertValue(node_type* pNode, const value_type& value);

		void DoInsertValues(node_type* pNode, size_type count, const value_type& value);

		template<typename Integer>
		void DoInsert(node_type* pNode, Integer count, Integer value, std::true_type);

		template<typename InputIterator>
		void DoInsert(node_type* pNode, InputIterator first, InputIterator last, std::false_type);

		template<typename InputIterator>
		void DoAssign(InputIterator first, InputIterator last, std::false_type);

		void DoAssignValues(size_type count, const value_type& value);

		template<typename Integer>
		void DoAssign(Integer count, Integer value, std::true_type);

		void DoErase(node_type* pNode);

		void DoClear();

	private:
		//成员变量
		node_type* pHead_;
		size_type size_;
	};

	///////////////////////////////////////////////////////////////////////
	// ListNode Class 实现
	///////////////////////////////////////////////////////////////////////

	template<typename T>
	ListNode<T>::ListNode(const T& data) : pNext_(nullptr), pPrev_(nullptr), data_(data)
	{
	}

	template<typename T>
	void ListNode<T>::insert(this_type* pNode)
	{
		pNext_ = pNode;
		pPrev_ = pNode->pPrev_;
		pNode->pPrev_ = this;
		pPrev_->pNext_ = this;
	}

	template<typename T>
	void ListNode<T>::remove()
	{
		pPrev_->pNext_ = pNext_;
		pNext_->pPrev_ = pPrev_;
	}

	template<typename T>
	void ListNode<T>::splice(this_type* first, this_type* last)
	{
		last->pPrev_->pNext_ = this;
		first->pPrev_->pNext_ = last;
		this->pPrev_->pNext_ = first;
		this_type* const pTemp = this->pPrev_;
		this->pPrev_ = last->pPrev_;
		last->pPrev_ = first->pPrev_;
		first->pPrev_ = pTemp;
	}

	///////////////////////////////////////////////////////////////////////
	// ListIterator Class 实现
	///////////////////////////////////////////////////////////////////////

	template<typename T, typename Pointer, typename Reference>
	ListIterator<T, Pointer, Reference>::ListIterator() : pNode_(nullptr)
	{
	}

	template<typename T, typename Pointer, typename Reference>
	ListIterator<T, Pointer, Reference>::ListIterator(const node_type* pNode) : pNode_(const_cast<node_type*>(pNode))
	{
	}

	template<typename T, typename Pointer, typename Reference>
	ListIterator<T, Pointer, Reference>::ListIterator(const iterator& x) : pNode_(const_cast<node_type*>(x.pNode_))
	{
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::this_type ListIterator<T, Pointer, Reference>::next() const
	{
		return this_type(pNode_->pNext_);
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::this_type ListIterator<T, Pointer, Reference>::prev() const
	{
		return this_type(pNode_->pPrev_);
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::reference ListIterator<T, Pointer, Reference>::operator*() const
	{
		return pNode_->data_;
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::pointer ListIterator<T, Pointer, Reference>::operator->() const
	{
		return &(pNode_->data_);
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::this_type& ListIterator<T, Pointer, Reference>::operator++()
	{
		pNode_ = pNode_->pNext_;
		return *this;
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::this_type ListIterator<T, Pointer, Reference>::operator++(int)
	{
		this_type temp = *this;
		pNode_ = pNode_->pNext_;
		return temp;
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::this_type& ListIterator<T, Pointer, Reference>::operator--()
	{
		pNode_ = pNode_->pPrev_;
		return *this;
	}

	template<typename T, typename Pointer, typename Reference>
	typename ListIterator<T, Pointer, Reference>::this_type ListIterator<T, Pointer, Reference>::operator--(int)
	{
		this_type temp = *this;
		pNode_ = pNode_->pPrev_;
		return temp;
	}

	///////////////////////////////////////////////////////////////////////
	// List Class 实现
	///////////////////////////////////////////////////////////////////////

	//构造函数和析构函数
	template<typename T>
	List<T>::List() : pHead_(new node_type), size_(0)
	{
		DoInit();
	}

	template<typename T>
	List<T>::List(size_type count, const value_type& value) : pHead_(new node_type), size_(0)
	{
		DoInit();
		DoInsertValues(pHead_, count, value);
	}

	template<typename T>
	template<class InputIterator>
	List<T>::List(InputIterator first, InputIterator last) : pHead_(new node_type), size_(0)
	{
		DoInit();
		DoInsert(pHead_, first, last, std::is_integral<InputIterator>());
	}

	template<typename T>
	List<T>::List(const this_type& other) : pHead_(new node_type), size_(0)
	{
		DoInit();
		DoInsert(pHead_, const_iterator(other.pHead_->pNext_), const_iterator(other.pHead_), std::false_type());
	}

	template<typename T>
	List<T>::~List()
	{
		DoClear();
		delete pHead_;
		pHead_ = nullptr;
	}

	//重载赋值运算符
	template<typename T>
	typename List<T>::this_type& List<T>::operator=(const this_type& other)
	{
		if (this != &other)
		{
			DoAssign(const_iterator(other.pHead_->pNext_), const_iterator(other.pHead_), std::false_type());
		}
		return *this;
	}

	//赋值操作
	template<typename T>
	void List<T>::assign(size_type count, const value_type& value)
	{
		DoAssignValues(count, value);
	}

	template<typename T>
	template<class InputIterator>
	void List<T>::assign(InputIterator first, InputIterator last)
	{
		DoAssign(first, last, std::is_integral<InputIterator>());
	}

	//元素访问
	template<typename T>
	typename List<T>::reference List<T>::front()
	{
		return pHead_->pNext_->data_;
	}

	template<typename T>
	typename List<T>::const_reference List<T>::front() const
	{
		return pHead_->pNext_->data_;
	}

	template<typename T>
	typename List<T>::reference List<T>::back()
	{
		return pHead_->pPrev_->data_;
	}

	template<typename T>
	typename List<T>::const_reference List<T>::back() const
	{
		return pHead_->pPrev_->data_;
	}

	//迭代器
	template<typename T>
	typename List<T>::iterator List<T>::begin()
	{
		return iterator(pHead_->pNext_);
	}

	template<typename T>
	typename List<T>::const_iterator List<T>::begin() const
	{
		return const_iterator(pHead_->pNext_);
	}

	template<typename T>
	typename List<T>::iterator List<T>::end()
	{
		return iterator(pHead_);
	}

	template<typename T>
	typename List<T>::const_iterator List<T>::end() const
	{
		return const_iterator(pHead_);
	}

	//容量
	template<typename T>
	bool List<T>::empty() const
	{
		return size_ == 0;
	}

	template<typename T>
	typename List<T>::size_type List<T>::size() const
	{
		return size_;
	}

	template<typename T>
	typename List<T>::size_type List<T>::max_size() const
	{
		return (size_type)(-1);
	}

	//修改器
	template<typename T>
	void List<T>::clear()
	{
		DoClear();
		DoInit();
		size_ = 0;
	}

	template<typename T>
	typename List<T>::iterator List<T>::insert(const_iterator pos, const value_type& value)
	{
		node_type* pNewNode = new node_type(value);
		pNewNode->insert(pos.pNode_);
		++size_;
		return pNewNode;
	}

	template<typename T>
	typename List<T>::iterator List<T>::insert(const_iterator pos, size_type count, const value_type& value)
	{
		iterator itPrev(pos.pNode_);
		--itPrev;
		DoInsertValues(pos.pNode_, count, value);
		return ++itPrev;
	}

	template<typename T>
	template<class InputIterator>
	typename List<T>::iterator List<T>::insert(const_iterator pos, InputIterator first, InputIterator last)
	{
		iterator itPrev(pos.pNode_);
		--itPrev;
		DoInsert(pos.pNode_, first, last, std::is_integral<InputIterator>());
		return ++itPrev;
	}

	template<typename T>
	typename List<T>::iterator List<T>::erase(const_iterator pos)
	{
		++pos;
		DoErase(pos.pNode_->pPrev_);
		return iterator(pos.pNode_);
	}

	template<typename T>
	typename List<T>::iterator List<T>::erase(const_iterator first, const_iterator last)
	{
		while (first != last)
		{
			first = erase(first);
		}
		return iterator(last.pNode_);
	}

	template<typename T>
	void List<T>::push_front(const value_type& value)
	{
		DoInsertValue(pHead_->pNext_, value);
	}

	template<typename T>
	void List<T>::pop_front()
	{
		DoErase(pHead_->pNext_);
	}

	template<typename T>
	void List<T>::push_back(const value_type& value)
	{
		DoInsertValue(pHead_, value);
	}

	template<typename T>
	void List<T>::pop_back()
	{
		DoErase(pHead_->pPrev_);
	}

	template<typename T>
	void List<T>::resize(size_type count, const value_type& value)
	{
		iterator cur(pHead_->pNext_);
		size_type i = 0;
		while ((cur.pNode_ != pHead_) && (i < count))
		{
			++cur;
			++i;
		}
		if (i == count)
		{
			erase(cur, pHead_);
		}
		else
		{
			insert(pHead_, count - i, value);
		}
	}

	template<typename T>
	void List<T>::swap(this_type& other)
	{
		std::swap(pHead_, other.pHead_);
		std::swap(size_, other.size_);
	}

	//操作
	template<typename T>
	void List<T>::merge(this_type& other)
	{
		if (this != &other)
		{
			iterator first(pHead_->pNext_);
			iterator firstOther(other.pHead_->pNext_);
			const iterator last(pHead_);
			const iterator lastOther(other.pHead_);
			while ((first != last) && (firstOther != lastOther))
			{
				if (*firstOther < *first)
				{
					iterator next(firstOther);
					splice(first, other, firstOther, ++next);
					firstOther = next;
				}
				else
				{
					++first;
				}
			}
			if (firstOther != lastOther)
			{
				splice(last, other, firstOther, lastOther);
			}
		}
	}

	template<typename T>
	template<typename Compare>
	void List<T>::merge(this_type& other, Compare comp)
	{
		if (this != &other)
		{
			iterator first(pHead_->pNext_);
			iterator firstOther(other.pHead_->pNext_);
			const iterator last(pHead_);
			const iterator lastOther(other.pHead_);
			while ((first != last) && (firstOther != lastOther))
			{
				if (comp(*firstOther, *first))
				{
					iterator next(firstOther);
					splice(first, other, firstOther, ++next);
					firstOther = next;
				}
				else
				{
					++first;
				}
			}
			if (firstOther != lastOther)
			{
				splice(last, other, firstOther, lastOther);
			}
		}
	}

	template<typename T>
	void List<T>::splice(const_iterator pos, this_type& other)
	{
		if (other.size_)
		{
			pos.pNode_->splice(other.pHead_->pNext_, other.pHead_);
			size_ += other.size_;
			other.size_ = 0;
		}
	}

	template<typename T>
	void List<T>::splice(const_iterator pos, this_type& other, const_iterator it)
	{
		iterator i(it.pNode_);
		++i;
		if ((pos != i) && (pos != it))
		{
			pos.pNode_->splice(it.pNode_, i.pNode_);
			++size_;
			--other.size_;
		}
	}

	template<typename T>
	void List<T>::splice(const_iterator pos, this_type& other, const_iterator first, const_iterator last)
	{
		size_type count = 0;
		const_iterator it = first;
		while (it != last)
		{
			++it;
			++count;
		}
		if (count)
		{
			pos.pNode_->splice(first.pNode_, last.pNode_);
			size_ += count;
			other.size_ -= count;
		}
	}

	template<typename T>
	typename List<T>::size_type List<T>::remove(const T& value)
	{
		iterator cur(pHead_->pNext_);
		size_type count = 0;
		while (cur != pHead_)
		{
			if (*cur == value)
			{
				++cur;
				DoErase(cur.pNode_->pPrev_);
				++count;
			}
			else
			{
				++cur;
			}
		}
		return count;
	}

	template<typename T>
	template<typename UnaryPredicate>
	typename List<T>::size_type List<T>::remove_if(UnaryPredicate p)
	{
		size_type count = 0;
		for (iterator first(pHead_->pNext_), last(pHead_); first != last;)
		{
			iterator temp(first);
			++temp;
			if (p(first.pNode_->data_))
			{
				DoErase(first.pNode_);
				++count;
			}
			first = temp;
		}
		return count;
	}

	template<typename T>
	void List<T>::reverse()
	{
		node_type* pNode = pHead_;
		do
		{
			node_type* const pTemp = pNode->pNext_;
			pNode->pNext_ = pNode->pPrev_;
			pNode->pPrev_ = pTemp;
			pNode = pNode->pPrev_;
		} while (pNode != pHead_);
	}

	template<typename T>
	void List<T>::unique()
	{
		iterator first(pHead_->pNext_);
		const iterator last(pHead_);
		if (first != last)
		{
			iterator next(first);
			while (++next != last)
			{
				if (*first == *next)
				{
					DoErase(next.pNode_);
				}
				else
				{
					first = next;
				}
				next = first;
			}
		}
	}

	template<typename T>
	template<class BinaryPredicate>
	void List<T>::unique(BinaryPredicate p)
	{
		iterator first(pHead_->pNext_);
		const iterator last(pHead_);
		if (first != last)
		{
			iterator next(first);
			while (++next != last)
			{
				if (p(*first, *next))
				{
					DoErase(next.pNode_);
				}
				else
				{
					first = next;
				}
				next = first;
			}
		}
	}

	//帮手函数
	template<typename T>
	void List<T>::DoInit()
	{
		pHead_->pNext_ = pHead_;
		pHead_->pPrev_ = pHead_;
	}

	template<typename T>
	void List<T>::DoInsertValue(node_type* pNode, const value_type& value)
	{
		node_type* const pNewNode = new node_type(value);
		pNewNode->insert(pNode);
		++size_;
	}

	template<typename T>
	void List<T>::DoInsertValues(node_type* pNode, size_type count, const value_type& value)
	{
		for (; count > 0; --count)
		{
			DoInsertValue(pNode, value);
		}
	}

	template<typename T>
	template<typename Integer>
	void List<T>::DoInsert(node_type* pNode, Integer count, Integer value, std::true_type)
	{
		DoInsertValues(pNode, count, value);
	}

	template<typename T>
	template<typename InputIterator>
	void List<T>::DoInsert(node_type* pNode, InputIterator first, InputIterator last, std::false_type)
	{
		for (; first != last; ++first)
		{
			DoInsertValue(pNode, *first);
		}
	}

	template<typename T>
	template<typename InputIterator>
	void List<T>::DoAssign(InputIterator first, InputIterator last, std::false_type)
	{
		node_type* pNode = pHead_->pNext_;
		for (; (pNode != pHead_) && (first != last); ++first)
		{
			pNode->data_ = *first;
			pNode = pNode->pNext_;
		}
		if (first == last)
		{
			erase(const_iterator(pNode), const_iterator(pHead_));
		}
		else
		{
			DoInsert(pHead_, first, last, std::false_type());
		}
	}

	template<typename T>
	void List<T>::DoAssignValues(size_type count, const value_type& value)
	{
		node_type* pNode = pHead_->pNext_;
		for (; (pNode != pHead_) && (count > 0); --count)
		{
			pNode->data_ = value;
			pNode = pNode->pNext_;
		}
		if (count == 0)
		{
			erase(const_iterator(pNode), const_iterator(pHead_));
		}
		else
		{
			DoInsertValues(pHead_, count, value);
		}
	}

	template<typename T>
	template<typename Integer>
	void List<T>::DoAssign(Integer count, Integer value, std::true_type)
	{
		DoAssignValues(count, value);
	}

	template<typename T>
	void List<T>::DoErase(node_type* pNode)
	{
		pNode->remove();
		pNode->~node_type();
		::operator delete(pNode);
		--size_;
	}

	template<typename T>
	void List<T>::DoClear()
	{
		node_type* p = pHead_->pNext_;
		while (p != pHead_)
		{
			node_type* const pTemp = p;
			p = p->pNext_;
			pTemp->~node_type();
			::operator delete(pTemp);
		}
	}
}