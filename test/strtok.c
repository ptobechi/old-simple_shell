#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char *buffer;

	buffer = malloc(strlen(original_string) * sizeof(char));

	while (*original_string != '\0')
	{
		if (*original_string == delimiter)
			buffer[i] = '\0';
		else
			buffer[i] = *original_string;
		/**orginal_string = NULL; */
		/*new_string[count] = *original_string;*/
		original_string++;
	}

	printf("%s", new_string);
	return (0);
}
