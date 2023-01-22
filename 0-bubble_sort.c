#include "sort.h"
/**
 * bubbl_sort - Function that sorts an array of integers
 * using the bubble sorting algorithm
 *
 * @array: array of int
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, k;

	if (!array || !size)
		return;

	i = 0;
	while (i < size)
	{
		for (k = 0; k < size - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
