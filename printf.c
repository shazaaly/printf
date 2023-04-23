#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * print_normal - prints a character to stdout
 * @format: format string to print
 *
 * Return: 1
 */
int print_normal(const char *format)
{
write(STDOUT_FILENO, format, 1);
return (1);
}






/**
 * print_char - prints a character to stdout
 * @args: arguments list
 *
 * Return: 1
 */
int print_char(va_list args)
{
char c = (char)va_arg(args, int);
write(STDOUT_FILENO, &c, 1);
return (1);
}




/**
 * print_string - prints a string to stdout
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
char *s = va_arg(args, char *);
size_t len = strlen(s);
write(STDOUT_FILENO, s, len);
return (len);
}





/**
 * print_percent - prints a percent symbol to stdout
 *
 * Return: 1
 */
int print_percent(void)
{
write(STDOUT_FILENO, "%", 1);
return (1);
}





/**
 *_printf - function that produces output according to a format
 *@format: string containing zero or more format specifiers
 *Return: number of characters printed
 */


int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int count = 0;
while (*format)
{
if (*format != '%')
{
count += print_normal(format);
}
else
{
switch (*++format)
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
count += print_percent();
break;
default;
break;
}
format++;
}
}
va_end(args);
return (count);
}
