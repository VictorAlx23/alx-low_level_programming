#include "main.h"

/**
 * palindrome - String length
 *
 * @s: char
 *
 * Return: the integer length
 */

int is_palindrome(char *s)
{
	if (*s)
	{
		s++;

		return (1 + is_palindrome(s));
	}
	return (0);
}

/**
 * helper_pal - Returns Palindrone
 *
 * @str: char
 *
 * @length: int
 *
 * @count: int
 *
 * Return: the integer length
 */

int helper_pal(char *str, int length, int count)
{
	if (count >= length)
	{
		return (1);
	}
	if (str[length] == str[count])
	{
		return (helper_pal(str, length - 1, count + 1));
	}
	return (0);
}
