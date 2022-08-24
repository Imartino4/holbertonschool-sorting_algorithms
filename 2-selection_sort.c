#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection sort alorithm
 * @array: array to be sorted
 * @size: array's size
 */
void selection_sort(int *array, size_t size)
{
	size_t  i = 0, j = 0, j_aux = 0;
	int aux1 = 0, flag;

	while (i < size)
	{
		aux1 = array[i];
		j_aux = 0;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (aux1 > array[j])
			{
				aux1 = array[j]; 
				j_aux =  j;
				flag = 1;
			}
			if (j == size - 1 && flag == 1)
			{
				array[j_aux] = array[i];
				array[i] = aux1;
				print_array(array, size);
			}
		}
		i++;
	}
}
