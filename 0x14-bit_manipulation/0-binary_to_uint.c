#include "main.h"

/**
* binary_to_uint - convert a binary number to an unsigned int
* @b: char string
* Return: converted decimal number or 0 if there is an unconvertable char
*/

unsigned int binary_to_uint(const char *b)
{
int x;
int len = strlen(b);
unsigned int sum = 0;
int val = 1;

if (b == NULL)
{

return (0);
}

for (x = (len - 1); x >= 0 ; x--)
{
if (b[x] == '1')
{
sum = sum + val;

}

if (b[x] != '0' && b[x] != '1')
{

return (0);
}

}

val = val * 2;

}

return (sum);
}
