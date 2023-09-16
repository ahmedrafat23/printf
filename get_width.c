#include "main.h"
/**
 * get_width - a function that calculates the width for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char* format, int* i, va_list list)
{
	int current_i = *i + 1, width = 0;

	while (format[current_i] != '\0')
	{
		if (is_digit(format[current_i]))
		{
			width *= 10;
			width = width + format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
		current_i++;
	}
	*i = current_i - 1;

	return (width);
}
