#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - helper function to swap integers
 * @x: integer x
 * @y: integer y
 **/
void swap_ints(int *x, int *y)
{
	int tp = *x;

	*x = *y;
	*y = tp;
}

/**
 * heapify_max - A helper function to heapify a Max Heap.
 * assumes everything under given root (element at index idx)
 * is already heapified
 * @array: array
 * @size: the array size for print
 * @ndx: index
 * @sz: the array size to run
 */
void heapify_max(int *array, size_t size, int ndx, size_t sz)
{
	int max = ndx;               /* Initializing largest as root*/
	int lt = 2 * ndx + 1; /* left = (ndx << 1) + 1*/
	int rt = 2 * ndx + 2; /* right = (ndx + 1) << 1*/

	/* Check if left child of root exists and greater than root*/
	if (lt < (int)sz && array[lt] > array[max])
		max = lt;

	/**
	 * Check if right child of root exists and greater than
	 * largest sp far
	 */
	if (rt < (int)sz && array[rt] > array[max])
		max = rt;

	/* Change root, if nessecary*/
	if (max != ndx)
	{
		swap_ints(&array[ndx], &array[max]);
		print_array(array, size);
		heapify_max(array, size, max, sz);
	}
}

/**
 * heap_sort - Main function that sorts an array of given size
 * using heap sort algorithm
 * @array: array of integers to sort
 * @size: the array size
 **/
void heap_sort(int *array, size_t size)
{
	int n;
	/**
	 * Start from lowest and rightmost internal mode to heapify all
	 * internal modes from bottom up
	 */
	if (!array || size < 2)
		return;

	for (n = (size - 2) / 2; n >= 0; --n)
		heapify_max(array, size, n, size);

	/**
	 * While heap size is greater than 1, repeat following steps.
	 * The minimum element will be the last element in max heap
	 */
	for (n = (size - 1); n > 0; --n)
	{
		/**
		 * Largest item in Heap is stored at the root. Replace
		 * with last item of the heap then reducing the
		 * heap size by 1.
		 */
		swap_ints(&array[0], &array[n]);
		print_array(array, size);

		/* Finally, heapify the tree root.*/
		heapify_max(array, size, 0, n);
	}
}
