#include "main.h"

void handle_signal(int signum)
{
	printf("ctrl+c received");

	exit(signum);
}
