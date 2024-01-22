#include "sort.h"

/**
 * swap - swaps a node with a previous one
 * @list: A double-pointer to doubly-linked list head
 * @node1: the first node to swap
 * @node2: the second node to swap
 * Return: a pointer to the inserted node
*/
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: The linked list of integers
 * Return: The sorted doubly linked list of integers
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	char swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap(list, temp, temp->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap(list, temp->prev, temp);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				temp = temp->prev;
		}
	}
}
