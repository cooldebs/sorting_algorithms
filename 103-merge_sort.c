#include "sort.h"

/**
 * print_left_right - print left and right partitions
 * @array: array of integers
 * @size: size of second array
 * @first: initial position
 * @mid: middle position
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int n;

	printf("Merging...\n");
	printf("[left]: ");
	n = first;
	while (n < mid)
	{
		if (n != mid - 1)
			printf("%d, ", array[n]);
		else
			printf("%d\n", array[n]);
		n++;
	}

	printf("[right]: ");
	n = mid;
	while (n < size)
	{
		if (n < size - 1)
			printf("%d, ", array[n]);
		else
			printf("%d\n", array[n]);
		n++;
	}
}

/**
 * merge - merge the values
 * @array: first array
 * @size: size of second array
 * @ptr: copy of array
 * @first: initial position
 * @mid: middle position
 * first one of the second array
 */
void merge(int *array, int size, int first, int mid, int *ptr)
{
	int i, j, n;

	print_left_right(array, size, first, mid);

	i = first;
	j = mid;

	printf("[Done]: ");
	n = first;
	while (n < size)
	{
		if (i < mid && (j >= size || array[i] <= array[j]))
		{
			ptr[n] = array[i];
			i++;
		}
		else
		{
			ptr[n] = array[j];
			j++;
		}
		if (n < size - 1)
			printf("%d, ", ptr[n]);
		else
			printf("%d\n", ptr[n]);
		n++;
	}
}
/**
 * mergeSort - sorts the merged array
 * @ptr: copy of array
 * @first: initial position
 * @size: size of the original  array
 * @array: the original array
 */
void mergeSort(int *ptr, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;

	mid = (size + first) / 2;

	mergeSort(array, first, mid, ptr);
	mergeSort(array, mid, size, ptr);

	merge(ptr, size, first, mid, array);
}
/**
 * copy_array - copies array
 * @arr: array source
 * @ptr: array dest
 * @size : array size
 */
void copy_array(int *arr, int *ptr, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		ptr[i] = arr[i];
}

/**
 * merge_sort - create partition and copy
 * @array: array
 * @size : array size
 */
void merge_sort(int *array, size_t size)
{
	int *ptr;

	ptr = malloc(sizeof(int) * size - 1);

	if (ptr == NULL)
		return;

	copy_array(array, ptr, size);

	mergeSort(ptr, 0, size, array);
	free(ptr);
}
