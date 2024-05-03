#include "sort.h"

/**
 * insert_node - A function to insert a node at
 * the appropraite position in a doubly linked
 * list
 *
 * @list: The doubly linked list representing the list
 * @node: The node we want to insert
 */

void insert_node(listint_t **list, listint_t *node)
{
	listint_t *tp;

	while (node->prev != NULL && node->n < (node->prev)->n)
	{
		tp = node->prev;

		if ((node->prev)->prev != NULL)
		{
			((node->prev)->prev)->next = node;
			node->prev = (node->prev)->prev;
		}
		else
		{
			node->prev = NULL;
			*list = node;
		}
		if (node->next)
		{
			(node->next)->prev = tp;
			tp->next = node->next;
		}
		else
		{
			tp->next = NULL;
		}
		node->next = tp;
		tp->prev = node;
		print_list(*list);
	}
}

/**
 * insertion_sort_list - An implementation of the insertion sorting algorithm
 *
 * @list: A singly linked list of the array to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *mov;
	listint_t *nex;
	listint_t *sorted_tail;

	if (!list || !*list)
		return;
	sorted_tail = *list;
	mov = sorted_tail->nex;
	while (mov)
	{
		nex = mov->nex;
		insert_node(list, mov);
		mov = nex;
	}
}
