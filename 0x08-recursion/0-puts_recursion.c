#include "main.h"
/**
 * _puts_recursion - a function that prints a string followed by a new line
 *
 * @s: string to be printed
 *
 * Return: printed string
 */

void _puts_recursion(char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        _putchar(s[i]);
        i++;
    }
    _putchar('\n');
}

