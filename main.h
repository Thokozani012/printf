#ifndef _MAIN_H
#define _MAIN_H

#define BUFFER_SIZE 1024

#include <stdarg.h>

/**
 * struct handle - Structure containing the function pointer
 * @type: First memeber
 * @handler: function pointer
 *
 * Description: Contains the function pointer to handle function
 */
typedef struct handle
{
	char type;
	void (*handler)(va_list args, int *counter);
} FormatHandler;

int _putchar(char c);
void handle_char(va_list args, int *counter);
void handle_string(va_list args, char *buffer, int *buffer_index);
void handle_percent(va_list args, int *counter);
void handle_default(va_list args, int *counter, char c);
int count_digits(int n);
void process_integer(int num, char *buffer, int *buffer_index);
void check_and_flush_buffer(char *buffer, int *buffer_index);
void flush_remaining_buffer(char *buffer, int *buffer_index);
int _printf(const char *format, ...);

#endif /*_MAIN_H*/
