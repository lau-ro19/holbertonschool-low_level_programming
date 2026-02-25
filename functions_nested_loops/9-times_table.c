include "main.h"

/**
 * times_table - Affiche la table de multiplication de 9
 *
 * Description: Formatage avec virgules et espaces pour aligner
 * les chiffres correctement.
 */

void times_table(void)
{
	int row, col, prod;

	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			prod = row * col;

			if (col == 0)
			{
				_putchar(prod + '0');
			}
			else if (prod <= 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(prod + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				_putchar((prod / 10) + '0');
				_putchar((prod % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
