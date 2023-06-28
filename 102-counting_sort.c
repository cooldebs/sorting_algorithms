#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int mx, j;

	for (mx = array[0], j = 1; j < size; j++)
	{
		if (array[j] > mx)
			mx = array[j];
	}

	return (mx);
}

/**
 * counting_sort - Sort an array of integers in ascending order.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, mx, i;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	mx = get_max(array, size);
	count = malloc(sizeof(int) * (mx + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < (mx + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (mx + 1); i++)
		count[i] += count[i - 1];
	print_array(count, mx + 1);

	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
