#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_format - parses and prints a format string
 * @format: the format string to print
 * @args: the list of arguments to print
 *
 * Return: the number of characters printed
 */
int print_format(const char *format, va_list args)
{
	int i, j, k, count;
	var_t type[] = {
		{"c", c_func}, {"s", s_func}, {"i", i_func}, {"%", perc_func},
		{"d", d_func},	{"b", b_func},	{"r", rev_func}, {"R", rot_func},
		{NULL, NULL},
	};

	i = 0, count = 0, k = 0;
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format && format[i])
	{
		if (format[i] != '%')
			_putchar(format[i]), k++;
		else
		{
			j = 0;
			while (type[j].vartype)
			{
				if (format[i + 1] == *type[j].vartype)
				{
					count += (type[j].f)(args), i++;
					break;
				}
				j++;
			}
			if (type[j].vartype == NULL)
				count += 1, _putchar('%');
		}
		i++;
	}
	k += count;
	return (k);
}

/**
 * _printf - function that produces output according to a format
 * @format: type of argument passed to function
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int k;

	va_start(args, format);
	k = print_format(format, args);
	va_end(args);

	return (k);
}

