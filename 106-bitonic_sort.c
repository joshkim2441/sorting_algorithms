#include "sort.h"

/**
 * swap_ints - Swaps two array integers
 * @x: The first integer to swap
 * @y: The second integer to swap
 * @arr: The array of integers
 * @seq: Descending seq: 0, ascending seq: 1
*/
void swap_ints(int arr[], int x, int y, int seq)
{
	int temp;

	if (seq == (arr[x] > arr[y]))
	{
		temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}
}

/**
 * join - recursively sorts bitonic sequences in both
 * @elem: the number of the element
 * @low: The first element
 * @arr: The integers array
 * @seq: Descending seq: 0, ascending seq: 1
*/
void join(int arr[], int low, int elem, int seq)
{
	int center, x;

	if (elem > 1)
	{
		center = elem / 2;
		for (x = low; x < low + center; x++)
			swap_ints(arr, x, x + center, seq);
		join(arr, low, center, seq);
		join(arr, low + center, center, seq);
	}
}

/**
 * bitonic_sort_seq - A helper funtion that sorts
 * a bitonic sequence in ascending order
 * @arr: The list of integers to be sorted
 * @size: The array size
 * @low: Starting index of the sequence to sort
 * @seq: The order of elements to sort
 * @elem: The number of elements
*/
void bitonic_sort_seq(int arr[], int low, int elem, int seq, int size)
{
	int center;

	if (elem > 1)
	{
		if (seq >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", elem, size);
			print_array(&arr[low], elem);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", elem, size);
			print_array(&arr[low], elem);
		}
		center = elem / 2;
		bitonic_sort_seq(arr, low, center, 1, size);
		bitonic_sort_seq(arr, low + center, center, 0, size);
		join(arr, low, elem, seq);
		if (seq <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", elem, size);
			print_array(&arr[low], elem);
		}
		if (seq >= 1)
		{
			printf("Result [%i/%i] (UP):\n", elem, size);
			print_array(&arr[low], elem);
		}
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using Bitonic sort algorithm
 * @array: the list of integers
 * @size: the size of the array
 * Return: the sorted list
*/
void bitonic_sort(int *array, size_t size)
{
	int seq = 1;

	if (!array || size < 2)
		return;

	bitonic_sort_seq(array, 0, size, seq, size);
}
