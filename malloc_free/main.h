#ifndef MAIN_H
#define MAIN_H

/**
 * File: main.h
 * Desc: Header file containing prototypes for all functions
 * used in the 0x0a-malloc_free directory.
 */

/* 0. create_array */
char *create_array(unsigned int size, char c);

/* 1. _strdup */
char *_strdup(char *str);

/* 2. str_concat */
char *str_concat(char *s1, char *s2);

/* 3. alloc_grid */
int **alloc_grid(int width, int height);

/* 4. free_grid */
void free_grid(int **grid, int height);

#endif /* MAIN_H */
