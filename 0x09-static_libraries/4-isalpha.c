#include "main.h"
/**
 * _isalpha - checks for alphabtic character
 * @c: the character to be checked
 * Return: 1 for correct or 0 for wrong
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
