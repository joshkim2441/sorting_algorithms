#include "sort.h"
/**
 * merge_s - merges l and r arrays into original array
 * @array: pointer to array
 * @size: size of the array
 * @l: pointer to left array
 * @r: pointer to right array
 **/
void merge_s(int *array, int *lt, int *rt, size_t size)
{
	int a = 0, b = 0, c = 0;
	int size_lt, size_rt;

	size_lt = size / 2;
	size_rt = size - size_lt;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(lt, size_lt);
	printf("[right]: ");
	print_array(rt, size_rt);

	while (a < size_lt && b < size_rt)
	{
		if (lt[a] < rt[b])
			array[c++] = lt[a++];
		else
			array[c++] = rt[b++];
	}

	while (a < size_lt)
		array[c++] = lt[a++];

	while (b < size_rt)
		array[c++] = rt[b++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t cen = 0, i;
	int lt[1000];
	int rt[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	cen = size / 2;
	/*left = (int*)malloc(sizeof(int) * mid);*/
	/*right = (int*)malloc(sizeof(int) * (size - mid));*/

	for (i = 0; i < cen; i++)
		lt[i] = array[i];

	for (i = cen; i < size; i++)
		rt[i - cen] = array[i];

	merge_sort(lt, cen);
	merge_sort(rt, size - cen);
	merge_s(array, lt, rt, size);
}

