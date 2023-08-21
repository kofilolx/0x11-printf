#include "main.h"
#include <stdio.h>
/**
 * _printf - custom printf function
 * prints different format specifiers
 * format: contains the format specifiers
 * Return: returns an output to the stdout
 */
int _printf(const char *format, ...)
{
	va_list specifiers;
	int characters;
	/* variable declarations done*/
	characters = 0;
	if (format == NULL)
		return (-1);
	/*returns an error*/
	va_start(specifiers, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			characters++;
			/*writes the strings as characters to the output
			 * eg. if format is the boy and not %...
			 * the output becomes the boy
			 * printing each character and incrementing
			 */
		}
		else
		{
			/**if format begins with a %
			 * we handle the specifiers
			 * we check the next character after the %
			 */
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(specifiers, int);
						write(1, &c, 1);
						characters++;
						break;
					}
				case 's':
					{
						char *s = va_arg(specifiers, char *);
						write(1, s, strlen(s));
						characters += strlen(s);
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						characters++;
						break;
					}
				case 'd':
					{
						int d = va_arg(specifiers, int);
						char buffer[1024];
						/*buffer holds the int as a str*/
						int len = snprintf(buffer, sizeof(buffer), "%d", d);
						/*snprintf is a function that prints the int to a
					 	* string buffer*/
						write(1, buffer, len);
						characters += len;
						break;
					}
				case 'i':
					{
						int i = va_arg(specifiers, int);
						char buffer_i[1024];
						int len_i = snprintf(buffer_i, sizeof(buffer_i), "%i", i);
						characters += len_i;
						break;
					}
				default:
					break;
			}
		}
		format++;
	}
	va_end(specifiers);
	return (characters);
}
