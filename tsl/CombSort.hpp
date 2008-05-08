#ifndef __COMBSORT_HPP__
#define __COMBSORT_HPP__

#include <algorithm>

namespace tsl {

	template <class T>
	class CombSort
	{
		public:
			static void sort(T& array, unsigned int length)
			{
				unsigned int j = length;
				bool swapped = true;

				while (j > 1 && swapped)
				{
					if (j > 1)
					{
						j /= 1.3;

						if ((j == 10) || (j == 9))
							j = 11;
					}

					swapped = false;
					for (unsigned int i = 0; i + j < length; i++)
					{
						if (array[i] > array[i + j])
						{
							std::swap(array[i], array[i + j]);
							swapped = true;
						}
					}
				}
			}
	};

} // tsl

#endif
