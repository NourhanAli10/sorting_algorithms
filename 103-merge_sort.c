#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (array == NULL || size < 2)
		return;


	temp_array = malloc(sizeof(int) * size);

	if (temp_array == NULL)
		return;


	merge_sort_helper(array, size, temp_array);

	free(temp_array);
}

/**
 * merge_sort_helper - Helper function for merge sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @temp_array: Temporary array for merging
 */
void merge_sort_helper(int *array, size_t size, int *temp_array)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;

	merge_sort_helper(array, mid, temp_array);
	merge_sort_helper(array + mid, size - mid, temp_array);


	merge(array, mid, size, temp_array);
}

/**
 * merge - Merges two sorted subarrays
 * @array: The array containing the subarrays to be merged
 * @mid: Middle index
 * @size: Number of elements in the subarrays
 * @temp_array: Temporary array for merging
 */
void merge(int *array, size_t mid, size_t size, int *temp_array)
{
	size_t i = 0, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	while (i < mid && j < size)
	{
		if (array[i] <= array[j])
			temp_array[k++] = array[i++];
		else
			temp_array[k++] = array[j++];
	}

	while (i < mid)
		temp_array[k++] = array[i++];

	while (j < size)
		temp_array[k++] = array[j++];

	for (i = 0; i < size; i++)
		array[i] = temp_array[i];

	printf("[Done]: ");
	print_array(array, size);
}
