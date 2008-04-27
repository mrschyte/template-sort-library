#ifndef __GNOMESORT_HPP__
#define __GNOMESORT_HPP__

namespace tsl {

	template <class T>
	class GnomeSort
	{
		public:
			static void sort(T& array, unsigned int length)
			{
				if (length <= 1)
					return;

				for (unsigned int i = length - 1; i > 0; )
				{
					if (array[i - 1] > array[i])
					{
						std::swap(array[i - 1], array[i]);

						if (i + 1 < length)
							i++;
						else
							i--;
					} else
						i--;
				}
			}
	};

} // tsl

#endif
