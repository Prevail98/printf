#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function that produces output according to a format
 * @format: type of argument passed to function
 *
 * Return: k, number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        printed_chars++;
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    char buffer[12];
                    sprintf(buffer, "%d", num);
                    printf("%s", buffer);
                    printed_chars += strlen(buffer);
                    break;
                }
                case '%': {
                    putchar('%');
                    printed_chars++;
                    break;
                }
                default: {
                    break;
                }
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}
