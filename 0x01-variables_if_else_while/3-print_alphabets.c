#include <stdio.h>

/**
 * main - print out a-z and A-Z
 *
 * Return: 0
 */
int main(void)
{
char ch = 'a';
char chz = 'A';
while (ch <= 'z')
{
	putchar(ch);
	ch++;
}
while (chz <= 'Z')
{
	putchar(chz);
	chz++;
}
putchar('\n');
return (0);
}
