#include <stdio.h>

/**
 * _strccmp - compare two string up to a char in s1
 * @s1: string 1
 * @s2: string 2
 * @c: char to compare up to
 *
 * Return: 0 if equal, pos int if s1 > s2, neg int if s1 < s2
*/
int _strccmp(const char *s1, const char *s2, char c)
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
