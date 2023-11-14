#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */
int print_unsned(va_list types, char buffer[],
	int f, int w, int precn, int s)
{
	int i = BUFF_SIZE - 2;
	unsned long int num = va_arg(types, unsned long int);

	num = convert_s_unsnd(num, s);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsnd(0, i, buffer, f, w, precn, s));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_o - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_o(va_list types, char buffer[],
	int f, int w, int precn, int s)
{

	int i = BUFF_SIZE - 2;
	unsned long int num = va_arg(types, unsned long int);
	unsned long int init_num = num;

	UNUSED(w);

	num = convert_s_unsnd(num, s);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsnd(0, i, buffer, f, w, precn, s));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexaD - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_hexaD(va_list types, char buffer[],
	int f, int w, int precn, int s)
{
	return (print_Hex(types, "0123456789abcdef", buffer,
		f, 'x', w, precn, s));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexaUpper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_hexaUpper(va_list types, char buffer[],
	int f, int w, int precn, int s)
{
	return (print_Hex(types, "0123456789ABCDEF", buffer,
		f, 'X', w, precn, s));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_Hex - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @f_ch: Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * @s: Size specification
 * Return: Number of chars printed
 */
int print_Hex(va_list types, char map_to[], char buffer[],
	int f, char f_ch, int w, int precn, int s)
{
	int i = BUFF_SIZE - 2;
	unsned long int num = va_arg(types, unsned long int);
	unsned long int init_num = num;

	UNUSED(w);

	num = convert_s_unsnd(num, s);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		buffer[i--] = f_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsnd(0, i, buffer, f, w, precn, s));
}
