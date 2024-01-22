#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

int main(void);
/* Print functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* Mandatory Tasks*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void nodes_swap(listint_t **list, listint_t *node1, listint_t *node2);
void selection_sort(int *array, size_t size);
void qSort(int *array, int low, int high, size_t size);
int lom_partition(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/* Advanced Tasks */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void bitonic_sort_seq(int arr[], int size, int elem, int seq, int low);
void bitonic_sort(int *array, size_t size);
void join(int arr[], int elem, int low, int seq);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */