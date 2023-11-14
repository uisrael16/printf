#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */

int _puts(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
        count++;
    }
    return count;
}
