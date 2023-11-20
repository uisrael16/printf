#include "main.h"

/**
 * percent - prints a percent sign
 * @list: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: number of characters printed
 */

int	percent(va_list list, flags_t *f)
{
    (void)list;  
    if (f == NULL)
        return (0); 

    return _putchar('%');
}

/**
 * print_char - prints a character
 * @list: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */

int	get_char(va_list list, flags_t *f)
{
	(void)f;
	_putchar(va_arg(list, int));
	return (1);
}

int	ASCII_print(va_list list, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(list, char *);
	(void)f;

	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convertToBaseString(s[i], 16, 1);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}


/**
 * get_hexadecimal - prints a number in hexadecimal base,
 * in lowercase
 * @list: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convertToBaseString() which in turns convertToBaseStrings the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */

int	get_hexadecimal(va_list list, flags_t *f)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convertToBaseString(num, 16, 1);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * print_hexadecimal_ - prints a number in hexadecimal base,
 * in uppercase
 * @list: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: the function calls convertToBaseString() which in turns convertToBaseStrings the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */

int	get_hexadecimal_(va_list list, flags_t *f)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convertToBaseString(num, 16, 0);
		int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}

