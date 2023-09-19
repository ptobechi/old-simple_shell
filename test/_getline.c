#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _getline - reads input from a file stream
 * @lineptr: strings
 * @n: number of char read from stream
 * @stream: file pointer
 *
 * Return: Always 0 (Success)
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer = NULL, *new_buffer;
	size_t buffer_size = 1024;
	size_t read_line = 0;
	int _char;

	if (*lineptr == NULL || *n == 0)
	{
		buffer = (char *)malloc(buffer_size * sizeof(char));

		if (buffer == NULL)
			return (-1);

		*lineptr = buffer;
		*n = buffer_size;
	}
	else
	{
		buffer = *lineptr;
		buffer_size = *n;
	}

	while ((_char = fgetc(stream)) != EOF)
	{
		if (read_line >= buffer_size - 1)
		{
			/** double the buffer size */
			buffer_size *= 2;
			new_buffer = realloc(buffer, buffer_size);

			if (new_buffer == NULL)
				return (-1);

			buffer = new_buffer;
			*lineptr = buffer;
			*n = buffer_size;
		}
		buffer[read_line++] = (char)_char;

		if (_char == '\0' || _char == '\n')
			break;
	}

	/** if no char is read and reach end of fle*/
	if (_char == EOF && read_line == 0)
		return (-1);

	return (read_line);
}
