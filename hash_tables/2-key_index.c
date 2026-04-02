#include "hash_tables.h"

/**
 * key_index - gives you the index of a key
 * @key: the key (string) to hash
 * @size: the size of the array of the hash table
 *
 * Return: the index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	/* 1. Generate the large hash number using djb2 */
	hash_value = hash_djb2(key);

	/* 2. Use modulo to fit the hash into the array size */
	return (hash_value % size);
}
