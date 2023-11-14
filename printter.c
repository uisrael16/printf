#include "main.h"

/**
 *  The conversion specifier is stored in the variable s. 
 *  The function iterates through an array of structs called array_func[] 
 *  to find a match between the specifier passed to _printf and the first element of each struct. 
 *  Once a match is found, the corresponding printing function is identified.
 * The function ultimately returns a pointer to the matched printing function.
 */

int (*printter(char s))(va_list, flags_t*)
{
    print_handler print_handlers[] = {
        {'i', print_int},
        {'s', print_string},
        {'c', print_char},
        {'d', print_int},
        {'u', print_unsigned},
        {'x', print_hexa},
        {'X', print_hexa_2},
        {'b', print_binary},
        {'o', print_octal},
        {'R', print_rot13},
        {'r', print_rev},
        {'S', print_2},
        {'p', print_address},
        {'%', print_percent}
    };

    size_t num_handlers = sizeof(print_handlers) / sizeof(print_handlers[0]);

    for (size_t i = 0; i < num_handlers; ++i)
    {
        if (print_handlers[i].c == s)
        {
            return print_handlers[i].f;
        }
    }

    return NULL;
}
