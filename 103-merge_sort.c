#include "sort.h"
/**
 * merge_sort - function merge that divide an array into two sub-arrays
 * @array: array
 * @size: the size of the array
 * Return: void function
 */
void merge_sort(int *array, size_t size)
{
	size_t first;
	size_t i;
	size_t second;
	int *new;
	int *left;
	int *right;

	if (size <= 1)
		return;
	first = size / 2;
	second = size - first;
	left = array;
	right = array + first;

	for (i = 0; i < first; i++)
		left[i] = array[i];
	for (i = 0; i < second; i++)
		right[i] = array[first + i];
	merge_sort(left, first);
	merge_sort(right, second);
	new = malloc(size * sizeof(int));

	if (!new)
		exit(1);
	merge(new, left, first, right, second);
	for (i = 0; i < size; i++)
		array[i] = new[i];
	free(new);
}
/**
 * merge - function that sorts the left array and the right one
 * @array: the new array where to merge
 * @left: the left array being divided
 * @first: the size of the left array
 * @right: the rightt array being divided
 * @second: the size of the right array
 * Return: void function
 */
void merge(int *array, int *left, int first, int *right, int second)
{
	int k;
	int i = 0, j = 0;
	int size = first + second;

	printf("Merging...\n[left]: ");
	print_array(left, first);
	printf("[right]: ");
	print_array(right, second);
	for (k = 0; k < size; k++)
	{
		if (i < first && (j >= second || left[i] <= right[j]))
			array[k] = left[i++];
		else
			array[k] = right[j++];
	}
	printf("[Done]: ");
	print_array(array, size);
}
