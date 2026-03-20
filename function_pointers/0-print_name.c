#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - Prints a name using a given function.
 * @name: The name to be printed.
 * @f: A pointer to a function that takes a char pointer as an argument
 * and returns nothing (void).
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	/* Sécurité : on vérifie que les pointeurs ne sont pas NULL */
	if (name == NULL || f == NULL)
		return;

	/* On appelle la fonction pointée par 'f' en lui passant 'name' */
	f(name);
}
