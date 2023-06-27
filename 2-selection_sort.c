#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx == i)
			continue;
		tmp = array[min_idx];
		array[min_idx] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
