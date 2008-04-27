#ifndef __QUICKSORT_HPP__
#define __QUICKSORT_HPP__

#include <vector>

#define QUICKSORT_STACK_LIMIT		8192

namespace tsl {

	template <class T, unsigned int STACK_LIMIT = QUICKSORT_STACK_LIMIT>
	class QuickSort
	{
		private:
			static void quicksort_recursive(T& array, unsigned int left, unsigned int right)
			{
				if (left < right)
				{
					unsigned int m = left;

					for (unsigned int i = left + 1; i < right; i++)
					{
						if (array[i] < array[left])
							std::swap(array[++m], array[i]);
					}

					std::swap(array[left], array[m]);

					quicksort_recursive(array, left, m);
					quicksort_recursive(array, m + 1, right);
				}
			}

			static void quicksort(T& array, unsigned int length)
			{
				std::vector<unsigned int> stack;
				unsigned int left = 0;
				unsigned int right = length;

				do
				{
					if (left >= right)
					{
						left = stack.back(); stack.pop_back();
						right = stack.back(); stack.pop_back();
					}

					unsigned int m = left;

					for (unsigned int i = left + 1; i < right; i++)
					{
						if (array[i] < array[left])
							std::swap(array[++m], array[i]);
					}

					std::swap(array[left], array[m]);

					if (m + 1 < right)
					{
						stack.push_back(right);
						stack.push_back(m + 1);
					}
					right = m;
				} while (stack.size() > 0);
			}

		public:
			static void sort(T& array, unsigned int length)
			{
				if (length < STACK_LIMIT)
					quicksort_recursive(array, 0, length);
				else
					quicksort(array, length);
			}
	};

} // tsl

#endif
