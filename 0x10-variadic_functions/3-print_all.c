#include "variadic_functions.h"
/**
 * print_all - prints anything passed into it
 * format: lists the type of argument passed into the function
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *sep = "";

	va_list list;

	va_start(list, format);
	if(format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sep, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", sep, va_arg(list, int));
					break;
				case 's':
					if(!str)
						str = "(nil)";
					printf("%s%s", sep, va_arg(list, char*));
					break;
				case 'f':
					printf("%s%f", sep, va_arg(list, double));
					break;
				default:
					i++;
					continue;
			}
			sep = ", ";
			i++;
		}
	}
	printf("\n");
	va_end(list);
}
