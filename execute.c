#include "main.h"

/**
 * _execute - function executes a program passed as arg
 * @argv: array of args to program
 * @env: array of environmet variables
 *
 * Return: 0 sucess
 */
int _execute(char **argv, char **env)
{
	int status;

	if (strcmp(argv[0], "exit") == 0)
		return (0);

	status = 0;
	if (fork() == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			perror(argv[0]);

		exit(0);
	}

	wait(&status);

	return (0);
}

