#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: The list of integers to sort
 * @size: The size of the array
 * Return: The sorted list
*/
void shell_sort(int *array, size_t size)
{
	size_t a, b, gap = 1;
	int temp;
	/*Generate largest Knuth seq num less than size*/
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	/*Start with largest gap and reduce the gap*/
	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			temp = array[a];
			for (b = a; b >= gap && array[b - gap] > temp; b -= gap)
			{
				array[b] = array[b - gap];
			}
			array[b] = temp;
		}
		print_array(array, size);
	/*Print the array each time gap is decreased*/
		gap /= 3;
	}
}
