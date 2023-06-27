#include "sort.h"

int get_max(int *array, int size);
void radix_count_sort(int *array, size_t size, int exp, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - gets the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
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
 * radix_count_sort - sorts the digits of an array of integers
 * in ascending order.
 * @array: array of integers.
 * @size: size of the array.
 * @exp: significant digit to sort on.
 * @buff: buffer to store the sorted array.
 */
void radix_count_sort(int *array, size_t size, int exp, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int mx, exp, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	mx = get_max(array, size);
	for (exp = 1; mx / exp > 0; exp *= 10)
	{
		radix_count_sort(array, size, exp, buff);
		print_array(array, size);
	}

	free(buff);
}
