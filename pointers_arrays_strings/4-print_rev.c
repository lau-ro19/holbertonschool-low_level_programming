#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: the string to be printed
 *
 * Return: nothing
 */
void print_rev(char *s)
{
	int len = 0;
	int i;

	/* 1. Trouver la longueur de la chaîne */
	while (s[len] != '\0')
	{
		len++;
	}

	/* 2. Imprimer en partant de la fin (len - 1) jusqu'à 0 */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	_putchar('\n');
}
