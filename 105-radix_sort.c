#include "sort.h"

int fetch_max(int *array, int size);
void counting_rdx_sort(int *array, size_t size, int sig_dig, int *bff);
void radix_sort(int *array, size_t size);

/**
 * fetch_max - Fetches the max val in an integers array
 * @array: The list of integers
 * @size: The array size
 * Return: The integer max in the array
 */
int fetch_max(int *array, int size)
{
	int val, x;

	for (val = array[0], x = 1; x < size; x++)
	{
		if (array[x] > val)
			val = array[x];
	}
	return (val);
}

/**
  * counting_rdx_sort - Helper function to sort significant digits of an
  * array of integers in ascending order using counting sort algorithm
  * @array: The list of integers
  * @size: The array size
  * @sig_dig: The digit significant to sort
  * @bff: The buffer for storing the sorted array
  */
void counting_rdx_sort(int *array, size_t size, int sig_dig, int *bff)
{
	int list[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
		list[(array[a] / sig_dig) % 10] += 1;

	for (a = 0; a < 10; a++)
		list[a] += list[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		bff[list[(array[a] / sig_dig) % 10] - 1] = array[a];
		list[(array[a] / sig_dig) % 10] -= 1;
	}
	for (a = 0; a < size; a++)
		array[a] = bff[a];
}

/**
 * radix_sort - Sorts an array of inteers in ascending order using
 * the Radix sort algorithm
 * @array: The array of integers
 * @size: The array size
 * Description: Prints array after each significant digit increase
 * implementing the LSD radix sort algorithm
 */
void radix_sort(int *array, size_t size)
{
	int val, sig_dig, *bff;

	if (!array || size < 2)
		return;

	bff = malloc(sizeof(int) * size);
	if (!bff)
		return;

	val = fetch_max(array, size);
	for (sig_dig = 1; val / sig_dig > 0; sig_dig *= 10)
	{
		counting_rdx_sort(array, size, sig_dig, bff);
		print_array(array, size);
	}

	free(bff);
}
