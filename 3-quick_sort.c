#include <stdio.h>
#include "sort.h"

/**
 * swap_a - Swaps two integers in an array and prints the array
 * after each swap.
 * @array: The array containing the elements to be swapped.
 * @size: The size of the array.
 * @a: Index of the first element to be swapped.
 * @b: Index of the second element to be swapped.
 */
void swap_a(int *array, size_t size, int a, int b)
{
	int temp;

	if (array[a] != array[b])
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort.
 * @array: The array to be partitioned.
 * @size: The size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The final position of the pivot after partitioning.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_a(array, size, i, j);
		}
	}

	swap_a(array, size, i + 1, high);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pivot - 1);
		quick_sort_recursive(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
