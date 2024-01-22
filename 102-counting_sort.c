#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: The list of integers to be sorted
 * @size: the numder of integers in the array
 * Return: The sorted list
*/
void counting_sort(int *array, size_t size)
{
	int *otpt, tot;
	int x, *arr_count, max;

	if (!array || size < 2)
		return;
	max = array[0];
	for (x = 0; x < (int)size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}
	arr_count = calloc(sizeof(int), (max + 1));
	if (!arr_count)
		return;
	for (x = 0; x < (int)size; x++)
		arr_count[array[x]]++;
	for (x = 0, tot = 0; x < max + 1; x++)
	{
		tot = arr_count[x] + tot;
		arr_count[x] = tot;
	}
	print_array(arr_count, max + 1);
	otpt = malloc(sizeof(int) * size);
	if (!otpt)
		return;
	for (x = 0; x < (int)size; x++)
	{
		otpt[arr_count[array[x]] - 1] = array[x];
		arr_count[array[x]]--; /* Handle the identiacal values */
	}
	for (x = 0; x < (int)size; x++)
		array[x] = otpt[x];
	free(arr_count);
	free(otpt);
}
