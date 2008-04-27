#ifndef __SHELLSORT_HPP__
#define __SHELLSORT_HPP__

namespace tsl {

	template <class T>
	class ShellSort {

		public:
			static void sort(T& array, unsigned int length)
			{
				for (unsigned int m = length / 2; m > 0; m = (m == 2 ? 1 : (m / 2.2)))
				{
					for (unsigned int i = m; i < length; i++)
					{
						for (unsigned int j = i; j >= m && array[j - m] > array[j]; j -= m)
							std::swap(array[j], array[j - m]);
					}
				}
			}
	};

} // tsl

#endif
