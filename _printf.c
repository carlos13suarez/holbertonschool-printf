#include "main.h"

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
