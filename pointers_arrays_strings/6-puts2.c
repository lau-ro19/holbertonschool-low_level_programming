#include "main.h"

/**
 * puts2 - prints every other character of a string
 * starting with the first character, followed by a new line
 * @str: the string to be treated
 *
 * Return: nothing
 */
void puts2(char *str)
{
	int i = 0;
	int len = 0;

	/* 1. Calculer la longueur totale pour ne pas dépasser */
	while (str[len] != '\0')
	{
		len++;
	}

	/* 2. Parcourir avec un pas de 2 (i += 2) */
	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}