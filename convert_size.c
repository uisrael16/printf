#include "main.h"

/**
 * convert_size - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return:result
 */

char *convert_size(unsigned long int num, int base, int lower_case)
{
    static char rep_lower[] = "0123456789abcdef";
    static char rep_upper[] = "0123456789ABCDEF";

    char *rep = (lower_case) ? rep_lower : rep_upper;
    if (num == 0) {
        char *result = (char *)malloc(2);
        if (result == NULL)
	{
            return NULL;
        }
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    unsigned long int temp = num;
    size_t length = 0;
    while (temp > 0) {
        temp /= base;
        length++;
    }

    char *result = (char *)malloc(length + 1);
    if (result == NULL)
    {
        return NULL;
    }

    char *ptr = result + length;
    *ptr = '\0';

    do {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return result;
}

