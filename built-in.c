#include "main.h"

/**
 * my_cd - changes the current working directory
 * @argv: command-line arguments passed to the program
 * Return: 1 on sucess
 */
int my_cd(char **argv)
{
	char *errstr = "tsh: expected argument to cd\n";

	if (argv[1] == NULL)
		write(STDERR_FILENO, errstr, _strlen(errstr));

	else
	{
		if (chdir(argv[1]) != 0)
			perror("tsh");
	}
	return (1);
}

/**
 * my_exit - exits the shell when the exit command is keyed
 * @argv: array of command-line arguments passed to the program
 * Return: 0 on success
 */
int my_exit(char **argv)
{
	if (argv[0])
	{
		/*in case first argument seeks to exit the shell*/
	}
	return (0);
}
