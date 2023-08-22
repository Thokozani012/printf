#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_string - Prints and counts the characters of a string
 * @args: argument string to be printed and counted
 * @counter: Counts the number of char of the string printed
 *
 * Return: Nothing (void function)
 */

void handle_string(va_list args, int *counter)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(NULL)";
	while (*str)
	{
		*counter += _putchar(*str);
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
	int counter = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (; *format; ++format)
	{
		if (*format != '%')
		{
			counter += _putchar(*format);
		}
		else
		{
			++format;
			if (*format == '\0')
				break;
			if (*format == ' ')
				return (-1);
			if (*format == 's')
			{
				handle_string(args, &counter);
			}
			else if (*format == 'c')
			{
				counter += _putchar(va_arg(args, int));
			}
			else
			{
				if (*format != '%')
					counter += _putchar('%');
				counter += _putchar(*format);
			}
		}
	}
	va_end(args);
	return (counter);
}
