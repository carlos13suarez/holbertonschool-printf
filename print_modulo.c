#include "main.h"

/**
 * print_modulo - prints a modulo
 *
 * @argument: the character modulo to print
 * @buffer: pointer to string
 * @position: where we'll start to add the chars in buffer from argument
 */
void print_modulo(__attribute__ ((unused)) va_list argument, char *buffer, unsigned int *position)
{
	buffer[*position] = '%';
	(*position)++;
}
