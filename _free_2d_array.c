#include "main.h"

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
