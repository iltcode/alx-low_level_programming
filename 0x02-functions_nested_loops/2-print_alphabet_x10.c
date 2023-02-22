#include "main.h"
/**
 * print_alphabet_x10 - prints alphbet ten times
 *
 */
void print_alphabet_x10(void)
{
int x = 0;

for (x = 0; x < 10; x++)
{
char ch = 'a';
while (ch <= 'z')
{
_putchar(ch);
ch++;
}
_putchar('\n');
}
return;
}
