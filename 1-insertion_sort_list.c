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
	listint_t *temp, *curr_node, *temp1;

	if (*list == NULL || (*list)->next == NULL || list == NULL)
		return;
	temp = (*list)->next;
	curr_node = (*list)->next;
	while (temp)
	{
		temp = temp->next;
		while (curr_node->prev != NULL && ((curr_node->n) < (curr_node->prev->n)))
		{
			temp1 = curr_node->next;
			curr_node->next = curr_node->prev;
			curr_node->prev = curr_node->next->prev;
			curr_node->next->next = temp1;
			curr_node->next->prev = curr_node;
			if (curr_node->next->next != NULL)
				curr_node->next->next->prev = curr_node->next;
			if (curr_node->prev == NULL)
				*list = curr_node;
			else
				curr_node->prev->next = curr_node;
			print_list(*list);
		}
		curr_node = temp;
	}
}
