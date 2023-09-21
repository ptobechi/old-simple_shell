#include "main.h"

/**
 * _free_linked_list - free linked list
 * @head: list head
 *
 * Return: void
 */
void _free_linked_list(p_ll *head)
{
	p_ll *temp = head;

	while (temp != NULL)
	{
		p_ll *next = temp->next;

		free(temp->path);
		free(temp);
		temp = next;
	}
}

