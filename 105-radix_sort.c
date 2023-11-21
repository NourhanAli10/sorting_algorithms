#include "sort.h"
#define MAX 100

/**
 * radix_sort - function that sorts an array of integers in
 * ascending order using the Radix sort algorithm
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */

void radix_sort(int *array, size_t size)
{

	size_t i, bucket[MAX], maxVal = 0, digitPosition = 1;

	if (size < 2)
		return;


	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)maxVal)
			maxVal = array[i];
	}


	while (maxVal / digitPosition > 0)
	{

		int digitCount[10] = {0};

		for (i = 0; i < size; i++)
			digitCount[array[i] / digitPosition % 10]++;

		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];


		for (i = size ; i > 0; i--)
			bucket[--digitCount[array[i - 1] / digitPosition % 10]] = array[i - 1];


		for (i = 0; i < size; i++)
			array[i] = bucket[i];


		print_array(array, size);

		digitPosition *= 10;
	}
}
