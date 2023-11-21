#include "sort.h"

/**
* get_maximum_value - Get the maximum value in an array of integers.
* @array: An array of integers.
* @size: The size of the array.
*
* Return: The maximum integer in the array.
*/
int get_maximum_value(int *array, int size)
{
	int maximum_value = array[0];

	for (int i = 1; i < size; i++)

	{
		if (array[i] > maximum_value)
		{
			maximum_value = array[i];
		}
	}

	return (maximum_value);
}

/**
* counting_sort - Sort an array of integers in ascending order
* using the counting sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Prints the counting array after setting it up.
*/
void counting_sort(int *array, size_t size)
{
	size_t array_size = size;
	int maximum_value;
	int *count_array, *sorted_array;
	int i;

	if (array == NULL || size < 2)
		return;
	maximum_value = get_maximum_value(array, array_size);
	count_array = malloc(sizeof(int) * (maximum_value + 1));
	if (count_array == NULL)
		return;
	for (i = 0; i <= maximum_value; i++)
	{
		count_array[i] = 0;
	}
	for (i = 0; i < array_size; i++)
	{
		count_array[array[i]]++;
	}
	for (i = 1; i <= maximum_value; i++)
	{
		count_array[i] += count_array[i - 1];
	}
	print_array(count_array, maximum_value + 1);
	sorted_array = malloc(sizeof(int) * array_size);
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = array_size - 1; i >= 0; i--)
	{
		sorted_array[--count_array[array[i]]] = array[i];
	}
	for (i = 0; i < array_size; i++)
	{
		array[i] = sorted_array[i];
	}
	free(sorted_array);
	free(count_array);
}
