#ifndef main_h
#define main_h

/* standard libraries */
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>

/* global var */

/**
 * struct global_var - struct representatio of all global varas
 * @_isterminal: flag for terminal and non-terminal
 * @response: response from child program
 */
typedef struct global_var
{
	int _isterminal;
	int response;
} s_data_t;

/* declaration of global var */
extern s_data_t shell_data;

#define DELIM " \t\n\r\a\v"
extern int errno;


/* shell utils */
void handle_sigint(int);
size_t _puts(char *);
int _execute(char **, char **);
void _isatty(void);
/* char **tokenize(char *str); */
int f_exist(char *path);

#endif /* end of main_h */

