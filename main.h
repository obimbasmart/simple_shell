#ifndef main_h
#define main_h

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int extern errno;


char **split_string(char *, char *);
void remove_new_line(char **, size_t);

#endif /* end of main_h */
