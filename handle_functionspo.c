#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointr - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */
int print_pointr(va_list types, char buffer[],
	int f, int w, int precn, int s)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(w);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precn);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (f & F_PLUS)
		extra_c = '+', length++;
	else if (f & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		w, f, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable (va_list types, char buffer[],
	int f, int w, int precn, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(precn);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reve - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */

int print_reve(va_list types, char buffer[],
	int f, int w, int precn, int s)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precn);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13str - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @precn: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13str(va_list types, char buffer[],
	int f, int w, int precn, int s)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(f);
	UNUSED(w);
	UNUSED(precn);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
