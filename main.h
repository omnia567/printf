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
 * struct ft - Struct op
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
 * typedef struct ft ft_t - Struct op
 *
 * @ft: The format.
 * @f_t: The function associated.
 */
typedef struct ft ft_t;

int _printf(const char *format, ...);
int H_print(const char *ft, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings ,precent */
int print_c(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_s(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_per(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers int and binary and octal , unsigned, hexdeciaml,hexupperer,hex */
int print_i(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_b(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_o(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexaD(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexaUpper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_Hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non print char */
int print_non_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print store address */
int print_PTR(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to Handles  */
int get_f(const char *format, int *i);
int get_w(const char *format, int *i, va_list list);
int get_precn(const char *format, int *i, va_list list);
int get_s(const char *format, int *i);

/*Function to print STR in reverse*/
int print_reve(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a STR in rot 13*/
int print_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print W0idthHandler */
int handleWriteC(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_numb(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_PTR(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** print utls ******************/
int is_print(char);
int appendHexaCode(char, char[], int);
int isDigit(char);

long int convert_s_numb(long int num, int size);
long int convert_s_unsnd(unsigned long int num, int size);

#endif /* MAIN_H */

