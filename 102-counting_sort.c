#include "sort.h"

/**
 * integer_count - Number of mode of indivdual
 * integers in an array.
 *
 * @array: array to be sorted.
 * @size: size of array given.
 * @range: number of check for occurance.
 *
 * Return: number of occurence.
 */
int integer_count(int *array, size_t size, int range)
{
	int total = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == range)
			total++;
	}
	return (total);

}

/**
 * count_sort - This fuction sorts a array using the
 * count sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array being counted.
 */
void counting_sort(int *array, size_t size)
{
	int k = 0, b = 0, r = 0;
	size_t i, c;
	int *array2, *newArray;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	array2 = malloc(sizeof(int) * (k + 1));
	if (!array)
		return;
	for (c = 0; c < ((size_t)k + 1); c++)
	{
		if (c == 0)
			array2[c] = integer_count(array, size, r);
		else
		{
			b = array2[c - 1] + integer_count(array, size, r);
			array2[c] = b;
		}
		r++;
	}
	print_array(array2, (k + 1));
	newArray = malloc(sizeof(int) * size);
	if (!newArray)
	{
		free(array2);
		return;
	}
	for (i = 0; i < size; i++)
		newArray[array2[array[i]]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = newArray[i];
	free(newArray);
	free(newArray);
}
