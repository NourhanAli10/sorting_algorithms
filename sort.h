#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** mandatory*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap_a(int *array, size_t size, int a, int b);
int lomuto_partition(int *array, size_t size, int low, int high);
void quick_sort_recursive(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**advanced*/
void shell_sort(int *array, size_t size);
/** task 5 */
void cocktail_sort_list(listint_t **list);
void swap_nod(listint_t **list, listint_t *a, listint_t *b);
/**task 6*/
void counting_sort(int *array, size_t size);
int get_maximum_value(int *array, int size);
/**task 7*/
void merge(int *array, size_t mid, size_t size, int *temp_array);
void merge_sort(int *array, size_t size);
void merge_sort_helper(int *array, size_t size, int *temp_array);
/**task 8*/
void heapify(int *array, size_t n, size_t i, size_t size);
void heap_sort(int *array, size_t size);
/** task 9*/
void radix_sort(int *array, size_t size);
/** task 10*/
void bitonic_merge(int *array, size_t low, size_t count, int order);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int order);
/**task 11*/
int hoare_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
#endif
