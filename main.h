#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fit - Struct op
 *
 * @ft: The format.
 * @f: The function associated.
 */
struct ft
{
	char ft;
	int (*f)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt ft_t - Struct op
 *
 * @ft: The format.
 * @f_t: The function associated.
 */

typedef struct ft ft_t;

int _printf(const char *format, ...);
int handle_print(const char *ft, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print characters and strings */
int print_c(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_s(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* Functions to print numbers int ,binary,unsigned,octal,hexadecimal,upper */
int print_i(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_b(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsd(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_o(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexaD(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexaU(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_non_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_f(const char *format, int *i);
int get_w(const char *format, int *i, va_list list);
int get_p(const char *format, int *i, va_list list);
int get_s(const char *format, int *i);

int print_revs(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int handle_write_chr(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_numb(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_n(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_p(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsnd(int is_negative, int ind,
	char buffer[],int flags, int width, int precision, int size);

int is_print(char);
int append_HX_code(char, char[], int);
int is_DT(char);

long int convert_sz_numb(long int num, int size);
long int convert_sz_unsnd(unsigned long int num, int size);

#endif
