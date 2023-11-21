#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order using insertion sort algorithm.
* @list: Pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{

	listint_t *current = NULL;
	listint_t *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{

			if (temp->prev != NULL)
				temp->prev->next = current;
			current->prev = temp->prev;
			temp->prev = current;
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			current->next = temp;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);

			temp = current->prev;
		}

		current = current->next;
	}
}
