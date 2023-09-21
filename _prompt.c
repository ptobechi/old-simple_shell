#include "main.h"

/**
 * _prompt - display prompt on terminal
 *
 * Return: void
 */
void _prompt(void)
{
	write(STDOUT_FILENO, "$\n", 1);
}
