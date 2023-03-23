#include "function_pointers.h"

/**
 * prinr_name - prints name using pointers to function
 * @name: string to add
 * @f: pointer to function
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
