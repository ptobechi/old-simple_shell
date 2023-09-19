#include "main.h"

/**
 * handle_signal - handle ctrl c
 * @signum: signal number
 *
 * Return: void
 */
void handle_signal(int signum)
{
	printf("exiting now...\n");
	exit(signum);
}
