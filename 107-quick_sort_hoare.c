#include <stdio.h>
#include "sort.h"



/**
* hoare_partition - Implements the Hoare partition scheme for quicksort.
* @array: The array to be partitioned.
* @low: The starting index of the partition.
* @high: The ending index of the partition.
* @size: The size of the array.
*
* Return: The partition index.
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		else
		{
			return (j);
		}
	}
}

/**
* quicksort - Recursively sorts the array using the Hoare partition scheme.
* @array: The array to be sorted.
* @low: The starting index of the subarray.
* @high: The ending index of the subarray.
* @size: The size of the array.
*/
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);

		quicksort(array, low, p, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
* quick_sort_hoare - Sorts an array of integers in
* ascending order using the Quick sort algorithm (Hoare partition scheme).
* @array: The array to be sorted.
* @size: The size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
