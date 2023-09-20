#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
char **_create_cmd_table(char *tokens, char *delim);
extern char *lineptr;
extern char **environ;
#endif /** MAIN_H */

#ifndef _PRINT_ENV
#define _PRINT_ENV
void _printenv(void);
int exit_shell(int argc, char **argv, char **envp);
#endif

#ifndef PATH_LIST
#define PATH_LIST
/**
 * struct path_list - path linked list
 * @path: cmd path
 * @next: points to the next node
 *
 * Description: linked list node structure
 */
typedef struct path_list
{
	char *path;
	struct path_list *next;
} p_ll;
#endif

#ifndef _FREE_LINKED_LIST
#define _FREE_LINKED_LIST
void _free_linked_list(p_ll *head);
#endif

#ifndef ENVIRON
#define ENVIRON
extern char **environ;
#endif

#ifndef GET_TOKEN_LEN
#define GET_TOKEN_LEN
int get_token_len(char *str, char *delim);
#endif

#ifndef _STRDUP
#define _STRDUP
char *_strdup(char *s);
#endif

#ifndef _FREE_2D_ARRAY
#define _FREE_2D_ARRAY
void free_2d_array(char **_arr);
#endif

#ifndef _STRNDUP
#define _STRNDUP
char *_strndup(char *s, int start, int end);
#endif

#ifndef _GET_TOKENS_POSITIONS
#define _GET_TOKENS_POSITIONS
int *get_tokens_positions(char *str, char *delim);
#endif

#ifndef _GET_TOKENS
#define _GET_TOKENS
/*char **_strtok(char *str, char delim);*/
#endif

#ifndef _GET_LINE
#define _GET_LINE
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif

#ifndef REMOVE_NEWLINE_CHAR
#define REMOVE_NEWLINE_CHAR
char *remove_newline_char(char *s);
#endif

#ifndef CREATE_CMD_TABLE
#define CREATE_CMD_TABLE
char **create_cmd_table(char *, char);
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
p_ll *create_path_ll(void);
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
void run_cmd(char **_argv);
#endif

#ifndef HANDLE_SIGNAL_H
#define HANDLE_SIGNAL_H
void handle_signal(int signum);
#endif
