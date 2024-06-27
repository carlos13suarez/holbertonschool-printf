#include "main.h"

/**
 * print_string - prints a string
 *
 * @argument: the string to print
 * @buffer: pointer to string
 * @position: where we'll start to add the chars in buffer from argument
 */
void print_string(va_list argument, char *buffer, int *position)
{
	int i = 0;
	char *str = va_arg(argument, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*position] = str[i];
		(*position)++;
	}
}
