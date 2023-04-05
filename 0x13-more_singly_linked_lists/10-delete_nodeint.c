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
	listint_t *newh;
        listint_t *p = *head;
        unsigned int len = 0;

        while (p != NULL)
        {
                if (len == index)
                {
			newh = (*head)->next;
			free(*head);
			*head = newh;
                        return (1);
                }

                len++;

                p = p->next;
        }

        return (-1);
}
