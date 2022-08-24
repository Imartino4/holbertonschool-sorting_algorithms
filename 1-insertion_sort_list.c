#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked listed list using insertion sort
 * @list: pointer to a listint_t doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux1 = *list, *aux2;

	aux2 = aux1->next;
	while (aux2)
	{
		if (aux2->n < aux1->n)
		{
			aux2->prev = aux1->prev;
			aux2->next = aux1->next;
			if (aux2->next)
				aux2->next->prev = aux1;
			aux2->next = aux1;
			aux1->prev = aux1;
			print_list(*list);
		}
	}
}

