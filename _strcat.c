#include "main.h"

/**
 * _strcat - concat two strings
 * @dest: destination string
 * @src: src string
 *
 * Return: result of dest + src
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	char *str;

	while (dest[++i] != '\0')
		;

	while (src[++j] != '\0')
		;

	i++;

	str = malloc((i + j) * sizeof(char));

	for (i = 0; dest[i] != '\0'; i++)
		str[i] = dest[i];

	for (j = 0; src[j] != '\0'; i++, j++)
		str[i] = src[j];

	str[i] = '\0';

	return (str);
}
