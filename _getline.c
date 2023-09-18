#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	size_t read_line = 0;
	int _char;

	if (*lineptr == NULL || *n == 0)
	{
		buffer_size = 128; /** SET BUFFER SIZE */
		buffer = (char *)malloc(buffer_size * sizeof(char)); /** mem alloc of 1024 */

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
		char *new_buffer;

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

		if (_char == '\0')
			break;
	}

	/** if no char is read and reach end of fle*/
	if (_char == EOF && read_line == 0)
		return (-1);

	return (read_line);
}

int main(int argc, char *argv[])
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	(void)argc;
	(void)argv;
	(void) nread;

	printf("Type someting: ");

	nread = _getline(&line, &len, stdin);
	printf("%s\n", line);
	printf("------------ %s:\n", "Line Two");

	free(line);
	return (0);
}
