#include "main.h"

/**
 * remove_new_line - removes new line char from a pathname
 * @pathname: pathname with trailing \n
 * @pathlength: length of pathname
 *
 * Return: nothing
 */
void remove_new_line(char **pathname, size_t pathlength)
{
	if ((*pathname)[pathlength - 1] == '\n')
		(*pathname)[pathlength - 1] = '\0';
}

