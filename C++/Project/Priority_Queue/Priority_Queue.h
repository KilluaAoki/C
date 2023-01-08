#pragma once

#include <vector>
#include <functional>

#include "Heap.h"

namespace Aoki
{
	template<typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
	class Priority_Queue
	{
	public:
		typedef Priority_Queue<T, Container, Compare> this_type;
		typedef Container container_type;
		typedef Compare compare_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::size_type size_type;
		typedef typename Container::difference_type difference_type;

	protected:
		container_type c;
		compare_type comp;

	public:
		Priority_Queue();

		Priority_Queue(const compare_type& compare, const container_type& cont);

		template<typename InputIterator>
		Priority_Queue(InputIterator first, InputIterator last);

		template<typename InputIterator>
		Priority_Queue(InputIterator first, InputIterator last, const compare_type& compare,
				const container_type& cont);

		const_reference top() const;

		bool empty() const;

		size_type size() const;

		void push(const value_type& value);

		void pop();

		void swap(this_type& other);
	};

	///////////////////////////////////////////////////////////////////////
	// Priority_Queue Class
	///////////////////////////////////////////////////////////////////////

	template<typename T, typename Container, typename Compare>
	Priority_Queue<T, Container, Compare>::Priority_Queue() : c(), comp()
	{
	}

	template<typename T, typename Container, typename Compare>
	Priority_Queue<T, Container, Compare>::Priority_Queue(const compare_type& compare, const container_type& cont)
			: comp(compare), c(cont)
	{
		Aoki::Make_Heap(c.begin(), c.end(), comp);
	}

	template<typename T, typename Container, typename Compare>
	template<typename InputIterator>
	Priority_Queue<T, Container, Compare>::Priority_Queue(InputIterator first, InputIterator last)
			: c(first, last), comp()
	{
		Aoki::Make_Heap(c.begin(), c.end(), comp);
	}

	template<typename T, typename Container, typename Compare>
	template<typename InputIterator>
	Priority_Queue<T, Container, Compare>::Priority_Queue(InputIterator first, InputIterator last,
			const compare_type& compare, const container_type& cont): comp(compare), c(cont)
	{
		c.insert(c.end(), first, last);
		Aoki::Make_Heap(c.begin(), c.end(), comp);
	}

	template<typename T, typename Container, typename Compare>
	typename Priority_Queue<T, Container, Compare>::const_reference Priority_Queue<T, Container, Compare>::top() const
	{
		return c.front();
	}

	template<typename T, typename Container, typename Compare>
	bool Priority_Queue<T, Container, Compare>::empty() const
	{
		return c.empty();
	}

	template<typename T, typename Container, typename Compare>
	typename Priority_Queue<T, Container, Compare>::size_type Priority_Queue<T, Container, Compare>::size() const
	{
		return c.size();
	}

	template<typename T, typename Container, typename Compare>
	void Priority_Queue<T, Container, Compare>::push(const value_type& value)
	{
		c.push_back(value);
		Aoki::Push_Heap(c.begin(), c.end(), comp);
	}

	template<typename T, typename Container, typename Compare>
	void Priority_Queue<T, Container, Compare>::pop()
	{
		Aoki::Pop_Heap(c.begin(), c.end(), comp);
		c.pop_back();
	}

	template<typename T, typename Container, typename Compare>
	void Priority_Queue<T, Container, Compare>::swap(this_type& other)
	{
		std::swap(c, other.c);
		std::swap(comp, other.comp);
	}

	///////////////////////////////////////////////////////////////////////
	// Global Operators
	///////////////////////////////////////////////////////////////////////

	template<typename T, typename Container, typename Compare>
	bool operator==(const Priority_Queue<T, Container, Compare>& a, const Priority_Queue<T, Container, Compare>& b)
	{
		return (a.c == b.c);
	}

	template<typename T, typename Container, typename Compare>
	bool operator<(const Priority_Queue<T, Container, Compare>& a, const Priority_Queue<T, Container, Compare>& b)
	{
		return (a.c < b.c);
	}

	template<typename T, typename Container, typename Compare>
	inline bool
	operator!=(const Priority_Queue<T, Container, Compare>& a, const Priority_Queue<T, Container, Compare>& b)
	{
		return !(a.c == b.c);
	}

	template<typename T, typename Container, typename Compare>
	inline bool
	operator>(const Priority_Queue<T, Container, Compare>& a, const Priority_Queue<T, Container, Compare>& b)
	{
		return (b.c < a.c);
	}

	template<typename T, typename Container, typename Compare>
	inline bool
	operator<=(const Priority_Queue<T, Container, Compare>& a, const Priority_Queue<T, Container, Compare>& b)
	{
		return !(b.c < a.c);
	}

	template<typename T, typename Container, typename Compare>
	inline bool
	operator>=(const Priority_Queue<T, Container, Compare>& a, const Priority_Queue<T, Container, Compare>& b)
	{
		return !(a.c < b.c);
	}

	template<class T, class Container, class Compare>
	inline void swap(Priority_Queue<T, Container, Compare>& a, Priority_Queue<T, Container, Compare>& b)
	{
		a.swap(b);
	}
}