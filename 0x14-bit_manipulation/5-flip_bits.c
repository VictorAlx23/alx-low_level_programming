#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip to
 * get from one number to another
 * @n: the first number
 * @m: the second number
 * Return: the number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flips = n ^ m;
	unsigned int counts = 0;

	while (flips > 0)
	{
		counts += flips & 1;
		flips >>= 1;
	}
	return (counts);
}
