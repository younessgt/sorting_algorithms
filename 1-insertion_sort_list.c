#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 * @list: doubly linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *temp1;
	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev != NULL && ((temp->n) < (temp->prev->n)))
		{
			temp1 = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->next = temp1;
			temp->next->prev = temp;
			temp = temp->prev;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
