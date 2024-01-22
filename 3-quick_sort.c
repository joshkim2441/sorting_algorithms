#include "sort.h"

/**
 * lom_partition - Implements the Lomuto partition scheme
 * @array: The list of integers to be sorted
 * @low: The array index that ends the partition
 * @high: The array index that starts the partition
 * @size: The size of the array
 * Return: A new index from which the recursive partition starts
 */
int lom_partition(int *array, int low, int high, size_t size)
{
	int b, tmp, a = low, pvt = array[high];

	for (b = low; b < high; b++)
	{
		if (array[b] < pvt)
		{
			tmp = array[a];
			array[a] = array[b];
			array[b] = tmp;
			if (array[a] != array[b])
				print_array(array, size); /*Print array after each swap*/
			a++;
		}
	}

	tmp = array[a];
	array[a] = array[high];
	array[high] = tmp;
	if (array[a] != array[high])
		print_array(array, size); /*Print array after each swap*/
	return (a);
}

/**
 * qSort - Sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: The array of integers to be partitioned
 * @high: The array index that starts the partition
 * @low: The array index that ends the partition
 * @size: The size of the array
*/
void qSort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lom_partition(array, low, high, size);

		qSort(array, low, pi - 1, size);
		qSort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: The list of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qSort(array, 0, (int)size - 1, size);
}
