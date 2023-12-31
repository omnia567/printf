#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, p = 0, p_ch = 0;
	int f, w, precn, s, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			p_ch++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			f = get_f(format, &i);
			w = get_w(format, &i, list);
			precn = get_precn(format, &i, list);
			s = get_s(format, &i);
			++i;
			p = H_print(format, &i, list, buffer,
				f, w, precn, s);
			if (p == -1)
				return (-1);
			p_ch += p;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (p_ch);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
