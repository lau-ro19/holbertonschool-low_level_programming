#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to be reversed
 *
 * Return: nothing
 */
void rev_string(char *s)
{
	int len = 0;
	int i = 0;
	char temp;

	/* 1. Calculer la longueur de la chaîne */
	while (s[len] != '\0')
	{
		len++;
	}

	/* 2. Échanger les caractères jusqu'au milieu (len / 2) */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
