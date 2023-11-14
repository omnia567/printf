#include "main.h"
/**
 * H_print - Prints an argument based on its type
 * @ft: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @f: Calculates active flags
 * @w: get width.
 * @precn: Precision specification
 * @s: Size specifier
 * Return: 1 or 2;
 */
int H_print(const char *ft, int *ind, va_list list, char buffer[],
	int f, int w, int precn, int s)
{
	int i, unknow_len = 0, p_ch = -1;
	ft_t ft_types[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_per},
		{'i', print_i}, {'d', print_i}, {'b', print_b},
		{'u', print_unsned}, {'o', print_o}, {'x', ‎print_hexaD},
		{'X', print_hexaUpper}, {'p', print_PTR}, {'S', print_non_print‎},
		{'r', print_reve‎}, {'R', print_rot13str‎}

	};
	for (i = 0; ft_types[i].ft != '\0'; i++)
		if (ft[*ind] == ft_types[i].ft)
			return (ft_types[i].f(list, buffer, f, w, precn, s));

	if (ft_types[i].ft == '\0')
	{
		if (ft[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (ft[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (w)
		{
			--(*ind);
			while (ft[*ind] != ' ' && ft[*ind] != '%')
				--(*ind);
			if (ft[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &ft[*ind], 1);
		return (unknow_len);
	}
	return (p_ch);
}
