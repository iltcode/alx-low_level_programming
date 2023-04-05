#include "lists.h"

/**
* insert_nodeint_at_index - inserts a new node in a linked list,
* at a given position
* @head: pointer to the first node in the list
* @idx: index where the new node is added
* @n: data to insert in the new node
*
* Return: pointer to the new node, or NULL
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int len = 1;
listint_t *new;
listint_t *p = *head;

new = malloc(sizeof(listint_t));
if (!new || !*head)
return (NULL);

new->n = n;
new->next = NULL;


while (p != NULL)
{
if (idx == 0)
{
new->next = *head;
*head = new;
return (new);
}
else if (len == idx)
{
	new->next = p->next;
	p->next = new;
	return (new);
}
	len++;
	p = p->next;
}

return (NULL);
}
