#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_string - Prints and counts the characters of a string
 * @args: argument string to be printed and counted
 * @buffer: buffer allocation
 * @buffer_index: Counts the number of char of the string printed
 *
 * Return: Nothing (void function)
 */

void handle_string(va_list args, char *buffer, int *buffer_index)
{
	const char *str;

	str = va_arg(args, const char *);
	if (str == NULL)
		str = "(NULL)";
	while (*str)
	{
		buffer[(*buffer_index)++] = *str;
		str++;
	}
}

/**
 * _printf - Printf function replica
 * @format: Format arguments
 *
 * Return: Number of characters printed to the stdout
 */

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (; *format; ++format)
	{
		if (*format != '%')
		{
			buffer[buffer_index++] = *format;
		}
		else
		{
			++format;
			if (*format == '\0' || *format == ' ')
			{
				va_end(args);
				return (-1);
			}
			if (*format == 's')
			{
				handle_string(args, buffer, &buffer_index);
			}
			else if (*format == 'c')
			{
				buffer[buffer_index++] = va_arg(args, int);
			}
			else if (*format == 'd' || *format == 'i')
			{
				process_integer(va_arg(args, int), buffer, &buffer_index);
			}
			else
			{
				if (*format != '%')
					buffer[buffer_index++] = '%';
				buffer[buffer_index++] = *format;
			}
		}
		check_and_flush_buffer(buffer, &buffer_index);
	}
	flush_remaining_buffer(buffer, &buffer_index);
	va_end(args);
	return (buffer_index);
}
