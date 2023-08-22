#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

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
	char *str;

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
			if (*format == '\0' || *format == ' ')
			{
				va_end(args);
				return (-1);
			}
			if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
				{
					str = "NULL";
					counter = counter + 1;
				}
				while (*str)
				{
					counter += _putchar(*str);
					str++;
				}
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
	_putchar('\n');
}
