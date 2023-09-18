#include "main.h"

/**
 * _strdup - dub
 * @s: string
 *
 * Return: Always 0
 */
char *_strdup(char *s)
{
	char *s_dup;
	int i = 0;

	while (s[i++] != '\0')
		;

	s_dup = malloc(i * sizeof(char));
	if (s_dup == NULL)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		s_dup[i] = s[i];

	s_dup[i] = '\0';

	return (s_dup);
}
