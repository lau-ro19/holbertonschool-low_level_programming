#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: the size of the array
 *
 * Return: pointer to the newly created hash table, or NULL if it fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	/* 1. Allocate the hash table structure */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	/* 2. Allocate the array of pointers (the buckets) */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht); /* Clean up previously allocated table if array fails */
		return (NULL);
	}

	/* 3. Initialize all pointers in the array to NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->size = size;

	return (ht);
