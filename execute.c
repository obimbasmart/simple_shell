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
	pid_t child_pid;

	child_pid = fork();

	if (strcmp(argv[0], "exit") == 0)
		return (-1);

	status = 0;
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			perror(argv[0]);

		exit(0);
	}

	wait(&status);
	return (0);
}

