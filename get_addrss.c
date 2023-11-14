#include "main.h"

/**
 *  * @list: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 */


int get_addrss(va_list list, flags_t *f)
{
    unsigned long int p;
    char *str;
    int index = 0;
    p = va_arg(list, unsigned long int);

    if (p == 0)
        return _puts("(nil)");

    *str = convert(p, 16, 1);


    index += _puts("0x");
    index += _puts(str);

    free(str);

    return index;
}

