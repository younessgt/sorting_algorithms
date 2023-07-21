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
	size_t i, j, k;
	int temp1, temp2;

	k = 0;
	for (i = 0; i < size - 1; i++)
	{
		temp1 = array[i];
		temp2 = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (temp2 > array[j])
			{
				temp2 = array[j];
				k = j;
			}
		}
		if (k != i)
		{
			array[i] = temp2;
			array[k] = temp1;
			print_array(array, size);
		}
	}
}
