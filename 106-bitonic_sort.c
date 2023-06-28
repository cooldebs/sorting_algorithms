#include "sort.h"

/**
 * comp_swap - change two values in ascending or descending order
 * @arr: array of integers
 * @i: first item
 * @j: second item
 * @order: 1: ascending order, 0 descending order
 */
void comp_swap(int arr[], int i, int j, int order)
{
	int tmp;

	if (order == (arr[i] > arr[j]))
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}
/**
 * bitonic_merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element
 * @exp: elements number
 * @order: 1: ascending order, 0 descending order
 */
void bitonic_merge(int arr[], int low, int exp, int order)
{
	int mid, i;

	if (exp > 1)
	{
		mid = exp / 2;
		for (i = low; i < low + mid; i++)
			comp_swap(arr, i, i + mid, order);
		bitonic_merge(arr, low, mid, order);
		bitonic_merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - implements the bitonic sort algorithm
 * @arr: array
 * @low: first element
 * @exp: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int exp, int order, int size)
{
	int mid;

	if (exp > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", exp, size);
			print_array(&arr[low], exp);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", exp, size);
			print_array(&arr[low], exp);
		}
		mid = exp / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		bitonic_merge(arr, low, exp, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", exp, size);
			print_array(&arr[low], exp);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", exp, size);
			print_array(&arr[low], exp);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
