#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

typedef struct node
{
	char *data;
	struct node *next;
} node;

struct

node *append_node(char *data, node *next)
{
	node node;

	node->data = data;
	node->next = NULL;

	return (node);
}

int main(void)
{
	char *val, *token, *delim = ":";	

	create_node("data",	



	val = _getenv("PATH");

	do {
		token = strtok(val, delim);
		if (token != NULL)
			printf("%s\n", token);
		if (val != NULL)
			free(val);
		val = NULL;
	} while (token != NULL);

	free(val);

	return (0);
}
