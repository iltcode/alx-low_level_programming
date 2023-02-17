#include <stdio.h>

/**
 * main - print out 0-9
 *
 * Return: 0
 */
int main(void)
{
int ch = 48;
while (ch <= 57)
{
	putchar(ch);
	ch++;
}
putchar('\n');
return (0);
}
