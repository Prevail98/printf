#include <stdarg.h>
#include <stdio.h>

/**
 * print_c - Prints a character to stdout.
 * @args: The arguments passed to the function.
 * @count: The number of characters printed.
 *
 * Return: The updated count.
 */
int print_c(va_list args, int count)
{
	char c;

	c = va_arg(args, int);
	putchar(c);
	count++;

	return (count);
}

/**
 * print_s - Prints a string to stdout.
 * @args: The arguments passed to the function.
 * @count: The number of characters printed.
 *
 * Return: The updated count.
 */
int print_s(va_list args, int count)
{
	const char *s;

	for (s = va_arg(args, const char *); *s; s++)
	{
		putchar(*s);
		count++;
	}

	return (count);
}

/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
			case 'c':
				count = print_c(args, count);
				break;
			case 's':
				count = print_s(args, count);
				break;
			case '%':
				putchar('%');
				count++;
				break;
			default:
				putchar('%');
				putchar(format[i]);
				count += 2;
				break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count);
}

