#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: array of integers
 * @size: number of elements in array
 *
 */

void bubble_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t i, j;

	if (!array || size == 0)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
