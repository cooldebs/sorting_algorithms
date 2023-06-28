#include "sort.h"

/**
 * swap - swaps two nodes of a doubly linked list
 *
 * @node: node
 * @list: head pointer of doubly linked list
 *
 * Return: void
 */
void swap(listint_t **node, listint_t **list)
{
	listint_t *ptr = *node, *tmp, *exp;


	if (!(*node)->prev)
		*list = (*node)->next;

	ptr = exp = *node;
	tmp = ptr->next;

	ptr->next = tmp->next;
	exp = ptr->prev;
	ptr->prev = tmp;
	tmp->next = ptr;
	tmp->prev = exp;

	if (tmp->prev)
		tmp->prev->next = tmp;


	if (ptr->next)
		ptr->next->prev = ptr;

	*node = tmp;

}
/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 *
 * @list: head of Double Linked List
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			c++;
			head = head->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			c--;
			head = head->prev;
		}
	}
}
