#include "main.h"

/**
 * print_address - prints address of input in hexa format
 * Extract the address from the va_list
 * Counter to keep track of the number of characters printed
 * Check if the address is NULL
 * Convert the address to a hexadecimal string
 * Free the allocated memory for the string
 * Return the total count of characters printed
 */

int	get_addrss(va_list list, flags_t *f)
{
    unsigned long int address = va_arg(list, unsigned long int);
	char *address_str;
    int count = 0;
	(void)f;
	
    if (address == 0)
    {
        return _puts("(nil)");
    }

    address_str = convertToBaseString(address, 16, 1);
    count += _puts("0x");
    count += _puts(address_str);

    free(address_str);
    return (count);
}

/**
 * This function takes a character 's' representing a flag and a pointer to a
 * flags_t structure 'f' where the flag will be set. The supported flags are:
 *   - '+' (plus)
 *   - ' ' (space)
 *   - '#' (hash)
 *
 * @param s The input character representing a flag ('+', ' ', or '#').
 * @param f A pointer to a flags_t structure where the flag will be set.
 * @return Returns 1 if the flag was recognized and set successfully, 0 otherwise.
 */

int	flags(char s, flags_t *f)
{
    switch (s) {
        case '+': f->plus = 1; return 1;
        case ' ': f->space = 1; return 1;
        case '#': f->hash = 1; return 1;
        default: return 0;
    }
}
