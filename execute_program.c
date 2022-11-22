#include "main.h"

/**
 * _execute - function executes a program passed as arg
 * @new_argv: array of args to program
 * @env: array of environmet variables
 *
 * Return: 0 sucess
 */
int _execute(char **new_argv, char **env)
{
	int status;

	status = 0;
	if (fork() == 0)
	{
		if (execve(new_argv[0], new_argv, env) == -1)
			perror(new_argv[0]);

		exit(0);
	}

	wait(&status);

	return (0);
}

