#include "main.h"
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */


/**
 * _printf - custom printf function
 * @format: format string
 * Return: length of the formatted output
 */



int	_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
	{
            format++;
            switch (*format)
	    {
                case 'c':
			{
                    char c = va_arg(args, int);
                    _putchar(c);
                    count++;
                    break;
                }
                case 's': 
			{
                    char *str = va_arg(args, char *);
                    while (*str) {
                        _putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case 'd': {
                    int num = va_arg(args, int);
                    
                    char buffer[20];
                    int i = 0;
                    if (num < 0)
		    {
                        _putchar('-');
                        count++;
                        num = -num;
                    }
                    while (num != 0)
		    {
                        buffer[i++] = num % 10 + '0';
                        num /= 10;
                    }
                    if (i == 0)
		    {
                        _putchar('0');
                        count++;
                    }
		    else
		    {
                        while (--i >= 0) {
                            _putchar(buffer[i]);
                            count++;
                        }
                    }
                    break;
                }
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
            }
        }
	else
	{
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}

