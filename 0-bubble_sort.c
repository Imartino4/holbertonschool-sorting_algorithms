#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using Bubble sort algorithm
 * @array: array to be sorted
 * @size: array's size
 */

void bubble_sort(int *array, size_t size)
{
	int i = 0, j = 0, aux = 0;

	for (j = 0; j < (int)size; j++)
	{
		i = 0;
		while (i < (int)size - 1)
		{
			aux = array[i];
			if (array[i] > array[i + 1])
			{
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
				i++;
				continue;
			}
			i++;
		}
	}
}
