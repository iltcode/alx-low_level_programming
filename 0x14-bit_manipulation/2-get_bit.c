#include "main.h"

/**
 * get_bit - value of a bit at a given index
 * @n: decimal parameter
 * @index: index
 * Return: val
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);


	bit = n >> index;

	return (bit & 1);
}
