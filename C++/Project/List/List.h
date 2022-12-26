#pragma once

#include <iostream>

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
		 * @details 将此独立节点( this )插入到链表中的节点 pNode 之前。
		 */
		void insert(this_type* pNode);
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
		List& operator=(const List& other);

		//赋值操作
		void assign(size_type count, const T& value);

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last);

	private:
		//帮手函数

	private:
		//成员变量
		this_type* pHead_;
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
		pHead_->pNext_ = pHead_;
		pHead_->pPrev_ = pHead_;
	}

	template<typename T>
	List<T>::List(size_type count, const value_type& value) : pHead_(new node_type), size_(0)
	{
		while (count--)
		{
			node_type* const pNewNode = new node_type(value);
			pNewNode->insert(pHead_);
			++size_;
		}
	}

	template<typename T>
	template<class InputIterator>
	List<T>::List(InputIterator first, InputIterator last)
	{
		for (; first != last; ++first)
		{
			node_type* const pNewNode = new node_type(*first);
			pNewNode->insert(pHead_);
			++size_;
		}
	}

	template<typename T>
	List<T>::List(const this_type& other)
	{
		for (const_iterator it = other.pHead_->pNext_; it != other.pHead_; ++it)
		{
			node_type* const pNewNode = new node_type(*it);
			pNewNode->insert(pHead_);
			++size_;
		}
	}

	template<typename T>
	List<T>::~List()
	{
		//		node_type* p = static_cast<node_type*>(internalNode().mpNext);
		//
		//		while(p != &internalNode())
		//		{
		//			node_type* const pTemp = p;
		//			p = static_cast<node_type*>(p->mpNext);
		//			pTemp->~node_type();
		//			EASTLFree(internalAllocator(), pTemp, sizeof(node_type));
		//		}

		delete pHead_;
	}

	//重载赋值运算符
	template<typename T>
	typename List<T>::this_type& List<T>::operator=(const this_type& other)
	{
		if (this != &other)
		{
			node_type* pNode = pHead_->pNext_;

		}
		return *this;
	}

	//赋值操作
	template<typename T>
	void List<T>::assign(size_type count, const value_type& value)
	{

	}

	template<typename T>
	template<class InputIterator>
	void List<T>::assign(InputIterator first, InputIterator last)
	{

	}
}