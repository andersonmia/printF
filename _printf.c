#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: a character string that specifies the format
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				format++;
				len++;
			}
			else if (*format == 'c')
			{
				char c = (char)va_arg(args, int);
				_putchar(c);
				format++;
				len++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);
				len += _puts(s);
				format++;
			}
			else
			{
				_putchar(*format);
				format++;
				len++;
			}
		}
		else
		{
			_putchar(*format);
			format++;
			len++;
		}
	}

	va_end(args);

	return (len);
}
