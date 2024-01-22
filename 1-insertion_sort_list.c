#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 * @list: The doubly-linked list to be sorted
 * Return: The sorted list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (*list == NULL || (*list)->next == NULL)
	{ /*List is empty or has only one element, no sorting needed*/
		return;
	}

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		/*Insert current node in its sorted position*/
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			swap_nodes(list, curr->prev, curr);
			print_list(*list); /*Print list after each swap*/
		}
	}
}

/**
 * nodes_swap - A helper function to swap two nodes in the list
 * @node1: Node to swap with node2
 * @node2: Node to swap with node1
 * @list: The node list
 * Return: A pointer to the node inserted
*/
void nodes_swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
	{
		return;
	}

	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}

	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
