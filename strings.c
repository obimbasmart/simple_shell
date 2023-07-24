#include "main.h"
/**
 * _strncopy - copies content
 * @dest: where to copy the string
 * @origin: the origin of the string
 *
 * Return: the concatenated string
 */
char *_strncopy(char *dest, char *origin)
{
	int l = 0;
	int x = 0;

	while (*(origin + l) != '\0')
		l++;
	for ( ; x < l ; x++)
	{
		dest[x] = origin[x];
	}
	dest[l] = '\0';
	return (dest);
}
/**
 * _strncat - concatenates two strings
 * @dest: string to add to
 * @origin: string to add
 *
 * Return: concatenated string
 */
char *_strncat(char *dest, char *origin)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
		i++;
	j = 0;
	while (origin[j] != '\0')
	{
		dest[i] = origin[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - returns the string length
 * @str: the string to determine its length
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int l = 0;

	if (str == NULL)
		return (0);

	while (*str++)
		l++;

	return (l);
}

/**
 * _strcmp - performs comparison of two strangs.
 * @str1: first string
 * @str2: second string
 *
 * Return: -ve if str1 < str2, +ve if str1 > str2, 0 if str1 == str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);

	else
	{
		return (*str1 < *str2 ? -1 : 1);
	}
}
