#include "sort.h"

void swap_int(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_int - swaps two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int flag;

	flag = *a;
	*a = *b;
	*b = flag;
}

/**
 * max_heapify - turns a binary tree into a complete binary heap.
 * @array: array of integers representing a binary tree.
 * @size: size of the array/tree.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, current;

	left = 2 * root + 1;
	right = 2 * root + 2;
	current = root;

	if (left < base && array[left] > array[current])
		current = left;
	if (right < base && array[right] > array[current])
		current = right;

	if (current != root)
	{
		swap_int(array + root, array + current);
		print_array(array, size);
		max_heapify(array, size, base, current);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
