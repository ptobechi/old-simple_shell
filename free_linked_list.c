#include "main.h"

/**
 * _free_linked_list - free linked list
 * @head: list head
 *
 * Return: void
 */
void _free_linked_list(p_ll *head)
{
	p_ll *temp;

	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		free(temp->path);
		free(temp);
	}
}


