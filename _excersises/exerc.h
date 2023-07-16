#ifndef EXERC_H
#define EXERC_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* builtins */
#include <sys/wait.h>

/* macros */
#define TOKEN_BUFFSIZE 1024

int get_ppid();
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t _getline(char **buffer, size_t *n, FILE *stream);
char **tokenize_str(char *line);
void free_tokens(char **toks);
#endif
