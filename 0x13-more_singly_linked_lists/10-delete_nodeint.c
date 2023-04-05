#include "lists.h"

/**
* get_nodeint_at_index - returns the node at a certain index in a linked list
* @head: first node in the linked list
* @index: index of the node to return
*
* Return: pointer to the node we're looking for, or NULL
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *del = *head;
listint_t *p = *head;
unsigned int len = 1;

if (*head == NULL)
{
return (-1);
}

if (index == 0)
{
*head = del->next;
free(del);
del = NULL;
return (1);
}

while (index != len)
{
	if (del->next == NULL)
		return (-1);
	p = del;
	del = del->next;
	len++;
}

p->next = del->next;
free(del);
del = NULL;
return (1);

}
