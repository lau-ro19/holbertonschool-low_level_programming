#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - Creates a self-contained session object
 * @id: String ID
 * @uid: User ID
 * @data: Initial data buffer
 * @data_len: Length of initial data
 *
 * Return: Pointer to new session, or NULL on failure
 */
session_t *session_create(const char *id, unsigned int uid,
			  const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id)
		return (NULL);

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);

	s->id = strdup(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;
	s->data = NULL;
	s->data_len = 0;

	if (data && data_len > 0)
	{
		s->data = malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}
		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}

	return (s);
}

/**
 * session_set_data - Robustly updates session data with safe resizing
 * @s: Pointer to session
 * @data: New data to copy
 * @data_len: Length of new data (0 to clear)
 *
 * Return: 1 on success, 0 on failure
 */
int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *tmp;

	if (!s)
		return (0);

	/* Scenario 1: Clear data (data_len is 0) */
	if (data_len == 0)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	/* Scenario 2: Resize/Update data */
	/* 1. Attempt realloc into a temporary pointer */
	tmp = realloc(s->data, data_len);
	if (!tmp)
	{
		/* Failure: Original s->data and s->data_len are preserved */
		return (0);
	}

	/* 2. Update successful: Re-assign pointer and metadata */
	s->data = tmp;
	if (data)
		memcpy(s->data, data, data_len);
	s->size = data_len; /* Only update after successful realloc */

	return (1);
}

/**
 * session_destroy - Safely cleans up session memory
 * @s: Session to destroy
 */
void session_destroy(session_t *s)
{
	if (!s)
		return;

	free(s->id);
	free(s->data);
	free(s);
}
