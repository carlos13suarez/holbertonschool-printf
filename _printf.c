#include "main.h"

void print_char(va_list argument, char *buffer, int *position);
void print_string(va_list argument, char *buffer, int *position);
/**
 * _printf - custom version of printf
 *
 * @format: string to be printed. Contains format specifiers.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list arguments_to_print;
	int size = 0, i = 0, j = 0;
	int *ptr_size = &size;
	char buffer[1024] = "";
	argument_structure valid_format[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(arguments_to_print, format);

	while (format && format[i] != '\0')
	{
		j = 0;
		if (format[i] != '%')
		{
			buffer[size] = format[i];
			size++;
		}
		else if (format[i + 1] != '\0')
		{
			while (valid_format[j].conversion_specifier != '\0')
			{
				if (format[i + 1] == valid_format[j].conversion_specifier)
				{
					valid_format[j].printer(arguments_to_print, buffer, ptr_size);
					size++;
					i++;
					break;
				}
				j++;
			}
		}
		else
		{
			buffer[size] = format[i];
			size++;
		}
		i++;
	}
	va_end(arguments_to_print);
	write(1, buffer, size);
	return (size);
}


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
}



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
		return;

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*position] = str[i];
		(*position)++;
	}
}
