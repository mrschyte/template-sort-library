#ifndef __INSERTIONSORT_HPP__
#define __INSERTIONSORT_HPP__

#include <algorithm>

namespace tsl {

	template <class T>
	class InsertionSort
	{
		public:
			static void sort(T& array, unsigned int length)
			{
				for (unsigned int i = 0; i < length; i++)
				{
					for (unsigned int j = i; (j > 0) && (array[j] < array[j - 1]); j--)
						std::swap(array[j], array[j - 1]);
				}
			}
	};

} // tsl

#endif
