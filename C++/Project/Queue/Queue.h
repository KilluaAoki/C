#pragma once

#include "deque"

namespace Aoki
{
	template<typename T, typename Container = std::deque<T>>
	class Queue
	{
	public:
		typedef Queue<T, Container> this_type;
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::size_type size_type;

	protected:
		Container c;

	public:
		Queue();

		explicit Queue(const container_type& other);

		reference front();

		const_reference front() const;

		reference back();

		const_reference back() const;

		bool empty() const;

		size_type size() const;

		void push(const value_type& value);

		void pop();

		void swap(this_type& other);
	};

	///////////////////////////////////////////////////////////////////////
	// Queue Class
	///////////////////////////////////////////////////////////////////////

	template<typename T, typename Container>
	Queue<T, Container>::Queue(): c()
	{
	}

	template<typename T, typename Container>
	Queue<T, Container>::Queue(const Container& other) : c(other)
	{
	}

	template<typename T, typename Container>
	typename Queue<T, Container>::reference Queue<T, Container>::front()
	{
		return c.front();
	}

	template<typename T, typename Container>
	typename Queue<T, Container>::const_reference Queue<T, Container>::front() const
	{
		return c.front();
	}

	template<typename T, typename Container>
	typename Queue<T, Container>::reference Queue<T, Container>::back()
	{
		return c.back();
	}

	template<typename T, typename Container>
	typename Queue<T, Container>::const_reference Queue<T, Container>::back() const
	{
		return c.back();
	}

	template<typename T, typename Container>
	bool Queue<T, Container>::empty() const
	{
		return c.empty();
	}

	template<typename T, typename Container>
	typename Queue<T, Container>::size_type Queue<T, Container>::size() const
	{
		return c.size();
	}

	template<typename T, typename Container>
	void Queue<T, Container>::push(const value_type& value)
	{
		c.push_back(value);
	}

	template<typename T, typename Container>
	void Queue<T, Container>::pop()
	{
		c.pop_front();
	}

	template<typename T, typename Container>
	void Queue<T, Container>::swap(this_type& other)
	{
		std::swap(c, other.c);
	}

	///////////////////////////////////////////////////////////////////////
	// Global Operators
	///////////////////////////////////////////////////////////////////////

	template<typename T, typename Container>
	inline bool operator==(const Queue<T, Container>& a, const Queue<T, Container>& b)
	{
		return (a.c == b.c);
	}

	template<typename T, typename Container>
	inline bool operator!=(const Queue<T, Container>& a, const Queue<T, Container>& b)
	{
		return !(a.c == b.c);
	}

	template<typename T, typename Container>
	inline bool operator<(const Queue<T, Container>& a, const Queue<T, Container>& b)
	{
		return (a.c < b.c);
	}

	template<typename T, typename Container>
	inline bool operator>(const Queue<T, Container>& a, const Queue<T, Container>& b)
	{
		return (b.c < a.c);
	}

	template<typename T, typename Container>
	inline bool operator<=(const Queue<T, Container>& a, const Queue<T, Container>& b)
	{
		return !(b.c < a.c);
	}

	template<typename T, typename Container>
	inline bool operator>=(const Queue<T, Container>& a, const Queue<T, Container>& b)
	{
		return !(a.c < b.c);
	}

	template<typename T, typename Container>
	inline void swap(Queue<T, Container>& a, Queue<T, Container>& b)
	{
		a.swap(b);
	}
}