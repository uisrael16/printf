#include "main.h"

/**
 *  @list: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 */

int get_str(va_list list, flags_t *f)
{
    const char *str = va_arg(list, const char *);

    if (str == NULL) {
        str = "(null)";
    }

    return _puts(str);
}
