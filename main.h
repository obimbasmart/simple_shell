#ifndef main_h
#define main_h

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern int errno;

size_t _puts(char *);
int _execute(char **, char **);
char **tokenize(char *, char *);
#endif /* end of main_h */

