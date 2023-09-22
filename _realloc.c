#include "main.h"

/**
 * _memset- resets memory bytes to constant
 * @str: string of null term char
 * @_char: char
 * @n: unsigned int
 *
 * Return: bytes char
 */
char *_memset(char *str, char _char, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		str[i] = _char;

	return (str);
}

/**
 * _memcpy - copy mem area
 * @dest: destination buffer
 * @src: source buffer
 * @bytes: number of copied bytes
 *
 * Return: a pointer to the copied buffer (dest address)
 */
char *_memcpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes && src[i] != '\0'; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _realloc - resize memory allocation
 * @ptr: buffer src to resize
 * @size: new buffer size
 *
 * Description: creates a new memory location with size and
 * copies the content from prev mem to new before freeing it.
 *
 * Return: void
*/
void *_realloc(void *ptr, size_t size)
{
	void *new;

	if (ptr == NULL)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(size);
	if (new == NULL)
		return (NULL);

	/** garbage values reset */
	_memset(new, 0, size);
	_memcpy(new, ptr, size);

	free(ptr);
	return (new);
}

