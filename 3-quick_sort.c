#include "sort.h"

/**
 * quick_sort - implementing Lomuto partition scheme Quicksort algorithm
 * @array: arrey to be sorted
 * @size: array's size
 */
void quick_sort(int *array, size_t size)
{
	int pivot = 0, aux2 = 0, flag = 0;
	size_t i = 0, j = 0;

	pivot = array[size - i];
	while(i < size)
	{
		j = 0;
		i = 0;
		while (j < size)
		{
			pivot = array[size - 1];
			if (array[j] < pivot)
			{
				i++;
				flag = 1;
			}
			if (array[j] > pivot && flag == 1)
			{
				aux2 = array[i];
				array[i] = array[j];
				array[j] = aux2;
				flag = 0;
				print_array(array, size);
			}
			j++;
			if (array[j] == array[size - 1] && flag == 0)
			{
				aux2 = array[i];
				array[i] = array[j];
				array[j] = aux2;
				print_array(array, size);
				i++;
			}
		}
	}
}
int lomuto_partion(int *array, int min, int max, size_t size)
{

