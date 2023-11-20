#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>

#include <stdlib.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024
#define MAX_BUFFER_SIZE 50


struct Flags {
    
    int flag1;
    int flag2;
    
};

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;


typedef struct {
    int precision;
    int width;
    
} Flags;

typedef struct {
    char c;
    int (*f)(va_list, flags_t *f);
} print_handler;

typedef struct {
    char c;
    int (*f)(va_list ap, flags_t *f);
} print_han;

int	print_int(va_list list, flags_t *f);
void	print_num(int num);
int	get_uns(va_list list, flags_t *f);
int	get_digit(int num);
int	get_hexadecimal(va_list list, flags_t *f);
int	get_hexadecimal_(va_list list, flags_t *f);
int	get_binary(va_list list, flags_t *f);
int	get_oct(va_list list, flags_t *f);
char	*convertToBaseString(unsigned long int number, int base, int useLowerCaseHex);
int	_printf(const char *format, ...);
int	(*argument_checker(char s))(va_list, flags_t *);
int	flags(char s, flags_t *f);
int	get_string(va_list list, flags_t *f);
int	get_char(va_list list, flags_t *f);
int	_putchar(char c);
int	_puts(char *str);
int	rot13(va_list list, flags_t *f);
int	rev_print(va_list list, flags_t *f);
int	ASCII_print(va_list list, flags_t *f);
int	get_addrss(va_list list, flags_t *f);
int	percent(va_list list, flags_t *f);

#endif
