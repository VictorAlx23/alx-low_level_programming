#include "variadic_functions.h"
/**
 * sum_them_all - Returns the summ of all its parameters
 * @n: The number of parameters passes to the function
 * @...: A variable number of parameters to calculate the sum of
 *
 * Return: 0, if n == 0
 * 	Otherwise - the sum of all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum = 0;
	va_list ap;
	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(ap, int);
	}
	va_end (ap);
	return (sum);
}
