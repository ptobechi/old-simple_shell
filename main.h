#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif /** MAIN_H */

#ifndef PATH_LIST
#define PATH_LIST
typedef struct path_list
{
	char *path;
	struct path_list *next;
} p_ll;
#endif

/**
 * Contributors: Tobechukwu Paschal, Pious Tenya
 *
 * file: main.h
 *
 * description: function protype for a basic simple shell project
*/

#ifndef ENVIRON
#define ENVIRON
extern char **environ;
#endif

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

#ifndef _STRCCMP
#define _STRCCMP
int _strccmp(const char *s1, const char *s2, char c);
#endif

#ifndef _GETENV
#define _GETENV
char *_getenv(const char *name);
#endif

#ifndef _GETENV_VAL
#define _GETENV_VAL
char *_getenv_val(char *env, const char *name);
#endif

#ifndef _FIND_FILE
#define _FIND_FILE
int find_file(char *file_path);
#endif

#ifndef _APPEND_NODE
#define _APPEND_NODE
p_ll *append_node(p_ll *head, char *path);
#endif

#ifndef _CREATE_P_LL
#define _CREATE_P_LL
p_ll *_create_p_ll(void);
#endif

#ifndef _STRCAT
#define _STRCAT
char *_strcat(char *dest, char *src);
#endif

#ifndef _FIND_CMD_FULL_PATH
#define _FIND_CMD_FULL_PATH
char *find_cmd_full_path(char *cmd);
#endif

#ifndef _GET_CMD_PATH
#define _GET_CMD_PATH
char *get_cmd_path(char *cmd);
#endif

#ifndef _RUN_CMD
#define _RUN_CMD
void run_cmd(char *path, char **_argv);
#endif

