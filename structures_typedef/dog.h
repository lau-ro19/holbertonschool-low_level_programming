#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A new type describing a dog
 * @name: First member (char *)
 * @age: Second member (float)
 * @owner: Third member (char *)
 *
 * Description: Header file that defines a new type struct dog
 * and an alias dog_t.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Def du nouvel alias dog_t pour struct dog */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);

void print_dog(struct dog *d);

dog_t *new_dog(char *name, float age, char *owner);

#endif /* DOG_H */
