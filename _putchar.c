#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 * Description: _putchar uses a local buffer of 1024 to call write
 * 
 */

int _putchar(char c)
{
    static char buf[BUFFER_SIZE];
    static int buffer_index = 0;

    if (buffer_index >= BUFFER_SIZE || c == -1)
    {
        write(1, buf, buffer_index);
        buffer_index = 0;

        if (c == -1)
        {
            return 0;
        }
    }
    buf[buffer_index++] = c;

    return 1;
}

