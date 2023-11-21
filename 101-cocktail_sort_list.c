#include "sort.h"

/**
* swap_nod - Swap two nodes in a doubly-linked list.
* @list: A pointer to the head of a doubly-linked list.
* @a: First node to swap.
* @b: Second node to swap.
*/
void swap_nod(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
* cocktail_sort_list - Sort a doubly-linked list of integers
* in ascending order using cocktail shaker sort.
* @list: A pointer to the head of a doubly-linked list.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL;
	int swapped;

	if (!list || !(*list) || !((*list)->next))
		return;
	do {
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nod(list, start, start->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		end = start;
		for (start = start->prev; start != NULL; start = start->prev)
		{
			if (start->n > start->next->n)
			{
				swap_nod(list, start, start->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
