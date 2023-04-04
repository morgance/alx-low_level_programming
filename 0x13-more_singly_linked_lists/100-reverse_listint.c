#include "lists.h"
/**
 * reverse_listint - reverses a list
 * @head:head of a list
 *
 * Return:a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t i;
	listint_t n;

	i = NULL;
	n = NULL;

	while (*head != Null)
	{
		n = (*head)->next;
		(*head)->next = i;
		i = *head;
		*head = n;
	}

	*head = i;
	return (*head);
}
