#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * Description: sorts a doubly linked list in ascending
 * ordder using the insertion algorithm
 * @list: pointer to a listint_t doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	bool flag = false;
	listint_t *travel = NULL, *aux = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	travel = *list;
	while (travel->next)
	{
		if (travel->n > travel->next->n)
		{
			travel->next->prev = travel->prev;
			if (travel->next->prev)
				travel->prev->next = travel->next;
			else
				*list = travel->next;

			travel->prev = travel->next;
			travel->next = travel->next->next;
			travel->prev->next = travel;
			if (travel->next)
				travel->next->prev = travel;

			travel = travel->prev;
			print_list(*list);

			if (travel->prev && travel->prev->n > travel->n)
			{
				if (!flag)
					aux = travel->next;
				flag = true;
				travel = travel->prev;
				continue;
			}
		}
		if (!flag)
			travel = travel->next;
		else
			travel = aux, flag = false;
	}
}
