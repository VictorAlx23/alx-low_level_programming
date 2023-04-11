#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: The number to convert to binary
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int bits_masks = 1;
	unsigned int bits_counts = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while ((n >> bits_counts) > 0)
		bits_counts++;
	while (bits_counts > 0)
	{
		bits_counts--;
		if (n & (bits_masks << bits_counts))
			_putchar('1');
		else
			_putchar('0');
	}
}
