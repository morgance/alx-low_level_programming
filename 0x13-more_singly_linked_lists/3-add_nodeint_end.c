#include "lists.h"
/**
 * add_nodeint_end - adds a new node at the end of a list
 * @head: head of a list
 * @n: element
 *
 * Return:address of the new element, or NULL if it failed
 */
listint_t add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *prom;

	(void)prom;

	qew = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;

	new->next = NULL;

	prom = *head;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (prom->next != NULL)
		{
			prom = prom->next;
		}
		prom->next = new;
	}
	return (*head);
}
