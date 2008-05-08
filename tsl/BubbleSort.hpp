#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__

#include <algorithm>

namespace tsl {

	template <class T>
	class BubbleSort
	{
		public:
			static void sort(T& array, unsigned int length)
			{
				for (unsigned int i = 0; i < length; i++)
				{
					for (unsigned int j = 0; j < i; j++)
					{
						if (array[i] < array[j])
							std::swap(array[i], array[j]);
					}
				};
			}
	};

} // tsl

#endif
