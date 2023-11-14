#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appendHexaCode‎ - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int appendHexaCode‎(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * isDigit‎ - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int isDigit‎(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_s_numb‎ - Casts a number to the specified size
 * @num: Number to be casted.
 * @s: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_s_numb‎(long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_s_unsnd‎ - Casts a number to the specified size
 * @num: Number to be casted
 * @s: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_s_unsnd‎(unsigned long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
