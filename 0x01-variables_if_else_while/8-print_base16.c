#include <stdio.h>

/**
 * main - print out a-z and A-Z
 *
 * Return: 0
 */
int main(void)
{
char ch = 'a';
int num = 48;
while (num < 57)
{
	putchar(num);
	num++;
}
while (ch <= 'f')
{
	putchar(ch);
	ch++;
}
putchar('\n');
return (0);
}
