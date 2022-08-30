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

void quicks(int *array, int min, int max, size_t size)
{
	int index = 0;
/*Caso base cuando hay un único elemento -> min == max*/
	while (min < max)
	{
		index = lomuto_partition(array, min, max, size);
		quicks(array, min, index - 1, size);
		quicks(array, index + 1, max, size);
	}
}

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
				printf("pivot = %d\n", pivot);
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
	print_array(array, size);
	return (i + 1);
}
