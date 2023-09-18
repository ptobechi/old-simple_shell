#include "main.h"

/**
 * free_2d_array - free mem alloc of an array
 * @_arr: array of NULL terminated string
 *
 * Return: void
 */
void free_2d_array(char **_arr)
{
	int i = 0;

	while (_arr[i] != NULL)
	{
		free(_arr[i]);
		i++;
	}
	free(_arr);
}
