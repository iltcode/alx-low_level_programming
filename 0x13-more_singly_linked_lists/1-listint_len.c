#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @h: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
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
