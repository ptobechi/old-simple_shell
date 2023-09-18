#include "main.h"

char *_strndup(char *s, int start, int end)
{
	char *s_dup;
	int i = 0;

	while (s[++i] != '\0');

	if (start > i || end > i || start >= end)
		return (NULL);

	i = (end + 2) - start;

	s_dup = malloc(i * sizeof(char));
	if (s_dup == NULL)
		return (NULL);

	for (i = 0; start <= end; i++, start++)
		s_dup[i] = s[start];

	s_dup[i] = '\0';

	return (s_dup);
}
