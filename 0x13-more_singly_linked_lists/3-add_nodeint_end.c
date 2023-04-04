#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *tail;
	listint_t *p = *head;

	tail = malloc(sizeof(listint_t));
	if (!tail)
		return (NULL);

	tail->n = n;
	tail->next = NULL;


	while (p->next)
		p = p->next;

	p->next = tail;

	return (tail);
}
