#include <stdio.h>
/**
 * _strlen - it counts the length of a string
 * @str: the string to get the length
 * Return: the length of @str.
 */
int _strlen(char *str)
{
int c = 0;

while (str[c] != '\0')
{
c++;
}
return (c);
}
