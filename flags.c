#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: updated:
 */


int flags(char s, flags_t *f)
{
    int updated = 0;

    switch (s) {
        case '+':
            f->plus = 1;
            updated = 1;
            break;
        case ' ':
            f->space = 1;
            updated = 1;
            break;
        case '#':
            f->hash = 1;
            updated = 1;
            break;
       
        default:
            updated = 0;
            break;
    }

    return updated;
}

