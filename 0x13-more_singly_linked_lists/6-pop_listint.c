#include "lists.h"
/**
 * pop_listint - deletes the head node of a linked list
 * @head: head of a list
 *
 * Return:the head nodes data (n) if empty return 0
 */
int pop_listint(listint_t **head)
{
	int prom;
	listint_t *i;
	listint_t *j;

	if (*head == NULL)
		return (0);

	j =  *head;

	prom = j->n;

	i = j->next;

	free(j);

	*head = i;

	return (prom);
}
