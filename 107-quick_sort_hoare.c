#include "sort.h"

/**
 * swap_ints - Swaps first and second integers
 * @x: The first integer
 * @y: The second integer
 * @array: The list of integers
 */
void swap_ints(int *array, ssize_t x, ssize_t y)
{
	int temp;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

/**
 * partition_hoare - partitions an array of integers in ascending
 * @array: The array to be sorted
 * @dwn: The starting index of the partition to be sorted
 * @up: The ending index of the partition to be sorted
 * @size: The size of the array
 * Return: The index of the pivot element
*/
int partition_hoare(int *array, int dwn, int up, size_t size)
{
	int pvt = array[up], i = dwn - 1, j = up + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pvt);
		do {
			j--;
		} while (array[j] > pvt);
		if (i >= j)
			return (i);

		swap_ints(array, i, j);
		print_array(array, size);
	}
}

/**
 * q_Sort_hoare - sorts array of ints in ascending order
 * @array: The array of elements to be sorted
 * @up: Starting index of partition to be sorted
 * @dwn: Size of array
 * @size: The size of the array
 */
void q_Sort_hoare(int *array, ssize_t dwn, ssize_t up, int size)
{
	ssize_t prt = 0;

	if (dwn < up)
	{
		prt = partition_hoare(array, dwn, up, size);
		q_Sort_hoare(array, dwn, prt - 1, size);
		q_Sort_hoare(array, prt, up, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_Sort_hoare(array, 0, size - 1, size);
}
