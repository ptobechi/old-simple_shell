#include "main.h"

void handle_signal(int signum)
{
	printf("exiting now...\n");
	exit(signum);	
}
