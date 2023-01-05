#pragma once

#include "vector"

namespace Aoki
{
	template<typename T, typename Container = std::vector<T>>
	class Stack
	{
	public:
		typedef Stack<T, Container> this_type;
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::size_type size_type;

	protected:
		Container c;

	public:
		Stack();

		explicit Stack(const container_type& other);

		reference top();

		const_reference top() const;

		bool empty() const;

		size_type size() const;

		void push(const value_type& value);

		void pop();

		void swap(this_type& other);
	};

	///////////////////////////////////////////////////////////////////////
	// Stack Class
	///////////////////////////////////////////////////////////////////////

	template<typename T, typename Container>
	Stack<T, Container>::Stack(): c()
	{
	}

	template<typename T, typename Container>
	Stack<T, Container>::Stack(const Container& other) : c(other)
	{
	}

	template<typename T, typename Container>
	typename Stack<T, Container>::reference Stack<T, Container>::top()
	{
		return c.back();
	}

	template<typename T, typename Container>
	typename Stack<T, Container>::const_reference Stack<T, Container>::top() const
	{
		return c.back();
	}

	template<typename T, typename Container>
	bool Stack<T, Container>::empty() const
	{
		return c.empty();
	}

	template<typename T, typename Container>
	typename Stack<T, Container>::size_type Stack<T, Container>::size() const
	{
		return c.size();
	}

	template<typename T, typename Container>
	void Stack<T, Container>::push(const value_type& value)
	{
		c.push_back(value);
	}

	template<typename T, typename Container>
	void Stack<T, Container>::pop()
	{
		c.pop_back();
	}

	template<typename T, typename Container>
	void Stack<T, Container>::swap(this_type& other)
	{
		std::swap(c, other.c);
	}

	///////////////////////////////////////////////////////////////////////
	// Global Operators
	///////////////////////////////////////////////////////////////////////

	template<typename T, typename Container>
	inline bool operator==(const Stack<T, Container>& a, const Stack<T, Container>& b)
	{
		return (a.c == b.c);
	}

	template<typename T, typename Container>
	inline bool operator!=(const Stack<T, Container>& a, const Stack<T, Container>& b)
	{
		return !(a.c == b.c);
	}

	template<typename T, typename Container>
	inline bool operator<(const Stack<T, Container>& a, const Stack<T, Container>& b)
	{
		return (a.c < b.c);
	}

	template<typename T, typename Container>
	inline bool operator>(const Stack<T, Container>& a, const Stack<T, Container>& b)
	{
		return (b.c < a.c);
	}

	template<typename T, typename Container>
	inline bool operator<=(const Stack<T, Container>& a, const Stack<T, Container>& b)
	{
		return !(b.c < a.c);
	}

	template<typename T, typename Container>
	inline bool operator>=(const Stack<T, Container>& a, const Stack<T, Container>& b)
	{
		return !(a.c < b.c);
	}

	template<typename T, typename Container>
	inline void swap(Stack<T, Container>& a, Stack<T, Container>& b)
	{
		a.swap(b);
	}
}