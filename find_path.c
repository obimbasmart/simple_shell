#include "main.h"

/**
 * find_path - function looks for files in the current PATH
 * @cmd: command(filename, filepath)
 *
 * Return: full path to file (executable)
 */
char *find_path(char *cmd)
{
	char *pathstring = getenv("PATH");
	char *dir = strtok(pathstring, ":");

	while (dir != NULL)
	{
		char *pathbuffer = malloc(_strlen(dir) + _strlen(cmd) + 2);

		sprintf(pathbuffer, "%s/%s", dir, cmd);

		if (access(pathbuffer, X_OK) == 0)
		{
			return (pathbuffer);
		}
		dir = strtok(NULL, ":");

		free(pathbuffer);
	}
	return (NULL);
}
