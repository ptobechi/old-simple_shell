#include "main.h"

static char _buffer[BUFFER_SIZE];
static ssize_t buffer_index;

/**
 * _resize_getline - resize getline memory buffer
 * @lineptr: buffer
 * @bytes: total bytes
 * @new_size: new buffer memory realloc
 *
 * Return: Always (0) on success, -ENOMEM on failure
 */
int _resize_getline(char **lineptr, size_t *bytes, size_t new_size)
{
	/** reallocate memory size */
	char *newline = _realloc(*lineptr, new_size);

	if (newline == NULL)
	{
		free(*lineptr);
		return (-ENOMEM);
	}
	*lineptr = newline;
	*bytes = new_size;

	return (0);
}

/**
 * _getline - retrieves an entire line of text from stream
 * @lineptr: address of the buffer containing the text
 * @bytes: size in bytes
 * @stream: The text stream src
 *
 * Return: The amount of bytes read is returned on success,
 * on error or EOF -1 is returned
 */
ssize_t _getline(char **lineptr, size_t *bytes, FILE *stream)
{
	if (bytes == NULL || stream == NULL)
		return (-EINVAL);

	if (*lineptr == NULL || *bytes <= 0)
	{
		*bytes = BUFFER_SIZE;
		*lineptr = malloc(*bytes);
		if (*lineptr == NULL)
			return (-ENOMEM);

		_memset(*lineptr, 0, BUFFER_SIZE);
	}

	return (_readline(lineptr, bytes, stream->_fileno));
}

/**
 * _readline - reads a line from a stream and stores it into lineptr
 * @lineptr: pointer to where the read line will be stored
 * @bytes: size of allocated buffer
 * @fd: file descriptor for stream to read from
 *
 * Return: total amount bytes read on Success
 */
ssize_t _readline(char **lineptr, size_t *bytes, int fd)
{
	ssize_t read_bytes = 0;
	ssize_t total_bytes_read = 0;

	buffer_index = 0;

	while (1)
	{
		/*Check if buffer needs to be resized*/
		if (total_bytes_read >= (ssize_t)(*bytes - 1) &&
				_resize_getline(lineptr, bytes, (*bytes * 2)))
		{
			return (-1); /*Memory allocation Failed*/
		}

		/*If the buffer is empty fill it, and reset the index to 0*/
		if (buffer_index >= read_bytes)
		{
			read_bytes = read(fd, _buffer, BUFFER_SIZE);
			if (read_bytes <= 0)
				return ((total_bytes_read == 0) ? EOF : -1);
		}

		if (_buffer[buffer_index] == '\n')
		{
			/*Set Null Terminating character*/
			(*lineptr)[buffer_index] = '\0';
			/*Reset Buffer*/
			buffer_index = 0;
			_memset(_buffer, 0, BUFFER_SIZE);
			return (total_bytes_read + 1);
		}

		(*lineptr)[total_bytes_read++] = _buffer[buffer_index++];
	}
}
