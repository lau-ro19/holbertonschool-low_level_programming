#include "hash_tables.h"

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	/* Magic constant 5381 is the starting point */
	hash = 5381;

	/* Iterate through each character of the string */
	while ((c = *str++))
	{
		/* hash * 33 + c */
		/* (hash << 5) shifts hash by 5 bits (multiply by 32) */
		hash = ((hash << 5) + hash) + c;
	}

	return (hash);
}
