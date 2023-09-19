#include <stdio.h>
#include <unistd.h>
#include "main.h"

char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	char *val = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strccmp(environ[i], name, '=') == 0)
		{
			while (name[++j] != '\0');
			while (environ[i][++k] != '\0');

			val = malloc((k - j) * sizeof(char));
			if (val == NULL)
				return (NULL);

			for (k = 0, j++; environ[i][j] != '\0'; j++, k++)
				val[k] = environ[i][j];

			val[k] = '\0';
			break;
		}
	}
	return (val);
}