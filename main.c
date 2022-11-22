#include "main.h"

/**
 * main - driver program for simple super shell
 * @argc: number of args passed to programm
 * @argv: array of args to programm
 * @env: array of environmet variables
 *
 * Return: 0 sucess
 */
int main(__attribute__((unused))int argc,
		__attribute__((unused)) char **argv, char **env)
{
	int status;
	char *lineptr;
	char *new_argv[2];
	size_t lineLen, nread;

	lineptr = NULL;
	lineLen = 0;
	new_argv[0] = NULL;

	printf("#mySimpleShell$: ");

	while ((nread = getline(&lineptr, &lineLen, stdin)))
	{
		/**
		 * the getline() function returns the entire line from
		 * a stream including the new line character '\n' if one was found
		 * this new line character when included in a file pathname
		 * leads to invalid pathname - hence the new line char
		 * would be removed before passing the pathname to execve() function
		 */
		remove_new_line(&lineptr, nread);

		new_argv[0] = lineptr;
		new_argv[1] = NULL;

		status = 0;

		if (fork() == 0)
		{
			if (execve(new_argv[0], new_argv, env) == -1)
				perror(new_argv[0]);

			exit(0);
		}

		wait(&status);
		printf("#mySimpleShell$: ");
	}
	fflush(stdout);
	return (0);
}

