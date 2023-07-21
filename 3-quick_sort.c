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
 * partition - recursive function that use a pivot to sort an array
 * @low: indice to begin with
 * @high: indice to end with
 * @size: size of the array
 * Return: pivot indice
 */
void partition(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot;

	pivot = array[high];
	j = low;
	if (low > high)
		return;

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
	partition(array, low, j - 1, size);
	partition(array, j + 1, high, size);
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
	partition(array, 0, size - 1, size);
}
