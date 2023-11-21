#include "sort.h"

/**
* bitonic_sort - Sorts an array of integers in
* ascending order using Bitonic sort
* @array: The array to be sorted
* @size: The size of the array
*/
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}

/**
* bitonic_merge - Merges two subarrays of the given array in a specified order
* @array: The array to be merged
* @low: The starting index of the first subarray
* @count: The size of each subarray
* @order: 1 for ascending order, 0 for descending order
*/
void bitonic_merge(int *array, size_t low, size_t count, int order)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		printf("Merging [%lu/%lu] (%s):\n", count, count * 2, order ? "UP" : "DOWN");
		print_array(array + low, count);

		for (i = low; i < low + k; ++i)
		{
			if ((array[i] > array[i + k]) == order)
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
				printf("Result [2/%lu] (%s):\n", count * 2, order ? "UP" : "DOWN");
				print_array(array + low, count * 2);
			}
		}

		bitonic_merge(array, low, k, order);
		bitonic_merge(array, low + k, k, order);
	}
}

/**
* bitonic_sort_recursive - Recursively performs Bitonic sort
* @array: The array to be sorted
* @low: The starting index of the subarray to be sorted
* @count: The size of the subarray
* @order: 1 for ascending order, 0 for descending order
*/
void bitonic_sort_recursive(int *array, size_t low, size_t count, int order)
{
	if (count > 1)
	{
		size_t k = count / 2;

		printf("Merging [%lu/%lu] (%s):\n", count, count * 2, order ? "UP" : "DOWN");
		print_array(array + low, count);

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, order);
	}
}
