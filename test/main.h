#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * Contributors: Tobechukwu Paschal, Pious Tenya
 *
 * file: main.h
 *
 * description: function protype for a basic simple shell project
*/
int get_token_len(cahr *lineptr, char *delim);
#endif /** MAIN_H */
