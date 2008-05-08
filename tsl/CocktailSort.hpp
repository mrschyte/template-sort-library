#ifndef __COCKTAILSORT_HPP__
#define __COCKTAILSORT_HPP__

#include <algorithm>

namespace tsl {

	template <class T>
	class CocktailSort
	{
		public:
			static void sort(T& array, unsigned int length)
			{
				bool swapped = false;
				unsigned int i;

				if (length <= 1)
					return;

				do
				{
					for (i = 0; i < length - 2; i++)
					{
						if (array[i] > array[i + 1])
						{
							std::swap(array[i], array[i + 1]);
							swapped = true;
						}
					}

					if (!swapped)
						break;

					swapped = false;
					for (i = length - 1; i != 0; i--)
					{
						if (array[i - 1] > array[i])
						{
							std::swap(array[i - 1], array[i]);
							swapped = true;
						}
					}
				} while (swapped);
			}
	};

} // tsl

#endif
