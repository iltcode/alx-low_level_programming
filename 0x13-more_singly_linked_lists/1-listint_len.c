#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{

size_t nm;

if (h == NULL)
{
printf("Is empty");
}

for (nm = 0; h ; nm++)
{
h = h->next;
}


return (nm);
}
