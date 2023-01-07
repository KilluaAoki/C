#pragma once

namespace Aoki
{
	template<class Iterator, class pointer, class reference>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef reverse_iterator<Iterator, pointer, reference> this_type;

		reverse_iterator() : mIterator()
		{
		}

		explicit reverse_iterator(Iterator it) : mIterator(it)
		{
		}

		reverse_iterator(const reverse_iterator& ri) : mIterator(ri.mIterator)
		{
		}

		iterator_type base() const
		{
			return mIterator;
		}

		reference operator*()
		{
			iterator_type i(mIterator);
			return *--i;
		}

		pointer operator->()
		{
			return &(operator*());
		}

		this_type& operator++()
		{
			--mIterator;
			return *this;
		}

		this_type operator++(int)
		{
			reverse_iterator ri(*this);
			--mIterator;
			return ri;
		}

		this_type& operator--()
		{
			++mIterator;
			return *this;
		}

		this_type operator--(int)
		{
			reverse_iterator ri(*this);
			++mIterator;
			return ri;
		}

	protected:
		Iterator mIterator;
	};

	template<class Iterator, class reference, class pointer>
	inline bool operator==(const reverse_iterator<Iterator, pointer, reference>& lhs,
			const reverse_iterator<Iterator, pointer, reference>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator, class reference, class pointer>
	inline bool operator!=(const reverse_iterator<Iterator, pointer, reference>& lhs,
			const reverse_iterator<Iterator, pointer, reference>& rhs)
	{
		return lhs.base() != rhs.base();
	}
}