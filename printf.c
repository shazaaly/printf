#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int print_unsign(unsigned int n, int base, const char *digits);

/**
 * _putchar - write a character to stdout
 * @c: the character to write
 *
 * Return: 1 on success, or -1 on error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _printf - print formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int len = 0;
const char *p = format;
va_start(args, format);

while (*p != '\0')
{
if (*p == '%')
{
switch (*(++p))
{
case 'c':
len += _putchar(va_arg(args, int));
break;
case 's': {
const char *str = va_arg(args, const char *);
while (*str != '\0')
{
len += _putchar(*str++);
}
break;
}
case '%':
len += _putchar('%');
break;
case 'd':
case 'i': {
int num = va_arg(args, int);
if (num < 0)
{
len += _putchar('-');
num = -num;
}
len += print_unsign(num, 10, "0123456789");
break;
}
case 'u':
len += print_unsign(va_arg(args, unsigned int), 10, "0123456789");
break;
case 'o':
len += print_unsign(va_arg(args, unsigned int), 8, "01234567");
break;
case 'x':
len += print_unsign(va_arg(args, unsigned int), 16, "0123456789abcdef");
break;
case 'X':
len += print_unsign(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
break;
case 'p': {
void *ptr = va_arg(args, void *);
len += _putchar('0');
len += _putchar('x');
len += print_unsign((unsigned long)ptr, 16, "0123456789abcdef");
break;
}
default:
len += _putchar('%');
len += _putchar(*p);
break;
}
}
else
{
len += _putchar(*p);
}
p++;
}
va_end(args);
return (len);
}

/**
 * print_unsign - print an unsigned integer in a specified base
 * @n: the number to print
 * @base: the base to use (e.g. 10 for decimal, 16 for hexadecimal, etc.)
 * @digits: the string of digits to use for the base (e.g. "0123456789abcdef")
 *
 * Return: the number of characters printed
 */
int print_unsign(unsigned int n, int base, const char *digits)
{
int len = 0;

if (n / base > 0)
{
len += print_unsign(n / base, base, digits);
}
len += _putchar(digits[n % base]);
return (len);
}
