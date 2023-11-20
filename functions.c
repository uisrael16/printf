#include "main.h"

/*
 * convertToBaseString - Converts a number to a string representation in the specified base.
 * @number: The input number to be converted.
 * @base: The base to convert the number to.
 * @useLowerCaseHex: A flag indicating whether hex values should be in lowercase.
 *
 * Return: A dynamically allocated string representing the converted number in the specified base.
 */

char *convertToBaseString(unsigned long int number, int base, int useLowerCaseHex)
{
    char *rep = useLowerCaseHex ? "0123456789abcdef" : "0123456789ABCDEF";
    char *buffer;
	int i;
	int j;

	buffer = (char *)malloc(MAX_BUFFER_SIZE);
    
    if (buffer == NULL) {
        return NULL;
    }

    i = MAX_BUFFER_SIZE - 1;
    
    if (number == 0) {
        buffer[i--] = '0';
    } else {
        while (number > 0 && i >= 0) {
            buffer[i--] = rep[number % base];
            number /= base;
        }
    }
   
    for (j = i + 1; j < MAX_BUFFER_SIZE; j++) {
        buffer[j - i - 1] = buffer[j];
    }

    return buffer;
}

int get_digit(int number)
{
    int count = 0;

    while (number != 0) {
        number /= 10;
        count++;
    }

    return count;

    return count;
}
/*
*Function to print an integer with optional flags
*Handle the space flag
*Handle the plus flag
*Make n positive for printing
*Handle zero case
*Print the number
*/

int print_int(va_list list, flags_t *f)
{
    int n = va_arg(list, int);
    int res = get_digit(n);

    if (f->space && !f->plus && n >= 0)
    {
        res += _putchar(' ');
    }

    if (f->plus && n >= 0) {
        res += _putchar('+');
    } else if (n < 0) {
        res += _putchar('-');
        n = -n;
    }

    if (n == 0) {
        res += _putchar('0');
    } else {
        
        print_num(n);
    }

    return res;
}
/*
*The argument_checker function is a utility function designed 
*to check the type of a format specifier character and return a corresponding function pointer. 
*This function is part of a larger program or library that deals with formatted string printing, 
*where different format specifiers are associated with specific printing functions.
*/

int (*argument_checker(char s))(va_list, flags_t *)
{
	size_t i;
    print_handler array_func[] = {
        {'c', get_char},
		{'i', print_int},
        {'s', get_string},
		{'d', print_int},
		{'u', get_uns},
		{'x', get_hexadecimal},
		{'b', get_binary},
		{'R', rot13},
		{'r', rev_print},
		{'S', ASCII_print},
		{'X', get_hexadecimal_},
		{'p', get_addrss},
		{'o', get_oct},
		{'%', percent},
    };
    
    for (i = 0; i < sizeof(array_func) / sizeof(array_func[0]); ++i) {
        if (array_func[i].c == s) {
            return array_func[i].f;
        }
    }
    
    return NULL;
}

int get_uns(va_list list, flags_t *f)
{
	unsigned int u = va_arg(list, unsigned int);
	char *str = convertToBaseString(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_num - helper function that loops through
 * an integer and prints all its digits
 * @num: integer to be printed
 */
void print_num(int num)
{

	int INT_MIN = 0;
    
    if (num < 0) {
        _putchar('-');
       
        if (num == INT_MIN) {
           
            _putchar('2');
            num = -(num / 10);
        } else {
            num = -num;
        }
    }

    
    if (num / 10 != 0) {
        print_num(num / 10);
    }

    
    _putchar('0' + num % 10);
}

