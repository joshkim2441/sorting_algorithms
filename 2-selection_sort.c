#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending
 * order using selection sort
 * @array: The array of integers
 * @size: The size of the array
 * Return: The sorted list
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_indx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_indx = i;
		/*Find the min element in unsorted array's port*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_indx])
			{
				min_indx = j;
			}
		}
		/*Swap the min element with the first unsorted port's element*/
		if (min_indx != i)
		{
			temp = array[i];
			array[i] = array[min_indx];
			array[min_indx] = temp;
			print_array(array, size); /*Print array after each swap*/
		}
	}
}
