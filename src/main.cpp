#include <iostream>
#include <sys/time.h>

#include "ArrayAccessor.hpp"
#include "Benchmark.hpp"
#include "Sort.hpp"

#define countof(x) (sizeof(x) / sizeof(x[0]))

char message[] = "WDCEFAJILOPVRGHQSBUKNXZMTY";

int main(void)
{
	using namespace tsl;
	unsigned long count = 1000000;

	ArrayAccessor<char> arrayAccessor(message, countof(message) - 1);
	struct timeval delta;

	Benchmark<ArrayAccessor<char> >::benchmark(BubbleSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of BubbleSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	Benchmark<ArrayAccessor<char> >::benchmark(CocktailSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of CocktailSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	Benchmark<ArrayAccessor<char> >::benchmark(GnomeSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of GnomeSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	Benchmark<ArrayAccessor<char> >::benchmark(InsertionSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of InsertionSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	Benchmark<ArrayAccessor<char> >::benchmark(MergeSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of MergeSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	Benchmark<ArrayAccessor<char> >::benchmark(QuickSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of QuickSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	Benchmark<ArrayAccessor<char> >::benchmark(SelectionSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of SelectionSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	Benchmark<ArrayAccessor<char> >::benchmark(ShellSort<ArrayAccessor<char> >::sort, &delta, count, arrayAccessor, arrayAccessor.size());
	printf("%d iterations of ShellSort took %f seconds\n", count, delta.tv_sec + (delta.tv_usec) / 1000000.0);

	return 0;
}
