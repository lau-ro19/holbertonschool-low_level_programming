#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j = 0;

	/* 1. Copie src vers dest jusqu'à n ou jusqu'à la fin de src */
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}

	/* 2. Si on a atteint la fin de src mais pas encore n, */
	/* on remplit le reste de dest avec des '\0' */
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
