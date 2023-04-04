#include  "list.h"
/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: head of a list
 * @idx:the index of the list where new node should be added
 * @n:element
 *
 * Return:The address of the new node of NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *j = *head;

	if (idx != 0)
	{
		for (i = 0; i < idx - 1 && j != NULL i++)
		{
			j = j->next;
		}
	}

	if (j == NULL && idx != 0)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = j->next;
		j->next = new;
	}
	return (new);
}
