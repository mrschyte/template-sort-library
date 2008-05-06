#ifndef __SHELLSORT_HPP__
#define __SHELLSORT_HPP__

#include <algorithm>

namespace tsl {

	template <class T>
	class ShellSort {

		public:
			static void sort(T& array, unsigned int length)
			{
				for (unsigned int m = length / 2; m > 0; m /= 2.2)
				{
					for (unsigned int i = m; i < length; i++)
					{
						for (unsigned int j = i; j >= m && array[j - m] > array[j]; j -= m)
							std::swap(array[j], array[j - m]);
					}
				}

			  for (unsigned int i = 1; i < length; i++)
			  {
				  for (unsigned int j = i; j >= 1 && array[j - 1] > array[j]; j--)
					  std::swap(array[j], array[j - 1]);
			  }
			}
	};

} // tsl

#endif
