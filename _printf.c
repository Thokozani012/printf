#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_char - Prints characters
 * @args: variable argument
 * @counter: counts the number of char printed
 *
 * Return: Nothing (void function)
 */
void handle_char(va_list args, int *counter)
{
	counter += _putchar(va_arg(args, int));
}

/**
 * handle_string - Prints strings
 * @args: variable arg
 * @counter: counts the no of char printed
 *
 * Return: Nothing (void function)
 */
void handle_string(va_list args, int *counter)
{
	char *str;

	str = va_arg(args, char *);
	while (*str)
	{
		*counter += _putchar(*str);
		str++;
	}
}

/**
 * handle_percent - Prints a percentage sign
 * @args: variadic arg
 * @counter: counts the number of charaters printed
 *
 * Return: Nothing (void function)
 */
void handle_percent(va_list args, int  *counter)
{
	(void) args;
	*counter += _putchar('%');
}

/**
 * handle_default - Prints a default character if none of speciefies match
 * @args: variable argument
 * @counter: counts the number of characters printed
 * @c: Character to be printed
 *
 * Return: Nothing (void function)
 */
void handle_default(va_list args, int *counter, char c)
{
	(void) args;
	*counter += _putchar(c);
}

/**
 * _printf - Printf function replica
 * @format: Format argument(s)
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, num_handlers, found_handler, counter = 0;
	FormatHandler handlers[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'%', handle_percent}
	};
	va_start(args, format);

	num_handlers = sizeof(handlers) / sizeof(handlers[0]);
	if (!format)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			found_handler = 0;
			for (j = 0; j < num_handlers; j++)
			{
				if (format[i] == handlers[j].type)
				{
					handlers[j].handler(args, &counter);
					found_handler = 1;
					break;
				}
			}
			if (!found_handler)
			{
				handle_default(args, &counter, format[i]);
			}
		}
		else
		{
			counter += _putchar(format[i]);
		}
	}
	va_end(args);
	return (counter);
}
