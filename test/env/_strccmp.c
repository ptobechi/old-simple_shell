#include <stdio.h>

int _strccmp(char *s1, const char *s2, char c)
{
	int i = 0;

	while (s1[i] != c)
	{
		if ((s1[i]) > (s2[i]))
			return ((s1[i]) - (s2[i]));
		if ((s1[i]) < (s2[i]))
			return ((s1[i]) - (s2[i]));
		i++;
	}
	return (0);
}
