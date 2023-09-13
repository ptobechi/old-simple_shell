#include <stdio.h>
#include <stdlib.h>

char *getenv_val(char *env, const char *name)
{
	int i = 0, j = 0;
	char *val;

	while (name[++i] != '\0');
	while (env[++j] != '\0');

	val = malloc((j - i) * sizeof(char));
	if (val == NULL)
		return (NULL);

	j = 0;
	while (env[i++] != '\0')
		val[j++] = env[i];

	val[j] = '\0';
	return (val);
}
