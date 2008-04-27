#ifndef __MERGESORT_HPP__
#define __MERGESORT_HPP__

namespace tsl {

	template <class T>
	class MergeSort
	{
		private:
			static void merge(T& array, T& temp, unsigned int left, unsigned int m, unsigned int right)
			{
				unsigned int i;
				unsigned int j;
				unsigned int k;

				for (i = left, j = m, k = left; (i < m) && (j < right); k++)
				{
					if (temp[i] < temp[j])
						array[k] = temp[i++];
					else
						array[k] = temp[j++];
				}

				while (i < m)
					array[k++] = temp[i++];

				while (j < right)
					array[k++] = temp[j++];

				for (i = left; i < right; i++)
				{
					temp[i] = array[i];
				}
			}

		public:
			static void sort(T& array, unsigned int length)
			{
				T temp(array);

				for (unsigned int m = 1; m < length; m = m * 2)
				{
					for (unsigned int i = 0; i < length - m; i = i + 2 * m)
						merge(array, temp, i, i + m, (i + 2 * m) < length ? i + 2 * m : length);
				}
			}
	};

} // tsl

#endif
