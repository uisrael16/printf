#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{   
    char *buffer;
    unsigned int length;
    unsigned int ibuf; 
    va_list arguments;
    size_t buffer_size;
     unsigned int i;
    if (!format)
    {
        return -1;
    }

   
    va_start(arguments, format);

    
    buffer_size = 1024;
    buffer = malloc(sizeof(char) * buffer_size);

    if (!buffer)
    {
        va_end(arguments);
        return -1;
    }

    length = 0;
    ibuf = 0;

    for (i = 0; format[i]; i++)
    {

        buffer[ibuf++] = format[i];

        if (ibuf >= buffer_size - 1)
        {
            print_buf(buffer, ibuf);
            ibuf = 0;
        }
    }

    print_buf(buffer, ibuf);

    free(buffer);

    va_end(arguments);

    return length;
}

