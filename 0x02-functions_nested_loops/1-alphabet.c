#include "main.h"
/**
 * print_alphabet - print out a-z
 *
 */
void print_alphabet(void)
{
char ch = 'a';
while (ch <= 'z')
{
_putchar(ch);
ch++;
}
_putchar('\n');
return;
}
