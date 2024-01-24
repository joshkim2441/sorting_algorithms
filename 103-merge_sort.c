#include "sort.h"

/**
 *c_alloc -Ccontigiously allocates memory
 *@n_elm: The number of elements
 *@size: The bit-size of each element
 *Return: A pointer assigned to memory
 */
void *c_alloc(unsigned int n_elm, unsigned int size)
{
	unsigned int x = 0;
	char *bs;

	if (n_elm == 0 || size == 0)
		return ('\0');
	bs = malloc(n_elm * size);
	if (bs == '\0')
		return ('\0');
	for (x = 0; x < (n_elm * size); x++)
		bs[x] = '\0';
	return (bs);
}

/**
 *merge_s - Merges an array of integers
 *@arr: An array of indexes from start to mid
 *@temp: temp array created outside to
 *optimize reducing the system calls used in merge
 *@frt: The first element position
 *@cen: The middle of the array
 *@fin: The last element position
 **/
void merge_s(int *arr, int *temp, int frt, int cen, int fin)
{
	/* temp arrays and sizes */
	int size_lt = cen - frt + 1, size_rt = fin - cen;
	int *array_lt, *array_rt;
	/* function counters */
	int lt, rt, a = 0;

	array_lt = &temp[0];
	array_rt = &temp[size_rt];
	for (lt = 0; lt < size_lt; lt++)
		array_lt[lt] = arr[frt + lt];
	for (rt = 0; rt < size_rt; rt++)
		array_rt[rt] = arr[cen + 1 + rt];
	lt = 0, rt = 0, a = frt;
	/* merge the temp arrays into the main arrays*/
	while (lt < size_lt && rt < size_rt)
	{
		if (array_lt[lt] <= array_rt[rt])
			arr[a] = array_lt[lt], lt++;
		else
			arr[a] = array_rt[rt], rt++;
		a++;
	}
	/* merge the remainder of left array into the main array*/
	while (lt < size_lt)
		arr[a] = array_lt[lt], lt++, a++;
	/* merge the remainder right array into the main array*/
	while (rt < size_rt)
		arr[a] = array_rt[rt], rt++, a++;
	printf("Merging...\n");
	printf("[lt]: ");
	print_array(array_lt, lt);
	printf("[rt]: ");
	print_array(array_rt, rt);
	printf("[Done]: ");
	print_array(&arr[frt], lt + rt);
}

/**
 *m_sort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@array: an array of integers
 *@temp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@frt: the first element position
 *@fin: the last element position
 *Return: void
 */
void m_sort(int *array, int *temp, int frt, int fin)
{
	int fin;

	cen = (frt + fin) / 2;
	if ((frt + fin) % 2 == 0)
		cen--;
	if (cen >= frt)
	{
		m_sort(array, temp, frt, cen);
		m_sort(array, temp, mid + 1, fin);
		merge(array, temp, frt, cen, fin);
	}
}

/**
 *m_sort - the function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@size: the size of the list
 *@array: an array of integers
 *Return: void
 */
void m_sort(int *array, size_t size)
{
	int *tp;

	if (!array || size < 2)
		return;
	tmp = c_alloc(size, sizeof(int));
	m_sort(array, tmp, 0, size - 1);
	free(tp);
}
