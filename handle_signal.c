#include "main.h"

/**
 * handle_signal - handle ctrl c
 * @signum: signal number
 *
 * Return: void
 */
void handle_signal(int signum)
{
	write(STDOUT_FILENO, "\n$ ", 3);
	if (sigint == 2)
	{
		errno = 130;
	}
}

