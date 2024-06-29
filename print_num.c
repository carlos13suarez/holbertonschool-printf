#include "main.h"

/**
 * print_num - prints a number
 *
 * @argument: the number to print
 * @buffer: pointer to string
 * @position: where we'll start to add the numbers in buffer from argument
 */
void print_num(va_list argument, char *buffer, unsigned int *position)
{
	int i, length = 0, decimal_accesser = 1, dn, n1 = 0,
	    n2 = 0, num = (int) va_arg(argument, int);

	if (num < 0)
	{
		dn = num * -1;
		buffer[*position] = '-';
		(*position)++;
	}
	else
		dn = num;

	n2 = dn;

	if (n2 > 0)
	{
		while (dn != 0)
		{
			dn = dn / 10;
			length++;
		}
	}
	else
		length = 1;

	for (i = 0; i < (length - 1); i++)
		decimal_accesser *= 10;

	for (i = 0; i <= (length - 1); i++)
	{
		n1 = n2 / decimal_accesser;
		buffer[*position] = ((n1 % 10) + 48);
		(*position)++;
		decimal_accesser /= 10;
	}
}
