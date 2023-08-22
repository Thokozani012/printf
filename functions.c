#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * count_digits - Counstthe number of digits in an number
 * @n: Number to be checked
 *
 * Return: On success, the number of digits in n
 */

int count_digits(int n)
{
	int count = 0;
	int is_negative = 0;

	if (n == 0)
	{
		count = 1;
	}
	else if (n == INT_MIN)
	{
		count = 10;
	}
	else if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	while (n > 0)
	{
		count++;
		n /= 10;
	}

	if (is_negative)
	{
		count++;
	}

	return (count);
}

/**
 * process_integer - Function prints and count no of char(s) printed
 * @num: Number to be printed
 * @buffer: Buffer variable for buffer_handling
 * @buffer_index: Counter of number of characters printed
 *
 * Return: Nothing (void function)
 */

void process_integer(int num, char *buffer, int *buffer_index)
{
	int is_negative = 0;
	int num_digits, divisor, digit, i;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	num_digits = count_digits(num);
	if (is_negative)
	{
		buffer[(*buffer_index)++] = '-';
	}

	while (num_digits > 0)
	{
		divisor = 1;
		for (i = 1; i < num_digits; i++)
		{
			divisor *= 10;
		}

		digit = num / divisor;
		buffer[(*buffer_index)++] = digit + '0';

		num %= divisor;
		num_digits--;
	}
}

/**
 * check_and_flush_buffer - checks and flushes a buffer if necessary
 * @buffer: buffer to be checked and checked
 * @buffer_index: counter of the number of characters flushed and initialized
 *
 * Return: Nothing (void function)
 */

void check_and_flush_buffer(char *buffer, int *buffer_index)
{
	if (*buffer_index >= BUFFER_SIZE)
	{
		write(1, buffer, *buffer_index);
		*buffer_index = 0;
	}
}

/**
 * flush_remaining_buffer - Flushes the remaining buffer
 * @buffer: Buffer to be flushed
 * @buffer_index: Character counter to be adjusted accordingly
 *
 * Return: Nothing (void function)
 */

void flush_remaining_buffer(char *buffer, int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, buffer, *buffer_index);
	}
}
