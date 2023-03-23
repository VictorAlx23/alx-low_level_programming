#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - Returns the sum of two numbera
 * @a: The first member
 * @b: The second member
 *
 * Return: The sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Returns the diffrence of two numbera
 * @a: The first member
 * @b: The second member
 *
 * Return: The diffrence of a and b
 */
int op_sub(int a, int b)
{
        return (a - b);
}
/**
 * op_mul - Returns the product of two numbera
 * @a: The first member
 * @b: The second member
 *
 * Return: The product of a and b
 */
int op_mul(int a, int b)
{       
        return (a * b);
}
/**
 * op_div - Returns the division of two numbera
 * @a: The first member
 * @b: The second member
 *
 * Return: The quotient of a and b
 */
int op_div(int a, int b)
{       
        return (a / b);
}
/**
 * op_mod - Returns the remainder of two numbera
 * @a: The first member
 * @b: The second member
 *
 * Return: The Remainder of a and b
 */
int op_mod(int a, int b)
{       
        return (a % b);
}
