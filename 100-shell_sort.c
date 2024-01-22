#include "sort.h"

/**
 * swap_indx - Swaps into an array the positions of two elements
 * @array: the list of integers
 * @elem1: an element of the array
 * @elem2: an element of the array
*/
void swap_indx(int *array, int elem1, int elem2)
{
	int indx;

	indx = array[elem1];
	array[elem1] = array[elem2];
	array[elem2] = indx;
}

/**
 * shell_sort - Sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: The list of integers to sort
 * @size: The size of the array
 * Return: The sorted list
*/
void shell_sort(int *array, size_t size)
{
	size_t a, gap = 1, tmp = 0;

	if (!array || size < 2)
		return;
	/*Generate largest Knuth seq num less than size*/
	while (gap < size / 3)
	{
		gap = 3 * gap + 1;
	}
	/*Start with largest gap and reduce the gap*/
	while (gap >= 1)
	{
		for (a = gap; a < size; a++)
			for (tmp = a; tmp >= gap &&
			(array[tmp] > array[tmp - gap]); tmp -= gap)
				swap_indx(array, tmp, tmp - gap);
		print_array(array, size);
	/*Print the array each time gap is decreased*/
		gap /= 3;
	}
}
