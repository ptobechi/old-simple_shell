#ifndef _MAIN_H
#define _MAIN_H

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 128

void error_msg(char **arr, char *path);
int _atoi(char *s);
const char *_str_chr(const char *str, char _char);
void _err_msg(char *a, char *b, char *c);
void err_msg(char *a, char *b, char *c);
char **_create_env_table(char **env);
int _file_input(char **argv, char **env);
void rm_trailing_space(char *s);
void _trim(char **str);
size_t _strlen(const char *str);
int _resize_getline(char **lineptr, size_t *bytes, size_t new_size);
ssize_t _readline(char **lineptr, size_t *bytes, int n);
ssize_t _getline(char **lineptr, size_t *bytes, FILE *stream);
char *_memset(char *str, char _char, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int bytes);
void *_realloc(void *ptr, size_t size);
void exec_shell(char **argv, char **envp, char **lineptr);
char **_create_cmd_table(char *tokens, char *delim);
extern char *lineptr;
extern char **environ;
#endif /** MAIN_H */

#ifndef _PRINT_ENV
#define _PRINT_ENV
void _printenv(char **env);
/*void _trim(char *str);*/
void _prompt(void);
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
char *_strtok(char *str, char *delim);
#endif

#ifndef _GET_LINE
#define _GET_LINE
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif

#ifndef REMOVE_NEWLINE_CHAR
#define REMOVE_NEWLINE_CHAR
char *remove_newline_char(char *s);
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
char *get_cmd_path(char *cmd, int *flag);
#endif

#ifndef _RUN_CMD
#define _RUN_CMD
void run_cmd(char **_argv, char **envp);
#endif

#ifndef HANDLE_SIGNAL_H
#define HANDLE_SIGNAL_H
void handle_signal(int signum);
#endif
