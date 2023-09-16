#include <stdio.h>
#include <unistd.h>
#include "main.h"

char *_getenv(const char *name)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (_strccmp(environ[i], name, '=') == 0)
			return (_getenv_val(environ[i], name));
		i++;
	}
	return (NULL);
}
