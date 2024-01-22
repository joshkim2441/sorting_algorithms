#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using Bubble sort algorithm
 * @array: The list of elements
 * @size: The size of the array
 * Return: the printed array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y, tmp;

	for (x = 0; x < size; x++)
	{
		for (y = 1; y < size - x; y++)
		{
			if (array[y - 1] > array[y])
			{
				tmp = array[y];
				array[y] = array[y - 1];
				array[y - 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
