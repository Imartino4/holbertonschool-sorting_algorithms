#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * Description: sorts a doubly linked list in ascending
 * ordder using the insertion algorithm
 * @list: pointer to a listint_t doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux1 = NULL, *aux2 = NULL;

	if (list == NULL || (*list) == NULL)
		return;
	aux1 = *list;

	while (aux1)
	{
		aux2 = aux1;
		while (aux2->prev && aux2->n < aux2->prev->n)
		{
			swap(aux2->prev, aux2, list);
			print_list(*list);
		}
		aux1 = aux1->next;
	}

}
/**
 * swap - swap 2 double linked list nodes
 * @aux1: node
 * @aux2: node
 * @list: double pointer to double linked list
 */

void swap(listint_t *aux1, listint_t *aux2, listint_t **list)
{
	if (aux1->prev != NULL)
	{
		aux1->prev->next = aux2;
		aux2->prev = aux1->prev;
	}
	if (aux2->next != NULL)
	{
		aux2->next->prev = aux1;
		aux1->next = aux2->next;
	}
	if (aux2->next == NULL)
		aux1->next = NULL;
	if (aux1->prev == NULL)
	{
		*list = aux2;
		aux2->prev = NULL;
	}
	aux1->prev = aux2;
	aux2->next = aux1;
}
