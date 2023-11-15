#include "main.h"

/**
 * get_f - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: F:
 */
int get_f(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int f = 0;
	const char F_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; F_CH[j] != '\0'; j++)
			if (format[curr_i] == F_CH[j])
			{
				f |= F_ARR[j];
				break;
			}

		if (F_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (f);
}
