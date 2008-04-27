#ifndef __BENCHMARK_HPP__
#define __BENCHMARK_HPP__

#include <sys/time.h>

template <class T>
class Benchmark
{
	private:
		typedef void (*sort_function)(T& array, unsigned int length);

	public:
		static void benchmark(sort_function sort, struct timeval* delta, unsigned int count, T& array, unsigned int length)
		{
			struct timeval before;
			struct timeval after;

			gettimeofday(&before, NULL);

			for (unsigned int i = 0; i < count; i++)
			{
				T temp(array);
				sort(temp, length);
			}

			gettimeofday(&after, NULL);

			delta->tv_usec = after.tv_usec - before.tv_usec;
			delta->tv_sec = after.tv_sec - before.tv_sec;
		}
};

#endif
