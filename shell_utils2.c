#include "main.h"

/**
 * _puts - function that writes a string to stdout
 * @str: string to write
 *
 * Return: number of bytes written to stdout
 */
size_t _puts(char *str)
{
	if (str == NULL)
	{
		return (write(STDOUT_FILENO, "(null)", 6));
	}
	return (write(STDOUT_FILENO, str, strlen(str)));
}

