#include "main.h"

/*
 * the condition str[0] != '0' is replaced with num != 0. 
 * This change ensures that the '0x' prefix is added 
 * only if the original unsigned integer value is not zero.
 *  Additionally, you can now easily extend 
 *  the logic inside the if (f->hash == 1) block to handle 
 *  other cases related to the hash flag if needed
 */

int print_hexadecimal(va_list list, flags_t *f)
{
	unsigned int num = va_arg(list, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	if (f->hash == 1) {
		if (num != 0) {
			count += _puts("0x");
		}
	} else
	{
		count += _puts(str);
	}
	return count;

}

  /*
  * Handle the minimum width if specified
  *handle the hash flag
  *Print the octal number
  */
int print_oct(va_list list, flags_t *f)
{
    unsigned int num = va_arg(list, unsigned int);
    char *str = convert(num, 8, 0);
    int count = 0;

    // Handle the minimum width if specified
    if (f->width > 0) {
        int padding = f->width - strlen(str);
        while (padding-- > 0) {
            count += _putchar(f->zero_padding ? '0' : ' ');
        }
    }

    // Handle the hash flag
    if (f->hash == 1 && (str[0] != '0' || f->precision == 0))
    {
        count += _putchar('0');
    }

    count += _puts(str);

    return count;
}

/**
 * Function to print a number in binary format
 * @list: variable arguments list
 * @f: flags
 * Return: number of characters printed
 */
int print_binary(va_list list, flags_t *f)
{
    unsigned int num = va_arg(list, unsigned int);
    char binary[32];
    int index = 0;
    int count = 0;

    if (num == 0)
    {
        _putchar('0');
        return 1;
    }

    while (num > 0)
    {
        binary[index++] = (num % 2) + '0';
        num /= 2;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        _putchar(binary[i]);
        count++;
    }

    return count;
}

/*
 * Reverse the string
 */

int custom_itoa(unsigned int value, char *buffer, int base)
{
    if (value == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return 1;
    }

    int i = 0;
    while (value != 0) {
        int rem = value % base;
        buffer[i++] = (rem < 10) ? rem + '0' : rem + 'A' - 10;
        value = value / base;
    }

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    buffer[i] = '\0';
    return i;
}

/*
 *Retrieve the argument from va_list
 *Determine the maximum length of the hexadecimal string
 *Allocate memory for the buffer
 *Handle memory allocation error
 *Return the number of characters printed
 */

int print_h2(va_list list, flags_t *f)
{

    unsigned int value = va_arg(list, unsigned int);
    int max_length = 20;
    char *buffer = (char *)malloc(max_length);

    if (buffer == NULL)
    {
        return -1;
    }

    int length = custom_itoa(value, buffer, 16);

    for (int i = 0; i < length; i++) {
        putchar(buffer[i]);
    }
    free(buffer);
    return length;
}

