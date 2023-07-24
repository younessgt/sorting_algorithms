#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers usin Shell sort algo
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, right, left;
	int temp;

	if (array == NULL || size <= 1)
		return;

	interval = 1;
	while (interval < size / 3)
		interval = (interval * 3) + 1;

	while (interval > 0)
	{
		for (right = interval ; right < size; right++)
		{
			temp = array[right];
			left = right;

			while (left > interval - 1 &&
					(array[left - interval] > array[left]))
			{
				array[left] = array[left - interval];
				left -= interval;
				array[left] = temp;
			}
		}
		print_array(array, size);
		interval /= 3;
	}

}
