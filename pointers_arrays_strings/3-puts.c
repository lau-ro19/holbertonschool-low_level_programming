#include "main.h"

/**
 * _puts - imprime une chaîne de caractères suivie d'un saut de ligne
 * @str: pointeur vers la chaîne à imprimer
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
