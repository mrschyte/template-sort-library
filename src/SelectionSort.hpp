#ifndef __SELECTIONSORT_HPP__
#define __SELECTIONSORT_HPP__

#include <algorithm>

namespace tsl {

	template <class T>
	class SelectionSort
	{
		public:
			static void sort(T& array, unsigned int length)
			{
				if (length <= 1)
					return;

				for (unsigned int i = 0; i < length - 1; i++)
				{
					unsigned int m = i;

					for (unsigned int j = i + 1; j < length; j++)
					{
						if (array[j] < array[m])
							m = j;
					}

					if (array[m] < array[i])
						std::swap(array[m], array[i]);
				}
			}
	};

} // tsl

#endif
