#include "main.h"

unsigned int valid_specifier(const char *format, argument_structure *valid_format,
		char *buffer, va_list arguments_to_print);
/**
 * _printf - custom version of printf
 *
 * @format: string to be printed. Contains format specifiers.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
unsigned int _printf(const char *format, ...)
{
	va_list arguments_to_print;
	unsigned int size = 0;
	char buffer[4086] = "";
	argument_structure valid_format[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_modulo},
		{'\0', NULL}
	};
	if (!format)
		return (0);
	va_start(arguments_to_print, format);

	size = valid_specifier(format, valid_format, buffer, arguments_to_print);
	
	va_end(arguments_to_print);
	write(1, buffer, size);
	return (size);
}



unsigned int valid_specifier(const char *format, argument_structure *valid_format,
		char *buffer, va_list arguments_to_print)
{
	unsigned int size = 0;
	int i = 0, j = 0;
	unsigned int *ptr_size = &size;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[size++] = format[i];
			continue;
		}
		for (j = 0; valid_format[j].conversion_specifier != '\0'; j++)
		{
			if (format[i + 1] == valid_format[j].conversion_specifier)
			{
				valid_format[j].printer(arguments_to_print, buffer, ptr_size);
				i++;
				break;
			}
		}
	}

	return (size);
}
