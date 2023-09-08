#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry Point
 *
 * Return: Always 0 (Success)
*/
int main()
{
	char delimiter = ' ';
	char *original_string = "Hello New World";
	char *new_string = NULL;
	int count = 0;

	while (*original_string != '\0')
	{
		if (*original_string == delimiter)
			*orginal_string = NULL;

		new_string[count] = *original_string;
		original_string++;
	}

	printf("%s", new_string);
	return (0);
}
