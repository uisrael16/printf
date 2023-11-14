#include "main.h"

/**
 * * @list: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 */

int print_char(va_list list, flags_t *f)
{
    (void)f;

    char c = va_arg(list, int);
    _putchar(c);
    return 1;
}
