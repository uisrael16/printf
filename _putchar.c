#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success, the number of characters written; On error, -1.
 * Description: _putchar uses a local buffer of 1024 to call write
 * as little as possible.
 */
int _putchar(char c)
{
    static char buf[BUFFER_SIZE];
    static int i;

    if (i >= BUFFER_SIZE || c == -1)
    {
        if (write(1, buf, i) != (int)i)
        {
            return (-1);
        }
        i = 0;
    }

    if (c != -1)
    {
        buf[i] = c;
        i++;
    }

    return (i); 
}
