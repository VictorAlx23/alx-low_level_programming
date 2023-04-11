#include "main.h"
/**
 * get_bit - gets the value of a bit at a given index
 * @n: the number to get the bit from
 * @index: the index of the bit to get
 * Return: the value of the bit at index index, or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bits_value;

	if (index > 63)
		return (-1);
	bits_value = (n >> index) & 1;
	return (bits_value);
}
