#include "sort.h"

/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @head: pointer to the head of the doubly-linked list.
 * @n1: pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *ptr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		ptr = current->prev;
		while (ptr != NULL && current->n < ptr->n)
		{
			swap(list, &ptr, current);
			print_list((const listint_t *)*list);
		}
	}
}
