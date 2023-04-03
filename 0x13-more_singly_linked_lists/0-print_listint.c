#include "lists.h"

size_t print_listint(const listint_t *h)
{

size_t nm;

if (h == NULL)
{
printf("Is empty");
}

for (nm = 0; h ; nm++)
{
printf("%d ", h->n);
h = h->next;
}


return (nm);
}
