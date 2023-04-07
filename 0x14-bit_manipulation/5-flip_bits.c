#include "main.h"

/**
* flip_bits - number of bits you would need to flip
* to get from one number to another
* @n: parameter
* @m: number n will be changed to
* Return: number of bits to fliped
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int result, count = 0;
result = n ^ m;

while (result > 0)
{
count += (result & 1);
result >>= 1;
}

return (count);
}
