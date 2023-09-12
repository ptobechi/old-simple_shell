#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
 * Contributors: Tobechukwu Paschal, Pious Tenya
 *
 * file: main.h
 *
 * description: function protype for a basic simple shell project
*/
int get_token_len(char *lineptr, char *delim);
char *_strdup(char *s);
#endif /** MAIN_H */
