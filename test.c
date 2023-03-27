#include "main.h"
void printstring (char *s)
{
	while (*s)
	{
		putchar(*s);
		s++;
	}
}
int _printf(const char *format, ...)
{
	int count = 0;
	int a;
	char *b;

	va_list args;
	va_start(args, format);
	while (*format)
	{
		count++;
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				a = va_arg(args, int);
				putchar(a);
				break;
			case 's':
				b = va_arg(args, char *);
				printstring(b);
				break;
			case '%':
				putchar('%');
				break;
			default:
				putchar(48);
				break;
			}
		}
		else
			putchar(*format);
		format++;
	}
	va_end(args);
	return 0;
}

int main(void)
{
	printf("mordecai %c %%", 'p');
	return 0;
}