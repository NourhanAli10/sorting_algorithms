#include "sort.h"

/**
* bubble_sort - function that sorts an array of integers
* in ascending order using the Bubble sort algorithm
* @array:array of integers
* @size: length of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, x;

	int temp;

	bool swapped;

	if (size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			swapped = false;
			for (x = 0; x < size - i - 1; x++)
			{
				if (array[x] > array[x + 1])
				{
					temp = array[x];
					array[x] = array[x + 1];
					array[x + 1] = temp;
					print_array(array, size);
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}
}
