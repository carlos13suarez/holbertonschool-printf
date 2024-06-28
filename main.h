#ifndef _MAIN_H_
#define _MAIN_H_

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>


/* Macros */


/* Structures */
/**
 * struct argument_structure - elements of a argument_structure object
 *
 * @name: the format to be choose
 * @printer: function pointer that prints the given arguments
 */
typedef struct argument_structure
{
	char conversion_specifier;
	void (*printer)(va_list args, char *buffer, unsigned int *position);
} argument_structure;


/* Prototypes */
unsigned int _printf(const char *format, ...);
void print_char(va_list argument, char *buffer, unsigned int *position);
void print_string(va_list argument, char *buffer, unsigned int *position);
void print_modulo(va_list argument, char *buffer, unsigned int *position);


#endif
