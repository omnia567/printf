#include "main.h"

/**
 * get_precn - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precn(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precn = -1;

	if (format[curr_i] != '.')
		return (precn);

	precn = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(format[curr_i]))
		{
			precn *= 10;
			precn += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precn = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precn);
}
