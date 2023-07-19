#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


#define TOKEN_BUFFSIZE 64
#define BUFFER_SIZE 1024

/* builtins */
size_t _getline(char **buffer, size_t *n, FILE *);

/*builtin () prototypes*/
int my_cd(char **argv);
int my_exit(char **argv);

/* string functions*/
char *_strncopy(char *dest, char *origin, int n);
char *_strncat(char *dest, char *origin, int n);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);

char *find_path(char *cmd);
char *my_getline(void);
char *print_env(char **argv);

extern char **environ;

void *_realloc(void *ptr, unsigned int former_size, unsigned int current_size);
int init_process(char **argv);
int handle_cmd(char **argv);

/*functions in main*/
void myshell_loop(void);
char *get_line(void);
int _putchar(char *c);
char **tokenize_string(char *lineptr);
int execute_cmd(char **argv);

void free_tokens(char **toks);

/**
 * struct builtins - a struct reprenting a builtin function
 * @name: name of builtin
 * @func: function associated for each builtin
 */
typedef struct builtins
{
	char *name; /* name of builtin */

	int (*func)(char **argv); /* function pointer */

} builtin_t;

/*** utility functions ***/
int (*get_func(char *name))(char **argv);
#endif
