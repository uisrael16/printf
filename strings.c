#include "main.h"

/**
 * rev_print - prints a string in reverse
 * @list: argument from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */

int	rev_print(va_list list, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(list, char *);
	(void)f;

	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * rot13 - prints a string using rot13
 * @list: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */

int	rot13(va_list list, flags_t *f)
{
	char *s = va_arg(list, char *);
	char base;
	int  i;
	(void)f;

	if (s == NULL)
		return 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			base = (s[i] >= 'a') ? 'a' : 'A';
			_putchar((s[i] - base + 13) % 26 + base);
		}
		else
		{
			_putchar(s[i]);
		}
	}

	return (i);
}

/**
 * get_binary - prints a number in base 2
 * @list: va_list arguments from _printf
 * @f: pointer to the struct that determines
 * if a flag is passed to _printf
 * Description: the function calls convertToBaseString() which in turns convertToBaseStrings the input
 * number into the correct base and returns it as a string
 * Return: the number of char printed
 */

int	get_binary(va_list list, flags_t *f)
{
	unsigned int num = va_arg(list, unsigned int);
	int chars_printed = 0;
	char *binary_str;
	(void)f;
	binary_str = convertToBaseString(num, 2, 1);

	if (binary_str == NULL)
	{
		return (-1); 
	}


	while (*binary_str != '\0') {
		_putchar(*binary_str);
		chars_printed++;
		binary_str++;
	}

	free(binary_str);
	return (chars_printed);
}

/**
 * @brief Prints an unsigned integer in octal format with optional formatting.
 *
 * This function prints the octal representation of an unsigned integer,
 * with an optional leading '0' if the hash (#) flag is set and the number
 * is not zero.
 * @param list The variable argument list.
 * @param f Pointer to the flags structure for formatting options.
 * @return The number of characters printed.
 */

int	get_oct(va_list list, flags_t *f)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convertToBaseString(num, 8, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}

/**
 * get_string - loops through a string and prints
 * every character
 * @list: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */

int	get_string(va_list list, flags_t *f)
{
	char *s = va_arg(list, char *);

	(void)f;
	if (!s) {
		s = "(null)";
	}

	if (s)
	{
		return _puts(s);
	}
	else
	{

		return (-1);
	}
}

