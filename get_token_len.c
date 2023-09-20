#include "main.h"

/**
 * get_token_len - count length of token
 * @str: string
 * @delim: delimiter
 *
 * Return: Always 0 (Success)
 */
int get_token_len(char *str, char delim)
{
	int i, j, count = 1;

	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		if (*str == delim)
			count++;
		str++;
	}
	return (count);
}
int main(void)
{
	int res;
	res = get_token_len("Hello How are u World", ' ');

	printf("%d\n", res);
	return (0);
}
