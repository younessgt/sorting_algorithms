#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - function that sort an array using bubble algo
 * @array: array to sort
 * @size: size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, tracker;
	int temp1;

	if (size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		tracker = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp1 = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp1;
				print_array(array, size);
				tracker = 1;

			}
		}
		if (tracker ==  0)
		{
			break;
		}
	}
}
