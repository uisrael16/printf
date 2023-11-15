#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>
#define BUFF_SIZE 1024
#define MAX_BUFFER_SIZE 50
#define NULL_STRING "(null)"
#define ROT13_ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ROT13_CIPHER   "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"



/**
 * struct format - converter for printf
 * @ph: type char pointer of the specifier
 * @function: function for the conversion specifier
 *
 */

typedef struct {
    char c;
    int (*f)(va_list, flags_t*);
} print_handler;

typedef struct {

} flags_t;

int get_addrss(va_list list, flags_t *f);
int _special_char(va_list list, flags_t *f, int (*output_fn)(char));
int _print(va_list list, flags_t *f);
int _rev(va_list list, flags_t *f);
int get_str(va_list list, flags_t *f);
int print_char(va_list list, flags_t *f);
int _puts(char *str);
int print_rot13(va_list list, flags_t *f);
int print_rot13(va_list list, flags_t *f);
int _percent(va_list list, flags_t *f);
int (*printter(char s))(va_list, flags_t*);
char *convert_size(unsigned long int num, int base, int lower_case);
int flags(char s, flags_t *f);
int print_hexadecimal(va_list list, flags_t *f);
int print_oct(va_list list, flags_t *f);
int print_h2(va_list list, flags_t *f);
int custom_itoa(unsigned int value, char *buffer, int base);
int print_binary(va_list list, flags_t *f);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
