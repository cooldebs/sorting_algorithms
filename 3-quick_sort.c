#include "sort.h"

/**
 * swap - swaps two integers
 * @first: first integer
 * @second: second integer
 *
 * Return: void
 */
void swap(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

/**
 * partition - partitions an array seperate by pivot
 * @array: the given array
 * @low: the lowest value of the array
 * @high: the highest value of the array
 * @size: the size of the array
 *
 * Return: the pivot position as integer
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = high;
	int i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * quick_sort_lumoto - sorts recursively an array of integer
 * @array: the given array of integer
 * @low: the lowest value of the array
 * @high: the highest value of the array
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_lumoto(int *array, int low, int high, size_t size)
{
	int prt;

	if (low < high)
	{
		prt = partition(array, low, high, size);
		quick_sort_lumoto(array, low, prt - 1, size);
		quick_sort_lumoto(array, prt + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers
 * @array: the given array of integers
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_sort_lumoto(array, 0, size - 1, size);
}
