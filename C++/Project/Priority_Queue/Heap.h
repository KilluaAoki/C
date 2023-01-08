#pragma once

#include <iterator>
#include <functional>

namespace Aoki
{
	///////////////////////////////////////////////////////////////////////
	// Promote_Heap ( Internal Function )
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator, typename Distance, typename T, typename value_type>
	void Promote_Heap_Impl(RandomAccessIterator first, Distance topPosition, Distance position, T value)
	{
		for (Distance parentPosition = (position - 1) >> 1;
			 position > topPosition && std::less<value_type>()(*(first + parentPosition), value);
			 parentPosition = (position - 1) >> 1)
		{
			*(first + position) = *(first + parentPosition);
			position = parentPosition;
		}
		*(first + position) = value;
	}

	template<typename RandomAccessIterator, typename Distance, typename T, typename Compare, typename value_type>
	void
	Promote_Heap_Impl(RandomAccessIterator first, Distance topPosition, Distance position, T value, Compare compare)
	{
		for (Distance parentPosition = (position - 1) >> 1;
			 position > topPosition && compare(*(first + parentPosition), value);
			 parentPosition = (position - 1) >> 1)
		{
			*(first + position) = *(first + parentPosition);
			position = parentPosition;
		}
		*(first + position) = value;
	}

	///////////////////////////////////////////////////////////////////////
	// Promote_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator, typename Distance, typename T>
	void Promote_Heap(RandomAccessIterator first, Distance topPosition, Distance position, const T& value)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		Promote_Heap_Impl<RandomAccessIterator, Distance, const T&, const value_type>
				(first, topPosition, position, value);
	}

	template<typename RandomAccessIterator, typename Distance, typename T, typename Compare>
	void
	Promote_Heap(RandomAccessIterator first, Distance topPosition, Distance position, const T& value, Compare compare)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		Promote_Heap_Impl<RandomAccessIterator, Distance, const T&, Compare, const value_type>
				(first, topPosition, position, value, compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Adjust_Heap ( Internal Function )
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator, typename Distance, typename T, typename ValueType>
	void
	Adjust_Heap_Impl(RandomAccessIterator first, Distance topPosition, Distance heapSize, Distance position, T value)
	{
		Distance childPosition = (2 * position) + 2;

		for (; childPosition < heapSize; childPosition = (2 * childPosition) + 2)
		{
			if (std::less<ValueType>()(*(first + childPosition), *(first + (childPosition - 1))))
			{
				--childPosition;
			}
			*(first + position) = *(first + childPosition);
			position = childPosition;
		}

		if (childPosition == heapSize)
		{
			*(first + position) = *(first + (childPosition - 1));
			position = childPosition - 1;
		}

		Aoki::Promote_Heap<RandomAccessIterator, Distance, T>(first, topPosition, position, value);
	}

	template<typename RandomAccessIterator, typename Distance, typename T, typename Compare, typename ValueType>
	void
	Adjust_Heap_Impl(RandomAccessIterator first, Distance topPosition, Distance heapSize, Distance position, T value,
			Compare compare)
	{
		Distance childPosition = (2 * position) + 2;

		for (; childPosition < heapSize; childPosition = (2 * childPosition) + 2)
		{
			if (compare(*(first + childPosition), *(first + (childPosition - 1))))
			{
				--childPosition;
			}
			*(first + position) = *(first + childPosition);
			position = childPosition;
		}

		if (childPosition == heapSize)
		{
			*(first + position) = *(first + (childPosition - 1));
			position = childPosition - 1;
		}

		Aoki::Promote_Heap<RandomAccessIterator, Distance, T, Compare>(first, topPosition, position, value, compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Adjust_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator, typename Distance, typename T>
	void
	Adjust_Heap(RandomAccessIterator first, Distance topPosition, Distance heapSize, Distance position, const T& value)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		Adjust_Heap_Impl<RandomAccessIterator, Distance, const T&, const value_type>(first, topPosition, heapSize,
				position, value);
	}

	template<typename RandomAccessIterator, typename Distance, typename T, typename Compare>
	void
	Adjust_Heap(RandomAccessIterator first, Distance topPosition, Distance heapSize, Distance position, const T& value,
			Compare compare)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		Adjust_Heap_Impl<RandomAccessIterator, Distance, const T&, Compare, const value_type>(first, topPosition,
				heapSize, position, value, compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Push_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator>
	inline void Push_Heap(RandomAccessIterator first, RandomAccessIterator last)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		const value_type tempBottom(*(last - 1));

		Aoki::Promote_Heap<RandomAccessIterator, difference_type, value_type>
				(first, (difference_type)0, (difference_type)(last - first - 1), tempBottom);
	}

	template<typename RandomAccessIterator, typename Compare>
	inline void Push_Heap(RandomAccessIterator first, RandomAccessIterator last, Compare compare)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		const value_type tempBottom(*(last - 1));

		Aoki::Promote_Heap<RandomAccessIterator, difference_type, value_type, Compare>
				(first, (difference_type)0, (difference_type)(last - first - 1), tempBottom, compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Pop_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator>
	inline void Pop_Heap(RandomAccessIterator first, RandomAccessIterator last)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		value_type tempBottom(*(last - 1));
		*(last - 1) = *first;

		Aoki::Adjust_Heap<RandomAccessIterator, difference_type, value_type>
				(first, (difference_type)0, (difference_type)(last - first - 1), 0, tempBottom);
	}

	template<typename RandomAccessIterator, typename Compare>
	inline void Pop_Heap(RandomAccessIterator first, RandomAccessIterator last, Compare compare)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		value_type tempBottom(*(last - 1));
		*(last - 1) = *first;

		Aoki::Adjust_Heap<RandomAccessIterator, difference_type, value_type, Compare>
				(first, (difference_type)0, (difference_type)(last - first - 1), 0, tempBottom, compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Make_Heap
	///////////////////////////////////////////////////////////////////////

	template<class RandomAccessIterator>
	void Make_Heap(RandomAccessIterator first, RandomAccessIterator last)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;

		const difference_type heapSize = last - first;

		if (heapSize >= 2)
		{
			difference_type parentPosition = ((heapSize - 2) >> 1) + 1;
			do
			{
				--parentPosition;
				value_type temp(*(first + parentPosition));
				Aoki::Adjust_Heap<RandomAccessIterator, difference_type, value_type>
						(first, parentPosition, heapSize, parentPosition, temp);
			} while (parentPosition != 0);
		}
	}

	template<class RandomAccessIterator, typename Compare>
	void Make_Heap(RandomAccessIterator first, RandomAccessIterator last, Compare compare)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;

		const difference_type heapSize = last - first;

		if (heapSize >= 2)
		{
			difference_type parentPosition = ((heapSize - 2) >> 1) + 1;
			do
			{
				--parentPosition;
				value_type temp(*(first + parentPosition));
				Aoki::Adjust_Heap<RandomAccessIterator, difference_type, value_type, Compare>
						(first, parentPosition, heapSize, parentPosition, temp, compare);
			} while (parentPosition != 0);
		}
	}

	///////////////////////////////////////////////////////////////////////
	// Sort_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator>
	inline void Sort_Heap(RandomAccessIterator first, RandomAccessIterator last)
	{
		for (; (last - first) > 1; --last)
			Aoki::Pop_Heap<RandomAccessIterator>(first, last);
	}

	template<typename RandomAccessIterator, typename Compare>
	inline void Sort_Heap(RandomAccessIterator first, RandomAccessIterator last, Compare compare)
	{
		for (; (last - first) > 1; --last)
			Aoki::Pop_Heap<RandomAccessIterator, Compare>(first, last, compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Remove_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator, typename Distance>
	inline void Remove_Heap(RandomAccessIterator first, Distance heapSize, Distance position)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		const value_type tempBottom(*(first + heapSize - 1));
		*(first + heapSize - 1) = *(first + position);

		Aoki::Adjust_Heap<RandomAccessIterator, difference_type, value_type>
				(first, (difference_type)0, (difference_type)(heapSize - 1), (difference_type)position, tempBottom);
	}

	template<typename RandomAccessIterator, typename Distance, typename Compare>
	inline void Remove_Heap(RandomAccessIterator first, Distance heapSize, Distance position, Compare compare)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		const value_type tempBottom(*(first + heapSize - 1));
		*(first + heapSize - 1) = *(first + position);

		Aoki::Adjust_Heap<RandomAccessIterator, difference_type, value_type, Compare>
				(first, (difference_type)0, (difference_type)(heapSize - 1), (difference_type)position, tempBottom,
						compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Change_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator, typename Distance>
	inline void Change_Heap(RandomAccessIterator first, Distance heapSize, Distance position)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		Aoki::Remove_Heap<RandomAccessIterator, Distance>(first, heapSize, position);

		value_type tempBottom(*(first + heapSize - 1));

		Aoki::Promote_Heap<RandomAccessIterator, difference_type, value_type>
				(first, (difference_type)0, (difference_type)(heapSize - 1), tempBottom);
	}

	template<typename RandomAccessIterator, typename Distance, typename Compare>
	inline void Change_Heap(RandomAccessIterator first, Distance heapSize, Distance position, Compare compare)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

		Aoki::Remove_Heap<RandomAccessIterator, Distance, Compare>(first, heapSize, position, compare);

		value_type tempBottom(*(first + heapSize - 1));

		Aoki::Promote_Heap<RandomAccessIterator, difference_type, value_type, Compare>
				(first, (difference_type)0, (difference_type)(heapSize - 1), tempBottom, compare);
	}

	///////////////////////////////////////////////////////////////////////
	// Is_Heap_Until
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator>
	inline RandomAccessIterator Is_Heap_Until(RandomAccessIterator first, RandomAccessIterator last)
	{
		int counter = 0;

		for (RandomAccessIterator child = first + 1; child < last; ++child, counter ^= 1)
		{
			if (*first < *child)
				return child;
			first += counter;
		}

		return last;
	}

	template<typename RandomAccessIterator, typename Compare>
	inline RandomAccessIterator Is_Heap_Until(RandomAccessIterator first, RandomAccessIterator last, Compare compare)
	{
		int counter = 0;

		for (RandomAccessIterator child = first + 1; child < last; ++child, counter ^= 1)
		{
			if (compare(*first, *child))
				return child;
			first += counter;
		}

		return last;
	}

	///////////////////////////////////////////////////////////////////////
	// Is_Heap
	///////////////////////////////////////////////////////////////////////

	template<typename RandomAccessIterator>
	inline bool Is_Heap(RandomAccessIterator first, RandomAccessIterator last)
	{
		return (Aoki::Is_Heap_Until(first, last) == last);
	}

	template<typename RandomAccessIterator, typename Compare>
	inline bool Is_Heap(RandomAccessIterator first, RandomAccessIterator last, Compare compare)
	{
		return (Aoki::Is_Heap_Until(first, last, compare) == last);
	}
}