#include "main.h"

/**
 * printting special char
 * return cout
 * */

int _special_char(va_list list, flags_t *f, int (*output_fn)(char))
{
    int i, count = 0;
    char *s = va_arg(list, char *);

    if (!s)
        return output_fn(NULL_STRING);

    for (i = 0; s[i]; i++)
    {
        if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
        {
            output_fn('\\');
            count += 2;
            char *res = convert(s[i], 16, 0);
            count += (res[1] ? _puts(res) : _putchar('0') + _puts(res));
        }
        else
        {
            count += output_fn(s[i]);
        }
    }
    return count;
}

/**
 * value in hexadecimal (upper case - always 2 characters)
 * @list: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
*/
int _print(va_list list, flags_t *f)
{
    return print_special_chars(list, f, _putchar);
}

/**
 * * @list: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 */

int _rev(va_list list, flags_t *f)
{
    int i = 0, count = 0;
    char *s = va_arg(list, char *);

    if (!s)
        s = NULL_STRING;

    while (s[i])
        i++;

    for (int j = i - 1; j >= 0; j--)
        count += _putchar(s[j]);

    return count;
}

/**
 * print_rot13 - prints a string using rot13
 * @list: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 */

int print_rot13(va_list list, flags_t *f)
{
    int count = 0;
    char *s = va_arg(list, char *);

    if (!s)
        return _puts(NULL_STRING);

    for (int j = 0; s[j]; j++)
    {
        if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
        {
            count += _putchar(s[j]);
        }
        else
        {
            for (int i = 0; i <= 52; i++)
            {
                if (s[j] == ROT13_ALPHABET[i])
                    count += _putchar(ROT13_CIPHER[i]);
            }
        }
    }
    return count;
}

/**
 * print_percent - prints a percent
 * @list: va_list arguments from _printf
 */

int _percent(va_list list, flags_t *f)
{
    (void)list;
    (void)f;
    return _putchar('%');
}
