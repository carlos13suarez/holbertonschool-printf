#include "main.h"

/**
 * print_char - prints a char
 *
 * @argument: the character to print
 * @buffer: pointer to string
 * @position: where we'll start to add the chars in buffer from argument
 */
void print_char(va_list argument, char *buffer, int *position)
{
	char c = (char) va_arg(argument, int);

	buffer[*position] = c;
	(*position)++;
}
