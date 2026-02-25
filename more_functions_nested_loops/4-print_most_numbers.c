#include "main.h"

/**
 * print_most_numbers: Write a function that prints some numbers.
 *
 * Description: prints the numbers, from 0 to 9 and 4 followed by a new line but do not print 2 . 
 * You can only use _putchar twice.
 */

void print_most_numbers(void);
{
	char num;

	for (num = '1'; num <= '9'; num++)
	{
		if (num != '2' && num != '4')
		{
			_putchar(num);
		}
	}
	_putchar('\n');

	return (0);
}