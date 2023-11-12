#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; 

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    fputs(va_arg(args, char*), stdout);
                    count += strlen(va_arg(args, char*));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else 
	{
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
