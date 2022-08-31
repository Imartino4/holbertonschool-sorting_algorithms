#include "sort.h"

/**
 * quick_sort - implementing Lomuto partition scheme Quicksort algorithm
 * @array: arrey to be sorted
 * @size: array's size
 */
void quick_sort(int *array, size_t size)
{
	quicks(array, 0, size - 1, size);
}

/**
 * quicks - auxiliar function to make recursion
 * @array: array to be sorted
 * @min: min index of the subarray
 * @max: max indec of the subarray
 * @size: array's size
 */
void quicks(int *array, int min, int max, size_t size)
{
	int index = 0;
/*Caso base cuando hay un único elemento -> min == max*/
	if (min < max)
	{
		index = lomuto_partition(array, min, max, size);
		quicks(array, min, index - 1, size);
		quicks(array, index + 1, max, size);
	}
}

/**
 * lomuto_partition - implementation of lomuto algorithm to partionate an array
 * @array: array to be partionated
 * @min: min index of the subarray
 * @max: max indec of the subarray
 * @size: array's size
 * Return: index of partition
 */
int lomuto_partition(int *array, int min, int max, size_t size)
{
	int pivot = array[max], i = min - 1, j = min, temp = 0;

	while (j < max)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i < j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
		j++;
	}
	temp = array[max];
	array[max] = array[i + 1];
	array[i + 1] = temp;
	if (array[i] != array[max] /*Cuando queda partido por un elemento*/
		print_array(array, size);
	return (i + 1);
}
