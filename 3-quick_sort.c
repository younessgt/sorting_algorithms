#include "sort.h"
/**
 * swap - function that swap to element of an array
 * @hp: pointer to the first element to swap
 * @jp: pointer to the second element to wap with
 */
void swap(int *hp, int *jp)
{
	int temp;

	temp = *hp;
	*hp = *jp;
	*jp = temp;
}
/**
 * partition - function that use a pivot to sort an array
 * @low: indice to begin with
 * @high: indice to end with
 * @size: size of the array
 * Return: pivot indice
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot;

	pivot = array[high];
	j = low;

	for (i = low; i <= high - 1; i++)
	{
		if (array[i] < pivot)
		{
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != high)
	{
		swap(&array[j], &array[high]);
		print_array(array, size);
	}
	return (j);
}
/**
 * recursive - function that sort the left and right of the array
 * @low: the indice to begin with
 * @high: the indice to end with
 * @size: size of the array
 * Return: nothing
 */
void recursive(int *array, int low, int high, size_t size)
{
	int j;

	if (low < high)
	{
		j = partition(array, low, high, size);
		recursive(array, low, j - 1, size);
		recursive(array, j + 1, high, size);
	}
}
/**
 * quick_sort - function that sort an array usin quicksort algo
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	recursive(array, 0, size - 1, size);
}
