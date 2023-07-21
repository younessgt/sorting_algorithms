#include <stdio.h>
#include "sort.h"
/**
 * selection_sort - function that sort an array using Selection algo
 * @array: array to sort
 * @size: size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int temp1;

	if (size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[idx] > array[j])
			{
				idx = j;
			}
		}
		if (idx != i)
		{
			temp1 = array[idx];
			array[idx] = array[i];
			array[i] = temp1;
			print_array(array, size);
		}
	}
}
