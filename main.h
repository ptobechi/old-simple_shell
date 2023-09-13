#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#endif /** MAIN_H */

/**
 * Contributors: Tobechukwu Paschal, Pious Tenya
 *
 * file: main.h
 *
 * description: function protype for a basic simple shell project
*/

#ifndef GET_TOKEN_LEN
#define GET_TOKEN_LEN
int get_token_len(char *lineptr, char *delim);
#endif

#ifndef _STRDUP
#define _STRDUP
char *_strdup(char *s);
#endif

#ifndef REMOVE_NEWLINE_CHAR
#define REMOVE_NEWLINE_CHAR
char *remove_newline_char(char *s);
#endif

#ifndef CREATE_CMD_TABLE
#define CREATE_CMD_TABLE
char **create_cmd_table(char *);
#endif
