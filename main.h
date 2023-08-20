#ifndef _MAIN_H
#define _MAIN_H

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
void handle_string(va_list args, int *counter);
void handle_percent(va_list args, int *counter);
void handle_default(va_list args, int *counter, char c);
int _printf(const char *format, ...);

#endif /*_MAIN_H*/
