#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line
 * @size: The size of the triangle
 *
 * Return: void
 */

void print_triangle(int size)
{
	int row, column;

	if (size > 0)
	{
		for (row = 1; row <= size; row++)
		{
			for (column = 0; column < (size - row); column++)
			{
				_putchar(' ');
			}
			for (column = 0; column < row; column++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
